// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
void __cdecl logf(int level, const char *fmt, ...);
extern unsigned char g_level;
struct Buf { char pad0[0x2c]; unsigned int size3D; char pad1[0x50]; unsigned int size3DTexture; };
struct Dev { char pad[0x4c]; Buf *buf; };
struct S {
    char pad[0x10];
    Dev *dev;
    void f();
};
void S::f()
{
    if (g_level)
        logf(g_level, "Post-Submit. Size of buffers, 3D: %u, 3DTexture: %u", dev->buf->size3D, dev->buf->size3DTexture, 0);
}