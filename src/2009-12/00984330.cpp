// from server: 100% by nuck16
// roc 2009-12 00984330  unit: seg_00980000  size: 55 bytes
//
// 00984330  51                   push ecx
// 00984331  6890996400           push 0x649990
// 00984336  68f85fb800           push 0xb85ff8
// 0098433b  c705d02ab30018d19c00 mov dword ptr [0xb32ad0], 0x9cd118
// 00984345  e8e6d2a7ff           call 0x401630
// 0098434a  83c408               add esp, 8
// 0098434d  e87e43ccff           call 0x6486d0
// 00984352  890424               mov dword ptr [esp], eax
// 00984355  8d0424               lea eax, [esp]
// 00984358  50                   push eax
// 00984359  e822d6a7ff           call 0x401980
// 0098435e  8bc8                 mov ecx, eax
// 00984360  e8ebd4a7ff           call 0x401850
// 00984365  59                   pop ecx
// 00984366  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b85ff8;
extern const int data_009cd118[];
extern int global_b32ad0;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649990();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32ad0 = (int)data_009cd118;
    call_once(flag_b85ff8, &callDoDeclare_649990);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
