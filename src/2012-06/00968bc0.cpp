// from server: 85% by Xemicl
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
        if (!RBX::assertHook || !RBX::assertHook(#expr, "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\tool\\LuaDragTool.cpp", 60)) \
            RBX::assertionFailed(RBX::assertsFatal, #expr " file: C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\tool\\LuaDragTool.cpp line: 60"); \
    }
struct Pad { char d[0x150]; };
struct Base2 { int x; };
struct Par : Pad, Base2 { };
struct Tmp { char d[0x1c]; Tmp(const Tmp&); Tmp(){} };
struct Tgt { void m(Tmp t); };
struct L { char pad[0x1c]; bool cap; char p2[3]; Par* par; char p3[0x34 - 0x24]; Tgt* tg; bool captured() const { return cap; } void f(int a); };
Tmp mk(int a, Base2* q);
void L::f(int a) { RBXASSERT(this->captured()); Base2* q = par; tg->m(mk(a, q)); }


