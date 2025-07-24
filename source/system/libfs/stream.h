#ifndef __ZOE3_STREAM_H__
#define __ZOE3_STREAM_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef void FS_STREAM;

typedef struct {
    int type;   /* +0x00 */
    int size;   /* +0x04 */
    int time;   /* +0x08 */
    int option; /* +0x0c */
} STREAM_TAG;

#ifdef __cplusplus
}
#endif
#endif // {{{ END OF FILE }}}
