// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
namespace RBX {
    extern bool assertsEnabled;
    extern bool assertsFatal;
    extern bool (*assertHook)(const char* expr, const char* file, int line);
    void assertionFailed(bool fatal, const char* message);
}
#define PROPFILE "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\include\\reflection/property.h"
#define RBXASSERT_T(cond, text) \
    if (RBX::assertsEnabled && !(cond)) { \
        if (!RBX::assertHook || !RBX::assertHook(text, PROPFILE, 255)) \
            RBX::assertionFailed(RBX::assertsFatal, text " file: " PROPFILE " line: 255"); \
    }
struct Target { virtual void v0(); virtual void v1(); virtual void call(int, int); };
struct Checker { bool check(int token); };
struct Impl { char pad[0x20]; Checker* checker; char pad2[4]; Target* target; };
int getToken();
namespace RBX { namespace Network {
struct IdSerializer {
    Impl* impl;
    int field4;
    int f(int arg);
};
int IdSerializer::f(int arg)
{
    RBXASSERT_T(impl->checker->check(getToken()), "isValueType<V>()");
    impl->target->call(arg, field4);
    return arg;
}
}}