// from server: 100% by nuck16
// roc 2009-12 00984270  unit: seg_00980000  size: 55 bytes
//
// 00984270  51                   push ecx
// 00984271  68c0996400           push 0x6499c0
// 00984276  680460b800           push 0xb86004
// 0098427b  c705dc2ab3006cd19c00 mov dword ptr [0xb32adc], 0x9cd16c
// 00984285  e8a6d3a7ff           call 0x401630
// 0098428a  83c408               add esp, 8
// 0098428d  e88e45ccff           call 0x648820
// 00984292  890424               mov dword ptr [esp], eax
// 00984295  8d0424               lea eax, [esp]
// 00984298  50                   push eax
// 00984299  e8e2d6a7ff           call 0x401980
// 0098429e  8bc8                 mov ecx, eax
// 009842a0  e8abd5a7ff           call 0x401850
// 009842a5  59                   pop ecx
// 009842a6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86004;
extern const int data_009cd16c[];
extern int global_b32adc;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_6499c0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32adc = (int)data_009cd16c;
    call_once(flag_b86004, &callDoDeclare_6499c0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
