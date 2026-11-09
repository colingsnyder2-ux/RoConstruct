// from server: 100% by nuck16
// roc 2009-12 00983ff0  unit: seg_00980000  size: 55 bytes
//
// 00983ff0  51                   push ecx
// 00983ff1  68609a6400           push 0x649a60
// 00983ff6  682c60b800           push 0xb8602c
// 00983ffb  c705042bb300ecd39c00 mov dword ptr [0xb32b04], 0x9cd3ec
// 00984005  e826d6a7ff           call 0x401630
// 0098400a  83c408               add esp, 8
// 0098400d  e86e4cccff           call 0x648c80
// 00984012  890424               mov dword ptr [esp], eax
// 00984015  8d0424               lea eax, [esp]
// 00984018  50                   push eax
// 00984019  e862d9a7ff           call 0x401980
// 0098401e  8bc8                 mov ecx, eax
// 00984020  e82bd8a7ff           call 0x401850
// 00984025  59                   pop ecx
// 00984026  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b8602c;
extern const int data_009cd3ec[];
extern int global_b32b04;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649a60();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32b04 = (int)data_009cd3ec;
    call_once(flag_b8602c, &callDoDeclare_649a60);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
