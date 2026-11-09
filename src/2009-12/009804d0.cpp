// from server: 100% by nuck16
// roc 2009-12 009804d0  unit: seg_00980000  size: 55 bytes
//
// 009804d0  51                   push ecx
// 009804d1  68b0be5200           push 0x52beb0
// 009804d6  686801b800           push 0xb80168
// 009804db  c70580cbb1009cc89b00 mov dword ptr [0xb1cb80], 0x9bc89c
// 009804e5  e84611a8ff           call 0x401630
// 009804ea  83c408               add esp, 8
// 009804ed  e81eb6baff           call 0x52bb10
// 009804f2  890424               mov dword ptr [esp], eax
// 009804f5  8d0424               lea eax, [esp]
// 009804f8  50                   push eax
// 009804f9  e88214a8ff           call 0x401980
// 009804fe  8bc8                 mov ecx, eax
// 00980500  e84b13a8ff           call 0x401850
// 00980505  59                   pop ecx
// 00980506  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b80168;
extern const int data_009bc89c[];
extern int global_b1cb80;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_52beb0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b1cb80 = (int)data_009bc89c;
    call_once(flag_b80168, &callDoDeclare_52beb0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
