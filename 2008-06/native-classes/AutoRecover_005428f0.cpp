// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the disassembly pushes no stack arguments, so the helper is declared
// with no extra arguments, which differs from the inferred 2-arg signature. It is
// probably the default constructor of a Vector2<float> member.
extern "C" int __fastcall fn_005445d0(void* self, int unusedEdx);

namespace Wml {

template <class Real>
class ConvexHull2 {
public:
    class SortedVertex {
    public:
        SortedVertex();
        // INFERRED: member layout (point plus index); only the first member is initialised by the helper.
        Real m_afTuple[2];
        int m_iIndex;
    };
};

template <class Real>
ConvexHull2<Real>::SortedVertex::SortedVertex()
{
    fn_005445d0(this, 0);
}

template ConvexHull2<float>::SortedVertex::SortedVertex();

} // namespace Wml
