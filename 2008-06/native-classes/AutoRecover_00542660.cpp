// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: SortedVertex ctor calls base/member ctor fn_005443c0 with 2 stack args; the disassembly shows none pushed, so the callee is declared with unused args.
extern "C" void __fastcall fn_005443c0(TreeIter* self, int unusedEdx);

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
    fn_005443c0(this, 0, 0, 0);
}
}
