// from server: 100% by nuck16
// roc 2009-12 00969650  unit: seg_00960000  size: 73 bytes
//
// 00969650  51                   push ecx
// 00969651  6800cd4400           push 0x44cd00
// 00969656  688cb4b700           push 0xb7b48c
// 0096965b  e8d07fa9ff           call 0x401630
// 00969660  83c408               add esp, 8
// 00969663  e8c825aeff           call 0x44bc30
// 00969668  890424               mov dword ptr [esp], eax
// 0096966b  8d0424               lea eax, [esp]
// 0096966e  50                   push eax
// 0096966f  e80c83a9ff           call 0x401980
// 00969674  8bc8                 mov ecx, eax
// 00969676  e8a5beadff           call 0x445520
// 0096967b  c700e494b000         mov dword ptr [eax], 0xb094e4
// 00969681  68e0e99700           push 0x97e9e0
// 00969686  c70510b6b7009a020000 mov dword ptr [0xb7b610], 0x29a
// 00969690  e894b2e8ff           call 0x7f4929
// 00969695  83c408               add esp, 8
// 00969698  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7b48c;
extern int global_b7b610;
extern ICreator creator_b094e4;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_44cd00();
const Name &doDeclare();
void destroy_97e9e0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7b48c, &callDoDeclare_44cd00);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b094e4;
    global_b7b610 = 0x29a;
    atexit(&destroy_97e9e0);
}
