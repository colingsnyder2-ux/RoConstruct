// from server: 100% by nuck16
// roc 2009-12 00983bb0  unit: seg_00980000  size: 55 bytes
//
// 00983bb0  51                   push ecx
// 00983bb1  68709b6400           push 0x649b70
// 00983bb6  687060b800           push 0xb86070
// 00983bbb  c705482bb30060d99c00 mov dword ptr [0xb32b48], 0x9cd960
// 00983bc5  e866daa7ff           call 0x401630
// 00983bca  83c408               add esp, 8
// 00983bcd  e81e58ccff           call 0x6493f0
// 00983bd2  890424               mov dword ptr [esp], eax
// 00983bd5  8d0424               lea eax, [esp]
// 00983bd8  50                   push eax
// 00983bd9  e8a2dda7ff           call 0x401980
// 00983bde  8bc8                 mov ecx, eax
// 00983be0  e86bdca7ff           call 0x401850
// 00983be5  59                   pop ecx
// 00983be6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86070;
extern const int data_009cd960[];
extern int global_b32b48;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649b70();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32b48 = (int)data_009cd960;
    call_once(flag_b86070, &callDoDeclare_649b70);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
