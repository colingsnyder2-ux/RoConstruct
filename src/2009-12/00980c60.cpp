// from server: 100% by nuck16
// roc 2009-12 00980c60  unit: seg_00980000  size: 55 bytes
//
// 00980c60  51                   push ecx
// 00980c61  68607c5700           push 0x577c60
// 00980c66  687827b800           push 0xb82778
// 00980c6b  c705fc4eb200ac0b9c00 mov dword ptr [0xb24efc], 0x9c0bac
// 00980c75  e8b609a8ff           call 0x401630
// 00980c7a  83c408               add esp, 8
// 00980c7d  e80e6cbfff           call 0x577890
// 00980c82  890424               mov dword ptr [esp], eax
// 00980c85  8d0424               lea eax, [esp]
// 00980c88  50                   push eax
// 00980c89  e8f20ca8ff           call 0x401980
// 00980c8e  8bc8                 mov ecx, eax
// 00980c90  e8bb0ba8ff           call 0x401850
// 00980c95  59                   pop ecx
// 00980c96  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b82778;
extern const int data_009c0bac[];
extern int global_b24efc;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_577c60();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b24efc = (int)data_009c0bac;
    call_once(flag_b82778, &callDoDeclare_577c60);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
