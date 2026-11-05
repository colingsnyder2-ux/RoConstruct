// from server: 100% by nuck16
// roc 2009-12 00984370  unit: seg_00980000  size: 55 bytes
//
// 00984370  51                   push ecx
// 00984371  6880996400           push 0x649980
// 00984376  68f45fb800           push 0xb85ff4
// 0098437b  c705cc2ab300fcd09c00 mov dword ptr [0xb32acc], 0x9cd0fc
// 00984385  e8a6d2a7ff           call 0x401630
// 0098438a  83c408               add esp, 8
// 0098438d  e8ce42ccff           call 0x648660
// 00984392  890424               mov dword ptr [esp], eax
// 00984395  8d0424               lea eax, [esp]
// 00984398  50                   push eax
// 00984399  e8e2d5a7ff           call 0x401980
// 0098439e  8bc8                 mov ecx, eax
// 009843a0  e8abd4a7ff           call 0x401850
// 009843a5  59                   pop ecx
// 009843a6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b85ff4;
extern const int data_009cd0fc[];
extern int global_b32acc;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649980();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32acc = (int)data_009cd0fc;
    call_once(flag_b85ff4, &callDoDeclare_649980);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
