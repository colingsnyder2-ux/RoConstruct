// from server: 100% by nuck16
// roc 2009-12 00983f70  unit: seg_00980000  size: 55 bytes
//
// 00983f70  51                   push ecx
// 00983f71  68809a6400           push 0x649a80
// 00983f76  683460b800           push 0xb86034
// 00983f7b  c7050c2bb30050d79c00 mov dword ptr [0xb32b0c], 0x9cd750
// 00983f85  e8a6d6a7ff           call 0x401630
// 00983f8a  83c408               add esp, 8
// 00983f8d  e8ce4dccff           call 0x648d60
// 00983f92  890424               mov dword ptr [esp], eax
// 00983f95  8d0424               lea eax, [esp]
// 00983f98  50                   push eax
// 00983f99  e8e2d9a7ff           call 0x401980
// 00983f9e  8bc8                 mov ecx, eax
// 00983fa0  e8abd8a7ff           call 0x401850
// 00983fa5  59                   pop ecx
// 00983fa6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86034;
extern const int data_009cd750[];
extern int global_b32b0c;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649a80();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32b0c = (int)data_009cd750;
    call_once(flag_b86034, &callDoDeclare_649a80);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
