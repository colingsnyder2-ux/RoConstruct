// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX { namespace Network {
void initA(); void releaseA();
void initB(); void releaseB();
struct Init {
    Init() { initA(); initB(); }
    ~Init() { releaseA(); releaseB(); }
};
extern bool g_flag;
extern std::string g_version;
void reg1(); void reg2(); void reg3(); void reg4(); void reg5(); void reg6(); void reg7();
void registerClasses(bool flag)
{
    g_flag = flag;
    static Init init;
    g_version = "8";
    reg1();
    g_version += "7";
    reg2();
    reg3();
    g_version += "x";
    reg4();
    reg5();
    reg6();
    g_version += "P";
    reg7();
    g_version += "E";
}
}}
