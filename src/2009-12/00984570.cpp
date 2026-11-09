// from server: 100% by nuck16
// roc 2009-12 00984570  unit: seg_00980000  size: 55 bytes
//
// 00984570  51                   push ecx
// 00984571  6800996400           push 0x649900
// 00984576  68d45fb800           push 0xb85fd4
// 0098457b  c705ac2ab3001cd09c00 mov dword ptr [0xb32aac], 0x9cd01c
// 00984585  e8a6d0a7ff           call 0x401630
// 0098458a  83c408               add esp, 8
// 0098458d  e84e3dccff           call 0x6482e0
// 00984592  890424               mov dword ptr [esp], eax
// 00984595  8d0424               lea eax, [esp]
// 00984598  50                   push eax
// 00984599  e8e2d3a7ff           call 0x401980
// 0098459e  8bc8                 mov ecx, eax
// 009845a0  e8abd2a7ff           call 0x401850
// 009845a5  59                   pop ecx
// 009845a6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b85fd4;
extern const int data_009cd01c[];
extern int global_b32aac;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649900();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32aac = (int)data_009cd01c;
    call_once(flag_b85fd4, &callDoDeclare_649900);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
