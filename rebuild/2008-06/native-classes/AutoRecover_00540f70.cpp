// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: unknown class; self+4 holds a G3D::Texture*, result is a ReferenceCountedPointer<Texture> built in the caller-supplied slot (ret 4).
// Disassembly shows a frame-local flag [ebp-4] set to 0 then |= 1 (unwind/temp-construct flag), no other use.
struct Texture;
struct RcpTexture { Texture* p; };
struct Holder { int pad; Texture* tex; };

extern "C" RcpTexture* __fastcall fn_004e6030(RcpTexture* self, int unusedEdx, Texture* t);

extern "C" RcpTexture* __fastcall fn_00540f70(Holder* self, int unusedEdx, RcpTexture* out)
{
    int flags = 0;
    fn_004e6030(out, 0, self->tex);
    flags |= 1;
    (void)flags;
    return out;
}
