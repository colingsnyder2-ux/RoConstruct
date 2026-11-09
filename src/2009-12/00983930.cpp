// from server: 100% by nuck16
// roc 2009-12 00983930  unit: seg_00980000  size: 55 bytes
//
// 00983930  51                   push ecx
// 00983931  68109c6400           push 0x649c10
// 00983936  689860b800           push 0xb86098
// 0098393b  c705702bb300b0de9c00 mov dword ptr [0xb32b70], 0x9cdeb0
// 00983945  e8e6dca7ff           call 0x401630
// 0098394a  83c408               add esp, 8
// 0098394d  e8fe5eccff           call 0x649850
// 00983952  890424               mov dword ptr [esp], eax
// 00983955  8d0424               lea eax, [esp]
// 00983958  50                   push eax
// 00983959  e822e0a7ff           call 0x401980
// 0098395e  8bc8                 mov ecx, eax
// 00983960  e8ebdea7ff           call 0x401850
// 00983965  59                   pop ecx
// 00983966  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86098;
extern const int data_009cdeb0[];
extern int global_b32b70;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649c10();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32b70 = (int)data_009cdeb0;
    call_once(flag_b86098, &callDoDeclare_649c10);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
