// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class header was provided, so a minimal G3D::Array<T> declaration is used.
// It exists only so the call mangles to ?resize@?$Array@PBX@G3D@@QAEXH@Z.
// The real definition lives elsewhere in the binary.
namespace G3D {
    template <class T>
    class Array {
    public:
        void resize(int n);
    private:
        // INFERRED: layout is irrelevant here; the function only forwards to resize(0).
        int m_dummy;
    };
}

// INFERRED: the function is unnamed, so it is exported under the fn_<addr> convention.
// It behaves like Array<const void*>::clear(), i.e. resize(0).
extern "C" void __fastcall fn_005527d0(G3D::Array<const void*>* self, int unusedEdx)
{
    self->resize(0);
}
