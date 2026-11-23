// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the callee at 0x5428f0 carries the same mangled name as the target, so
// it cannot be declared as a second SortedVertex constructor. It is declared here
// as a C-linkage __fastcall helper, as the fixed naming convention requires.
extern "C" void __fastcall fn_005428f0(void* self, int unusedEdx);

namespace Wml {

template <class Real>
class ConvexHull2 {
public:
    // INFERRED: member layout is unknown, so only a placeholder is declared.
    class SortedVertex {
    public:
        SortedVertex();
        Real mData[3];
    };
};

template <class Real>
ConvexHull2<Real>::SortedVertex::SortedVertex()
{
    fn_005428f0(this, 0);
}

template class ConvexHull2<float>::SortedVertex;

}
