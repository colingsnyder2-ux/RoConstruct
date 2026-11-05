// from server: 100% by nuck16
// roc 2009-12 00983970  unit: seg_00980000  size: 55 bytes
//
// 00983970  51                   push ecx
// 00983971  68009c6400           push 0x649c00
// 00983976  689460b800           push 0xb86094
// 0098397b  c7056c2bb30028de9c00 mov dword ptr [0xb32b6c], 0x9cde28
// 00983985  e8a6dca7ff           call 0x401630
// 0098398a  83c408               add esp, 8
// 0098398d  e84e5eccff           call 0x6497e0
// 00983992  890424               mov dword ptr [esp], eax
// 00983995  8d0424               lea eax, [esp]
// 00983998  50                   push eax
// 00983999  e8e2dfa7ff           call 0x401980
// 0098399e  8bc8                 mov ecx, eax
// 009839a0  e8abdea7ff           call 0x401850
// 009839a5  59                   pop ecx
// 009839a6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86094;
extern const int data_009cde28[];
extern int global_b32b6c;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649c00();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32b6c = (int)data_009cde28;
    call_once(flag_b86094, &callDoDeclare_649c00);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
