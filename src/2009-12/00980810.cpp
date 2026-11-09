// from server: 100% by nuck16
// roc 2009-12 00980810  unit: seg_00980000  size: 55 bytes
//
// 00980810  51                   push ecx
// 00980811  68e0885300           push 0x5388e0
// 00980816  68d805b800           push 0xb805d8
// 0098081b  c70530f6b10068d39b00 mov dword ptr [0xb1f630], 0x9bd368
// 00980825  e8060ea8ff           call 0x401630
// 0098082a  83c408               add esp, 8
// 0098082d  e8be70bbff           call 0x5378f0
// 00980832  890424               mov dword ptr [esp], eax
// 00980835  8d0424               lea eax, [esp]
// 00980838  50                   push eax
// 00980839  e84211a8ff           call 0x401980
// 0098083e  8bc8                 mov ecx, eax
// 00980840  e80b10a8ff           call 0x401850
// 00980845  59                   pop ecx
// 00980846  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b805d8;
extern const int data_009bd368[];
extern int global_b1f630;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_5388e0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b1f630 = (int)data_009bd368;
    call_once(flag_b805d8, &callDoDeclare_5388e0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
