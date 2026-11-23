// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" int __fastcall fn_00540ed0(void* self, int unusedEdx, int a1);

namespace Wml {
template <class Real> class ConvexHull2 {
public:
    struct SortedVertex {
        bool operator!=(const SortedVertex& rhs) const;
    };
};

// INFERRED: operator!= is !(*this == rhs); fn_00540ed0 is operator==.
template <>
bool ConvexHull2<float>::SortedVertex::operator!=(const SortedVertex& rhs) const
{
    return !(fn_00540ed0((void*)this, 0, (int)&rhs) & 0xFF);
}
}
