// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class header was provided, so this minimal ConvexHull2 template
// is declared locally to produce the right mangled name. The members of
// SortedVertex are guesses, and the body forwards to fn_00544500 and returns
// its result as a bool.

extern "C" bool __fastcall fn_00544500(void* self, int unusedEdx, int a1);

namespace Wml {

template <class Real>
class ConvexHull2 {
public:
    class SortedVertex {
    public:
        // INFERRED: layout of the members is a guess (a 2D point plus an index)
        Real x, y;
        int  index;

        bool operator==(const SortedVertex& rkV) const;
    };
};

template <>
bool ConvexHull2<float>::SortedVertex::operator==(const SortedVertex& rkV) const
{
    return fn_00544500(const_cast<SortedVertex*>(this), 0, (int)&rkV);
}

} // namespace Wml
