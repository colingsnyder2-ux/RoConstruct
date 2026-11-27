// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
namespace RBX {
    extern bool assertsEnabled;
    extern bool assertsFatal;
    extern bool (*assertHook)(const char* expr, const char* file, int line);
    void assertionFailed(bool fatal, const char* message);
}
#define RBXASSERT(expr) \
    if (RBX::assertsEnabled && !(expr)) { \
        if (!RBX::assertHook || !RBX::assertHook(#expr, "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\V8Kernel\\Kernel.cpp", 127)) \
            RBX::assertionFailed(RBX::assertsFatal, #expr " file: C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\V8Kernel\\Kernel.cpp line: 127"); \
    }
struct Sub { void put(int); };
struct Inner { char pad[0x40]; Sub sub; };
struct K { char pad[0x10]; bool inStepCode; char p2[3]; Inner* inner; void f(int a); };
void K::f(int a) { RBXASSERT(!inStepCode); inner->sub.put(a); }
