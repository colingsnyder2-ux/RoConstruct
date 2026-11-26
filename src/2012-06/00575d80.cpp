// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#define EMPTY &getNullName() == this
extern unsigned char g_assertEnabled;
extern char (__cdecl *g_assertHook)(const char*, const char*, int);
void __cdecl g_assertFail(unsigned char, const char*);
#define FILE_ "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\include\\Util/Object.h"
#define ASSERT_(cond, cs, line, lines) if (g_assertEnabled && !(cond)) { if (!g_assertHook || !g_assertHook(cs, FILE_, line)) g_assertFail(g_assertEnabled, cs " file: " FILE_ " line: " lines); }
namespace RBX {
class Name {
public:
    static const Name& getNullName();
    bool empty() const { return EMPTY; }
};
class ClassDescriptor {
public:
    const Name& name() const;
};
class Product {
public:
    static ClassDescriptor& classDescriptor();
    static const Name& className() { return classDescriptor().name(); }
    static bool isNullClassName();
};
bool Product::isNullClassName()
{
    ASSERT_(!className().empty(), "!className().empty()", 0x107, "263")
    return false;
}
}
