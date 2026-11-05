// from server: 100% by nuck16
// roc 2009-12 00969890  unit: seg_00960000  size: 73 bytes
//
// 00969890  51                   push ecx
// 00969891  6810674500           push 0x456710
// 00969896  68f0b7b700           push 0xb7b7f0
// 0096989b  e8907da9ff           call 0x401630
// 009698a0  83c408               add esp, 8
// 009698a3  e8e8b5aeff           call 0x454e90
// 009698a8  890424               mov dword ptr [esp], eax
// 009698ab  8d0424               lea eax, [esp]
// 009698ae  50                   push eax
// 009698af  e8cc80a9ff           call 0x401980
// 009698b4  8bc8                 mov ecx, eax
// 009698b6  e865bcadff           call 0x445520
// 009698bb  c700c89cb000         mov dword ptr [eax], 0xb09cc8
// 009698c1  6870ea9700           push 0x97ea70
// 009698c6  c70504b8b7009a020000 mov dword ptr [0xb7b804], 0x29a
// 009698d0  e854b0e8ff           call 0x7f4929
// 009698d5  83c408               add esp, 8
// 009698d8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7b7f0;
extern int global_b7b804;
extern ICreator creator_b09cc8;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_456710();
const Name &doDeclare();
void destroy_97ea70();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7b7f0, &callDoDeclare_456710);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b09cc8;
    global_b7b804 = 0x29a;
    atexit(&destroy_97ea70);
}
