// from server: 100% by nuck16
// roc 2009-12 0097dcb0  unit: seg_00970000  size: 55 bytes
//
// 0097dcb0  51                   push ecx
// 0097dcb1  68f0774100           push 0x4177f0
// 0097dcb6  68c8a1b700           push 0xb7a1c8
// 0097dcbb  c7052439b00030259a00 mov dword ptr [0xb03924], 0x9a2530
// 0097dcc5  e86639a8ff           call 0x401630
// 0097dcca  83c408               add esp, 8
// 0097dccd  e80e9aa9ff           call 0x4176e0
// 0097dcd2  890424               mov dword ptr [esp], eax
// 0097dcd5  8d0424               lea eax, [esp]
// 0097dcd8  50                   push eax
// 0097dcd9  e8a23ca8ff           call 0x401980
// 0097dcde  8bc8                 mov ecx, eax
// 0097dce0  e86b3ba8ff           call 0x401850
// 0097dce5  59                   pop ecx
// 0097dce6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7a1c8;
extern const int data_009a2530[];
extern int global_b03924;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4177f0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b03924 = (int)data_009a2530;
    call_once(flag_b7a1c8, &callDoDeclare_4177f0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
