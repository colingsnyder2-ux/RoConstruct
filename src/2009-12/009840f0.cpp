// from server: 100% by nuck16
// roc 2009-12 009840f0  unit: seg_00980000  size: 55 bytes
//
// 009840f0  51                   push ecx
// 009840f1  68209a6400           push 0x649a20
// 009840f6  681c60b800           push 0xb8601c
// 009840fb  c705f42ab30014d29c00 mov dword ptr [0xb32af4], 0x9cd214
// 00984105  e826d5a7ff           call 0x401630
// 0098410a  83c408               add esp, 8
// 0098410d  e8ae49ccff           call 0x648ac0
// 00984112  890424               mov dword ptr [esp], eax
// 00984115  8d0424               lea eax, [esp]
// 00984118  50                   push eax
// 00984119  e862d8a7ff           call 0x401980
// 0098411e  8bc8                 mov ecx, eax
// 00984120  e82bd7a7ff           call 0x401850
// 00984125  59                   pop ecx
// 00984126  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b8601c;
extern const int data_009cd214[];
extern int global_b32af4;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649a20();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32af4 = (int)data_009cd214;
    call_once(flag_b8601c, &callDoDeclare_649a20);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
