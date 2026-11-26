// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
    extern bool assertsEnabled;
    extern bool assertsFatal;
    extern bool (*assertHook)(const char* expr, const char* file, int line);
    void assertionFailed(bool fatal, const char* message);
}
#define RBXASSERT(expr) \
    if (RBX::assertsEnabled && !(expr)) { \
        if (!RBX::assertHook || !RBX::assertHook(#expr, "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\include\\V8World/Geometry.h", 53)) \
            RBX::assertionFailed(RBX::assertsFatal, #expr " file: C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\include\\V8World/Geometry.h line: 53"); \
    }
namespace RBX {
struct Geometry {
    void f(int a, int b);
};
void Geometry::f(int a, int b)
{
    RBXASSERT(0);
}
}