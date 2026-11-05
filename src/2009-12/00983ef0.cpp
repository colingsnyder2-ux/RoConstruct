// from server: 100% by nuck16
// roc 2009-12 00983ef0  unit: seg_00980000  size: 55 bytes
//
// 00983ef0  51                   push ecx
// 00983ef1  68a09a6400           push 0x649aa0
// 00983ef6  683c60b800           push 0xb8603c
// 00983efb  c705142bb30088d79c00 mov dword ptr [0xb32b14], 0x9cd788
// 00983f05  e826d7a7ff           call 0x401630
// 00983f0a  83c408               add esp, 8
// 00983f0d  e82e4fccff           call 0x648e40
// 00983f12  890424               mov dword ptr [esp], eax
// 00983f15  8d0424               lea eax, [esp]
// 00983f18  50                   push eax
// 00983f19  e862daa7ff           call 0x401980
// 00983f1e  8bc8                 mov ecx, eax
// 00983f20  e82bd9a7ff           call 0x401850
// 00983f25  59                   pop ecx
// 00983f26  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b8603c;
extern const int data_009cd788[];
extern int global_b32b14;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649aa0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32b14 = (int)data_009cd788;
    call_once(flag_b8603c, &callDoDeclare_649aa0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
