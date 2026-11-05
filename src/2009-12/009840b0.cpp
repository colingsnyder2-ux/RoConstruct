// from server: 100% by nuck16
// roc 2009-12 009840b0  unit: seg_00980000  size: 55 bytes
//
// 009840b0  51                   push ecx
// 009840b1  68309a6400           push 0x649a30
// 009840b6  682060b800           push 0xb86020
// 009840bb  c705f82ab30030d29c00 mov dword ptr [0xb32af8], 0x9cd230
// 009840c5  e866d5a7ff           call 0x401630
// 009840ca  83c408               add esp, 8
// 009840cd  e85e4accff           call 0x648b30
// 009840d2  890424               mov dword ptr [esp], eax
// 009840d5  8d0424               lea eax, [esp]
// 009840d8  50                   push eax
// 009840d9  e8a2d8a7ff           call 0x401980
// 009840de  8bc8                 mov ecx, eax
// 009840e0  e86bd7a7ff           call 0x401850
// 009840e5  59                   pop ecx
// 009840e6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86020;
extern const int data_009cd230[];
extern int global_b32af8;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649a30();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32af8 = (int)data_009cd230;
    call_once(flag_b86020, &callDoDeclare_649a30);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
