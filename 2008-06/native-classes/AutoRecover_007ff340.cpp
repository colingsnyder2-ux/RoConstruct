// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: layout modeled locally; the real classes live in Reflection headers.
namespace RBX {
class TextureId {};
namespace Reflection {
struct DescriptorBase {
    int a;
    int b;
    int c;
    int d;
    int e;
    DescriptorBase() : a(0), b(0), c(0), d(0), e(0) {}
    virtual ~DescriptorBase() {}
};

template<class T, int N>
struct BoundProp : DescriptorBase {
    char* owned;
    BoundProp() : owned(0) {}
    ~BoundProp() { delete owned; }
};
}

class Sky {
public:
    static Reflection::BoundProp<TextureId, 1> prop_SkyRt;
};

Reflection::BoundProp<TextureId, 1> Sky::prop_SkyRt;
}
