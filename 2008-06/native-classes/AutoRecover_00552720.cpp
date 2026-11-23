// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: opaque G3D::ReferenceCountedPointer<Texture>; layout is one pointer.
struct TexPtr { void* p; };
struct TexOwner { char pad[0x2c]; TexPtr tex; };

extern "C" TexPtr* __fastcall fn_004f0820(TexPtr* self, int unusedEdx, const TexPtr* src);

// Returns a copy of the texture pointer at +0x2c through a hidden return slot.
extern "C" TexPtr* __fastcall fn_00552720(TexOwner* self, int unusedEdx, TexPtr* out)
{
    fn_004f0820(out, 0, &self->tex);
    return out;
}
