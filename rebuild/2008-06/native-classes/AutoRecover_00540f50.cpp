// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

extern "C" Iter* __fastcall fn_00542710(Iter* self, int unusedEdx);

namespace Wml {
template <class Real> class ConvexHull2 {
public:
    struct SortedVertex {
        SortedVertex();
    };
};

// INFERRED: disassembly shows ctor only forwards to func_00542710 with no stack args; the
// original frame (push ebp / push ecx) suggests a non-/O2 inline-expanded base ctor.
template <>
ConvexHull2<float>::SortedVertex::SortedVertex()
{
    fn_00542710(this, 0, 0, 0);
}
}
