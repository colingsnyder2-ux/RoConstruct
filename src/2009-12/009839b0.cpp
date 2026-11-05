// from server: 100% by nuck16
// roc 2009-12 009839b0  unit: seg_00980000  size: 55 bytes
//
// 009839b0  51                   push ecx
// 009839b1  68f09b6400           push 0x649bf0
// 009839b6  689060b800           push 0xb86090
// 009839bb  c705682bb300a0dd9c00 mov dword ptr [0xb32b68], 0x9cdda0
// 009839c5  e866dca7ff           call 0x401630
// 009839ca  83c408               add esp, 8
// 009839cd  e89e5dccff           call 0x649770
// 009839d2  890424               mov dword ptr [esp], eax
// 009839d5  8d0424               lea eax, [esp]
// 009839d8  50                   push eax
// 009839d9  e8a2dfa7ff           call 0x401980
// 009839de  8bc8                 mov ecx, eax
// 009839e0  e86bdea7ff           call 0x401850
// 009839e5  59                   pop ecx
// 009839e6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86090;
extern const int data_009cdda0[];
extern int global_b32b68;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649bf0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32b68 = (int)data_009cdda0;
    call_once(flag_b86090, &callDoDeclare_649bf0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
