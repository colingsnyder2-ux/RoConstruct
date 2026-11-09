// from server: 100% by nuck16
// roc 2009-12 00967ef0  unit: seg_00960000  size: 73 bytes
//
// 00967ef0  51                   push ecx
// 00967ef1  6800414000           push 0x404100
// 00967ef6  688495b700           push 0xb79584
// 00967efb  e83097a9ff           call 0x401630
// 00967f00  83c408               add esp, 8
// 00967f03  e8e8b9a9ff           call 0x4038f0
// 00967f08  890424               mov dword ptr [esp], eax
// 00967f0b  8d0424               lea eax, [esp]
// 00967f0e  50                   push eax
// 00967f0f  e86c9aa9ff           call 0x401980
// 00967f14  8bc8                 mov ecx, eax
// 00967f16  e805d6adff           call 0x445520
// 00967f1b  c70098fdaf00         mov dword ptr [eax], 0xaffd98
// 00967f21  6820d89700           push 0x97d820
// 00967f26  c7059095b7009a020000 mov dword ptr [0xb79590], 0x29a
// 00967f30  e8f4c9e8ff           call 0x7f4929
// 00967f35  83c408               add esp, 8
// 00967f38  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b79584;
extern int global_b79590;
extern ICreator creator_affd98;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_404100();
const Name &doDeclare();
void destroy_97d820();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b79584, &callDoDeclare_404100);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_affd98;
    global_b79590 = 0x29a;
    atexit(&destroy_97d820);
}
