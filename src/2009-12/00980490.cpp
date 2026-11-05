// from server: 100% by nuck16
// roc 2009-12 00980490  unit: seg_00980000  size: 55 bytes
//
// 00980490  51                   push ecx
// 00980491  68c0be5200           push 0x52bec0
// 00980496  686c01b800           push 0xb8016c
// 0098049b  c70584cbb100b8c89b00 mov dword ptr [0xb1cb84], 0x9bc8b8
// 009804a5  e88611a8ff           call 0x401630
// 009804aa  83c408               add esp, 8
// 009804ad  e8ceb6baff           call 0x52bb80
// 009804b2  890424               mov dword ptr [esp], eax
// 009804b5  8d0424               lea eax, [esp]
// 009804b8  50                   push eax
// 009804b9  e8c214a8ff           call 0x401980
// 009804be  8bc8                 mov ecx, eax
// 009804c0  e88b13a8ff           call 0x401850
// 009804c5  59                   pop ecx
// 009804c6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b8016c;
extern const int data_009bc8b8[];
extern int global_b1cb84;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_52bec0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b1cb84 = (int)data_009bc8b8;
    call_once(flag_b8016c, &callDoDeclare_52bec0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
