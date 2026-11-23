// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no headers were available, so the callee declarations below are
// local and written to produce the same mangled names as the originals.
namespace Wml {
    template <class Real>
    class ConvexHull3 {
    public:
        int GetType() const;
    };
}

namespace G3D {
    int iClamp(int val, int low, int hi);
}

// INFERRED: the owning class is unknown; the sub-object at +0xc is used as the hull.
struct FnObj_0054aca0 {
    char pad[0xc];
    Wml::ConvexHull3<float> hull;
};

extern "C" int __fastcall fn_0054aca0(FnObj_0054aca0* self, int unusedEdx, double x)
{
    // clamp((int)(GetType() * x), 0, GetType() - 1)
    int hi = self->hull.GetType() - 1;
    int n = self->hull.GetType();
    int v = (int)((double)n * x);
    return G3D::iClamp(v, 0, hi);
}
