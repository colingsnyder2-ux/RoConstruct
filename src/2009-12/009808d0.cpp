// from server: 100% by nuck16
// roc 2009-12 009808d0  unit: seg_00980000  size: 55 bytes
//
// 009808d0  51                   push ecx
// 009808d1  68b0885300           push 0x5388b0
// 009808d6  68cc05b800           push 0xb805cc
// 009808db  c70524f6b10014d39b00 mov dword ptr [0xb1f624], 0x9bd314
// 009808e5  e8460da8ff           call 0x401630
// 009808ea  83c408               add esp, 8
// 009808ed  e8ae6ebbff           call 0x5377a0
// 009808f2  890424               mov dword ptr [esp], eax
// 009808f5  8d0424               lea eax, [esp]
// 009808f8  50                   push eax
// 009808f9  e88210a8ff           call 0x401980
// 009808fe  8bc8                 mov ecx, eax
// 00980900  e84b0fa8ff           call 0x401850
// 00980905  59                   pop ecx
// 00980906  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b805cc;
extern const int data_009bd314[];
extern int global_b1f624;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_5388b0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b1f624 = (int)data_009bd314;
    call_once(flag_b805cc, &callDoDeclare_5388b0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
