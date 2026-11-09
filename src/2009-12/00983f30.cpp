// from server: 100% by nuck16
// roc 2009-12 00983f30  unit: seg_00980000  size: 55 bytes
//
// 00983f30  51                   push ecx
// 00983f31  68909a6400           push 0x649a90
// 00983f36  683860b800           push 0xb86038
// 00983f3b  c705102bb3006cd79c00 mov dword ptr [0xb32b10], 0x9cd76c
// 00983f45  e8e6d6a7ff           call 0x401630
// 00983f4a  83c408               add esp, 8
// 00983f4d  e87e4eccff           call 0x648dd0
// 00983f52  890424               mov dword ptr [esp], eax
// 00983f55  8d0424               lea eax, [esp]
// 00983f58  50                   push eax
// 00983f59  e822daa7ff           call 0x401980
// 00983f5e  8bc8                 mov ecx, eax
// 00983f60  e8ebd8a7ff           call 0x401850
// 00983f65  59                   pop ecx
// 00983f66  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86038;
extern const int data_009cd76c[];
extern int global_b32b10;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649a90();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32b10 = (int)data_009cd76c;
    call_once(flag_b86038, &callDoDeclare_649a90);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
