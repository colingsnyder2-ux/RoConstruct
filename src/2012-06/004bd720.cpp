// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#define _SECURE_SCL 0
#define _HAS_ITERATOR_DEBUGGING 0
#include <map>
struct Name;
extern unsigned char g_assertEnabled;
extern char (__cdecl *g_assertHook)(const char*, const char*, int);
void __cdecl g_assertFail(unsigned char, const char*);
extern void* const g_initPtr;
const Name& initDirect();
const Name& instance();
void __cdecl callOnce(int* flag, void (*fn)());
extern int g_onceFlag;
void onceFn();
#define FILE_ "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\Include\\Util/Object.h"
#define ASSERT_(cond, cs, line, lines) if (g_assertEnabled && !(cond)) { if (!g_assertHook || !g_assertHook(cs, FILE_, line)) g_assertFail(g_assertEnabled, cs " file: " FILE_ " line: " lines); }
struct CreatorBase;
struct Class {
    typedef std::map<const Name*, CreatorBase*> Creators;
    static Creators& getCreators();
};
inline const Name& className() { if (g_initPtr == 0) return initDirect(); callOnce(&g_onceFlag, &onceFn); return instance(); }
struct CreatorBase {
    static int magic;
    static bool wasConstructed() { return magic == 0x29a; }
    CreatorBase();
    virtual ~CreatorBase();
};
CreatorBase::CreatorBase()
{
    const Name& name = className();
    ASSERT_(Class::getCreators().find(&name)==Class::getCreators().end(), "Class::getCreators().find(&name)==Class::getCreators().end()", 0xd7, "215")
    ASSERT_(!wasConstructed(), "!wasConstructed()", 0xd8, "216")
    Class::getCreators()[&name] = this;
    magic = 0x29a;
    ASSERT_(Class::getCreators().find(&name)!=Class::getCreators().end(), "Class::getCreators().find(&name)!=Class::getCreators().end()", 0xdd, "221")
    ASSERT_(wasConstructed(), "wasConstructed()", 0xde, "222")}

