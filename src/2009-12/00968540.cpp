// from server: 100% by nuck16
// roc 2009-12 00968540  unit: seg_00960000  size: 73 bytes
//
// 00968540  51                   push ecx
// 00968541  6800784100           push 0x417800
// 00968546  68cca1b700           push 0xb7a1cc
// 0096854b  e8e090a9ff           call 0x401630
// 00968550  83c408               add esp, 8
// 00968553  e8f8f1aaff           call 0x417750
// 00968558  890424               mov dword ptr [esp], eax
// 0096855b  8d0424               lea eax, [esp]
// 0096855e  50                   push eax
// 0096855f  e81c94a9ff           call 0x401980
// 00968564  8bc8                 mov ecx, eax
// 00968566  e8b5cfadff           call 0x445520
// 0096856b  c7002839b000         mov dword ptr [eax], 0xb03928
// 00968571  6870dc9700           push 0x97dc70
// 00968576  c705e0a1b7009a020000 mov dword ptr [0xb7a1e0], 0x29a
// 00968580  e8a4c3e8ff           call 0x7f4929
// 00968585  83c408               add esp, 8
// 00968588  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7a1cc;
extern int global_b7a1e0;
extern ICreator creator_b03928;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_417800();
const Name &doDeclare();
void destroy_97dc70();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7a1cc, &callDoDeclare_417800);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b03928;
    global_b7a1e0 = 0x29a;
    atexit(&destroy_97dc70);
}
