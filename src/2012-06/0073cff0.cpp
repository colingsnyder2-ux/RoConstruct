// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <typeinfo>
extern "C" void __cdecl sub_972290(unsigned char, const char*);
extern unsigned char byte_E580B3;
extern char (__cdecl *dword_E5809C)(const char*, const char*, int);
int __stdcall sub_52acb0(int, int, int, int);
namespace RBX {
class Base {
public:
    Base(int);
    virtual ~Base();
};
class PluginManager : public Base {
public:
    PluginManager(int a1, int a2, int a3, int a4);
    virtual ~PluginManager();
};
}
using namespace RBX;
PluginManager::PluginManager(int a1, int a2, int a3, int a4)
    : Base(sub_52acb0(a1, a2, a3, a4))
{
    if (byte_E580B3 != 0 && !(typeid(PluginManager) == typeid(PluginManager))) {
        if (dword_E5809C == 0 || !dword_E5809C("Class::classType()==typeid(Class)", "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\include\\Reflection/Reflection.h", 0x1d5))
            sub_972290(byte_E580B3, "Class::classType()==typeid(Class) file: C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\include\\Reflection/Reflection.h line: 469");
    }
}