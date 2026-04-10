#include "game.h"
#include "common.h"
#include "../system/libgcl/libgcl.h"

extern int GM_TrapCommand(); /* in trap.c */

static int LoadCmd(char *top);
static int CharaCmd(char *top);
static int CommandCmd(char *top);
static int RestartCmd(char *top);
static int MesgCmd(char *top);
static int PreseekCmd(char *top);

/*---------------------------------------------------------------------------*/

static GCL_COMMANDLIST Commands[] = {
    { 0x0037c884, LoadCmd        }, // GV_StrCode("load")
    { 0x008b3df5, PreseekCmd     }, // GV_StrCode("preseek")
    { 0x00082bc9, CommandCmd     }, // GV_StrCode("command")
    { 0x006592a7, CharaCmd       }, // GV_StrCode("chara")
    { 0x003822c7, MesgCmd        }, // GV_StrCode("mesg")
    { 0x006bb005, RestartCmd     }, // GV_StrCode("restart")
    { 0x003bd490, GM_TrapCommand }  // GV_StrCode("trap")
};

static GCL_COMMANDDEF script_commands = {
    NULL,               // next
    countof(Commands),  // n_commlist
    Commands            // commlist
};

int GM_InitScript( void )
{
    return GCL_AddCommMulti( &script_commands );
}
