// from server: 100% by nuck16
// roc 2009-12 009843b0  unit: seg_00980000  size: 55 bytes
//
// 009843b0  51                   push ecx
// 009843b1  6870996400           push 0x649970
// 009843b6  68f05fb800           push 0xb85ff0
// 009843bb  c705c82ab300e0d09c00 mov dword ptr [0xb32ac8], 0x9cd0e0
// 009843c5  e866d2a7ff           call 0x401630
// 009843ca  83c408               add esp, 8
// 009843cd  e81e42ccff           call 0x6485f0
// 009843d2  890424               mov dword ptr [esp], eax
// 009843d5  8d0424               lea eax, [esp]
// 009843d8  50                   push eax
// 009843d9  e8a2d5a7ff           call 0x401980
// 009843de  8bc8                 mov ecx, eax
// 009843e0  e86bd4a7ff           call 0x401850
// 009843e5  59                   pop ecx
// 009843e6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b85ff0;
extern const int data_009cd0e0[];
extern int global_b32ac8;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649970();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32ac8 = (int)data_009cd0e0;
    call_once(flag_b85ff0, &callDoDeclare_649970);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
