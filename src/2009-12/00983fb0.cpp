// from server: 100% by nuck16
// roc 2009-12 00983fb0  unit: seg_00980000  size: 55 bytes
//
// 00983fb0  51                   push ecx
// 00983fb1  68709a6400           push 0x649a70
// 00983fb6  683060b800           push 0xb86030
// 00983fbb  c705082bb30034d79c00 mov dword ptr [0xb32b08], 0x9cd734
// 00983fc5  e866d6a7ff           call 0x401630
// 00983fca  83c408               add esp, 8
// 00983fcd  e81e4dccff           call 0x648cf0
// 00983fd2  890424               mov dword ptr [esp], eax
// 00983fd5  8d0424               lea eax, [esp]
// 00983fd8  50                   push eax
// 00983fd9  e8a2d9a7ff           call 0x401980
// 00983fde  8bc8                 mov ecx, eax
// 00983fe0  e86bd8a7ff           call 0x401850
// 00983fe5  59                   pop ecx
// 00983fe6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86030;
extern const int data_009cd734[];
extern int global_b32b08;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649a70();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32b08 = (int)data_009cd734;
    call_once(flag_b86030, &callDoDeclare_649a70);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
