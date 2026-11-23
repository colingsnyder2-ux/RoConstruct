// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: local minimal class declaration; real Wml header not available.
namespace Wml {
template <class Real> class ConvexHull2 {
public:
    class SortedVertex {
    public:
        SortedVertex();
    };
};
}

extern "C" void __fastcall fn_005445b0(void* self, int unusedEdx);

template <>
Wml::ConvexHull2<float>::SortedVertex::SortedVertex()
{
    fn_005445b0(this, 0);
}
