// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void __cdecl sub_972290(unsigned char, const char*);
extern unsigned char byte_E580B3;
extern char (__cdecl *dword_E5809C)(const char*, const char*, int);
#include <typeinfo>
namespace RBX { class Camera; }
const void* __cdecl sub_67f5b0(int*);
const void* __cdecl sub_67f480();
struct Flags { bool a; bool b; short pad; Flags() : a(false), b(false) {} }; struct Holder { Flags f; int x; Holder() : x(0) {} }; struct Sig { int v; Sig() : v(0) {} };
struct Base {
    char bp[0xc];
    Base(int n, Flags f, Sig z);
    virtual ~Base();
};
struct Derived : Base {
    const std::type_info* pad;
    const void* tag;
    bool x;
    bool y;
    Derived(int a1, int a2, int a3);
    void sub_708c80();
};
Derived::Derived(int a1, int a2, int a3) : Base(a1, Holder().f, Sig())
{
    pad = &typeid(RBX::Camera*);
    const void* t = sub_67f5b0(&a2);
    tag = t;
    x = false;
    y = false;
    if (byte_E580B3 != 0 && sub_67f480() == t) {
        if (dword_E5809C == 0 || !dword_E5809C("!this->tag.empty()", "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\include\\reflection/Type.h", 0x4d))
            sub_972290(byte_E580B3, "!this->tag.empty() file: C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\include\\reflection/Type.h line: 77");
    }
    sub_708c80();
}

