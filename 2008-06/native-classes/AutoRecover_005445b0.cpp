// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: SortedVertex ctor forwards to a 2-arg member helper; args are not set by the caller (ecx only, unused stack args).
extern "C" void __fastcall fn_005458a0(TreeIter* self, int unusedEdx);

namespace Wml {
template <class Real> class ConvexHull2 {
public:
    struct SortedVertex {
        SortedVertex();
    };
};

template <>
ConvexHull2<float>::SortedVertex::SortedVertex()
{
    fn_005458a0(this, 0, 0, 0);
}
}
