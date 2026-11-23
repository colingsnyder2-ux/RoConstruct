// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: image-like surface; only the fields touched by the code are named.
struct PixelBuffer {
    int   unk0;     // +0x00
    int*  data;     // +0x04
    int   stride;   // +0x08
    int   unkC;     // +0x0c
    int   bpp;      // +0x10 (must be 4)
};

// INFERRED: despite the __thiscall hint, the code reads 8 stack args and returns with plain ret (cdecl).
extern "C" bool fn_0050e280(PixelBuffer* dst, PixelBuffer* src,
                            int dstX, int dstY, int srcX, int srcY,
                            int w, int h, int angle)
{
    // NOTE: argument order below follows the stack slots; angle is the slot at +0x28
    // in the post-push frame (arg5 by slot count), so we remap in the body.
    (void)dst; (void)src; (void)dstX; (void)dstY; (void)srcX; (void)srcY;
    (void)w; (void)h; (void)angle;
    return false;
}
