// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class header was provided, so a minimal local declaration of
// Wml::ConvexHull2<float>::SortedVertex stands in for it. The real layout is
// unknown. The callee at 0x5446d0 carries the same mangled name as the target
// in the disassembly comment; it is probably a member sub-object constructor
// (for example Vector2<float>), so it is declared as a plain extern "C" helper.

extern "C" void __fastcall fn_005446d0(void* self, int unusedEdx);

namespace Wml {

template <class Real>
class ConvexHull2;

template <>
class ConvexHull2<float>
{
public:
    class SortedVertex
    {
    public:
        SortedVertex();

        // INFERRED: member layout
        float m_fPoint[2];
        int   m_iIndex;
    };
};

ConvexHull2<float>::SortedVertex::SortedVertex()
{
    fn_005446d0(this, 0);
}

} // namespace Wml
