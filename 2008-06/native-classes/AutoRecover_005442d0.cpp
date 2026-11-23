// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this looks like std::allocator<ConvexClipper<float>::Face>::destroy(Face*),
// a thiscall member that forwards its one argument to std::_Destroy.
// The allocator class is unknown, so `self` is typed as void*.

namespace Wml {
    template <class Real>
    class ConvexClipper {
    public:
        class Face;
    };
}

namespace std {
    // Implemented elsewhere (0x005460c0).
    template <class T>
    void _Destroy(T* p);
}

typedef Wml::ConvexClipper<float>::Face ClipperFace;

extern "C" void __fastcall fn_005442d0(void* self, int unusedEdx, ClipperFace* p)
{
    std::_Destroy(p);
}
