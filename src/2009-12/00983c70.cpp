// from server: 100% by nuck16
// roc 2009-12 00983c70  unit: seg_00980000  size: 55 bytes
//
// 00983c70  51                   push ecx
// 00983c71  68409b6400           push 0x649b40
// 00983c76  686460b800           push 0xb86064
// 00983c7b  c7053c2bb3000cd99c00 mov dword ptr [0xb32b3c], 0x9cd90c
// 00983c85  e8a6d9a7ff           call 0x401630
// 00983c8a  83c408               add esp, 8
// 00983c8d  e80e56ccff           call 0x6492a0
// 00983c92  890424               mov dword ptr [esp], eax
// 00983c95  8d0424               lea eax, [esp]
// 00983c98  50                   push eax
// 00983c99  e8e2dca7ff           call 0x401980
// 00983c9e  8bc8                 mov ecx, eax
// 00983ca0  e8abdba7ff           call 0x401850
// 00983ca5  59                   pop ecx
// 00983ca6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86064;
extern const int data_009cd90c[];
extern int global_b32b3c;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649b40();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32b3c = (int)data_009cd90c;
    call_once(flag_b86064, &callDoDeclare_649b40);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
