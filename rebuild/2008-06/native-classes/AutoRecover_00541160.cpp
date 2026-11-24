// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the disassembly pushes no stack arguments before the call, so the
// callee is declared with zero stack args here, unlike the 2-arg prototype in
// the task text. It is probably the default constructor of a member (e.g. a
// vertex or point sub-object).
extern "C" int __fastcall fn_00542930(void* self, int unusedEdx);

namespace Wml {

// INFERRED: no class header was available, so this is a minimal layout.
template <class Real>
class ConvexHull2 {
public:
    class SortedVertex {
    public:
        SortedVertex();
        // INFERRED: members are unknown; the constructor only forwards to fn_00542930.
        Real m_afData[3];
    };
};

template <>
ConvexHull2<float>::SortedVertex::SortedVertex()
{
    fn_00542930(this, 0);
}

} // namespace Wml
