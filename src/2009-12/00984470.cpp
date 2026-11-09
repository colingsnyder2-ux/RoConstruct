// from server: 100% by nuck16
// roc 2009-12 00984470  unit: seg_00980000  size: 55 bytes
//
// 00984470  51                   push ecx
// 00984471  6840996400           push 0x649940
// 00984476  68e45fb800           push 0xb85fe4
// 0098447b  c705bc2ab3008cd09c00 mov dword ptr [0xb32abc], 0x9cd08c
// 00984485  e8a6d1a7ff           call 0x401630
// 0098448a  83c408               add esp, 8
// 0098448d  e80e40ccff           call 0x6484a0
// 00984492  890424               mov dword ptr [esp], eax
// 00984495  8d0424               lea eax, [esp]
// 00984498  50                   push eax
// 00984499  e8e2d4a7ff           call 0x401980
// 0098449e  8bc8                 mov ecx, eax
// 009844a0  e8abd3a7ff           call 0x401850
// 009844a5  59                   pop ecx
// 009844a6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b85fe4;
extern const int data_009cd08c[];
extern int global_b32abc;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649940();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32abc = (int)data_009cd08c;
    call_once(flag_b85fe4, &callDoDeclare_649940);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
