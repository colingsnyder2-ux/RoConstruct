// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the G3D header path is not shown, so only the minimal declaration needed to
// produce the mangled call ?resize@?$Array@PBX@G3D@@QAEXH@Z is given here.
namespace G3D {
    template<class T>
    class Array {
    public:
        void resize(int n);
    };
}

// INFERRED: the target takes `this` as a G3D::Array<const void*> and clears it by resizing to 0.
extern "C" void __fastcall fn_00552810(G3D::Array<const void*>* self, int unusedEdx)
{
    self->resize(0);
}
