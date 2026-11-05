// from server: 100% by nuck16
// roc 2009-12 00980be0  unit: seg_00980000  size: 55 bytes
//
// 00980be0  51                   push ecx
// 00980be1  68b0515700           push 0x5751b0
// 00980be6  683027b800           push 0xb82730
// 00980beb  c7051842b200e4079c00 mov dword ptr [0xb24218], 0x9c07e4
// 00980bf5  e8360aa8ff           call 0x401630
// 00980bfa  83c408               add esp, 8
// 00980bfd  e8ae43bfff           call 0x574fb0
// 00980c02  890424               mov dword ptr [esp], eax
// 00980c05  8d0424               lea eax, [esp]
// 00980c08  50                   push eax
// 00980c09  e8720da8ff           call 0x401980
// 00980c0e  8bc8                 mov ecx, eax
// 00980c10  e83b0ca8ff           call 0x401850
// 00980c15  59                   pop ecx
// 00980c16  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b82730;
extern const int data_009c07e4[];
extern int global_b24218;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_5751b0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b24218 = (int)data_009c07e4;
    call_once(flag_b82730, &callDoDeclare_5751b0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
