// from server: 100% by nuck16
// roc 2009-12 00983cb0  unit: seg_00980000  size: 55 bytes
//
// 00983cb0  51                   push ecx
// 00983cb1  68309b6400           push 0x649b30
// 00983cb6  686060b800           push 0xb86060
// 00983cbb  c705382bb300f0d89c00 mov dword ptr [0xb32b38], 0x9cd8f0
// 00983cc5  e866d9a7ff           call 0x401630
// 00983cca  83c408               add esp, 8
// 00983ccd  e85e55ccff           call 0x649230
// 00983cd2  890424               mov dword ptr [esp], eax
// 00983cd5  8d0424               lea eax, [esp]
// 00983cd8  50                   push eax
// 00983cd9  e8a2dca7ff           call 0x401980
// 00983cde  8bc8                 mov ecx, eax
// 00983ce0  e86bdba7ff           call 0x401850
// 00983ce5  59                   pop ecx
// 00983ce6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86060;
extern const int data_009cd8f0[];
extern int global_b32b38;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649b30();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32b38 = (int)data_009cd8f0;
    call_once(flag_b86060, &callDoDeclare_649b30);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
