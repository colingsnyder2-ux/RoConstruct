// from server: 100% by Xemicl
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace FLog { extern unsigned char Asserts; }
namespace RBX {
typedef bool (*AssertionHook)(const char* expr, const char* file, int line);
extern AssertionHook assertionHook;
void FastLog(unsigned int level, const char* message);
}
#define RBX_STR2(x) #x
#define RBX_STR(x) RBX_STR2(x)
#define RBXASSERT(expr, FILE_, LINE_) \
    do { if (FLog::Asserts && !(expr)) { \
        if (!RBX::assertionHook || !RBX::assertionHook(#expr, FILE_, LINE_)) \
            RBX::FastLog(FLog::Asserts, #expr " file: " FILE_ " line: " RBX_STR(LINE_)); \
    } } while (0)
namespace RBX {
class Geometry {
public:
    static int __stdcall CheckAssertion(int);
};
int __stdcall Geometry::CheckAssertion(int) {
    RBXASSERT(0, "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\include\\V8World/Geometry.h", 56);
    return 0;
}
}