// from server: 100% by nuck16
// roc 2009-12 00971640  unit: seg_00970000  size: 73 bytes
//
// 00971640  51                   push ecx
// 00971641  6840996400           push 0x649940
// 00971646  68e45fb800           push 0xb85fe4
// 0097164b  e8e0ffa8ff           call 0x401630
// 00971650  83c408               add esp, 8
// 00971653  e8486ecdff           call 0x6484a0
// 00971658  890424               mov dword ptr [esp], eax
// 0097165b  8d0424               lea eax, [esp]
// 0097165e  50                   push eax
// 0097165f  e81c03a9ff           call 0x401980
// 00971664  8bc8                 mov ecx, eax
// 00971666  e8b53eadff           call 0x445520
// 0097166b  c700bc2ab300         mov dword ptr [eax], 0xb32abc
// 00971671  6870449800           push 0x984470
// 00971676  c70510fcb8009a020000 mov dword ptr [0xb8fc10], 0x29a
// 00971680  e8a432e8ff           call 0x7f4929
// 00971685  83c408               add esp, 8
// 00971688  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b85fe4;
extern int global_b8fc10;
extern ICreator creator_b32abc;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649940();
const Name &doDeclare();
void destroy_984470();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b85fe4, &callDoDeclare_649940);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32abc;
    global_b8fc10 = 0x29a;
    atexit(&destroy_984470);
}
