// from server: 100% by nuck16
// roc 2009-12 00984030  unit: seg_00980000  size: 55 bytes
//
// 00984030  51                   push ecx
// 00984031  68509a6400           push 0x649a50
// 00984036  682860b800           push 0xb86028
// 0098403b  c705002bb300d0d39c00 mov dword ptr [0xb32b00], 0x9cd3d0
// 00984045  e8e6d5a7ff           call 0x401630
// 0098404a  83c408               add esp, 8
// 0098404d  e8be4bccff           call 0x648c10
// 00984052  890424               mov dword ptr [esp], eax
// 00984055  8d0424               lea eax, [esp]
// 00984058  50                   push eax
// 00984059  e822d9a7ff           call 0x401980
// 0098405e  8bc8                 mov ecx, eax
// 00984060  e8ebd7a7ff           call 0x401850
// 00984065  59                   pop ecx
// 00984066  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86028;
extern const int data_009cd3d0[];
extern int global_b32b00;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649a50();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32b00 = (int)data_009cd3d0;
    call_once(flag_b86028, &callDoDeclare_649a50);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
