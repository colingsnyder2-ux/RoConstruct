// from server: 100% by nuck16
// roc 2009-12 009807d0  unit: seg_00980000  size: 55 bytes
//
// 009807d0  51                   push ecx
// 009807d1  68f0885300           push 0x5388f0
// 009807d6  68dc05b800           push 0xb805dc
// 009807db  c70534f6b10084d39b00 mov dword ptr [0xb1f634], 0x9bd384
// 009807e5  e8460ea8ff           call 0x401630
// 009807ea  83c408               add esp, 8
// 009807ed  e86e71bbff           call 0x537960
// 009807f2  890424               mov dword ptr [esp], eax
// 009807f5  8d0424               lea eax, [esp]
// 009807f8  50                   push eax
// 009807f9  e88211a8ff           call 0x401980
// 009807fe  8bc8                 mov ecx, eax
// 00980800  e84b10a8ff           call 0x401850
// 00980805  59                   pop ecx
// 00980806  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b805dc;
extern const int data_009bd384[];
extern int global_b1f634;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_5388f0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b1f634 = (int)data_009bd384;
    call_once(flag_b805dc, &callDoDeclare_5388f0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
