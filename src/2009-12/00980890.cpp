// from server: 100% by nuck16
// roc 2009-12 00980890  unit: seg_00980000  size: 55 bytes
//
// 00980890  51                   push ecx
// 00980891  68c0885300           push 0x5388c0
// 00980896  68d005b800           push 0xb805d0
// 0098089b  c70528f6b10030d39b00 mov dword ptr [0xb1f628], 0x9bd330
// 009808a5  e8860da8ff           call 0x401630
// 009808aa  83c408               add esp, 8
// 009808ad  e85e6fbbff           call 0x537810
// 009808b2  890424               mov dword ptr [esp], eax
// 009808b5  8d0424               lea eax, [esp]
// 009808b8  50                   push eax
// 009808b9  e8c210a8ff           call 0x401980
// 009808be  8bc8                 mov ecx, eax
// 009808c0  e88b0fa8ff           call 0x401850
// 009808c5  59                   pop ecx
// 009808c6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b805d0;
extern const int data_009bd330[];
extern int global_b1f628;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_5388c0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b1f628 = (int)data_009bd330;
    call_once(flag_b805d0, &callDoDeclare_5388c0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
