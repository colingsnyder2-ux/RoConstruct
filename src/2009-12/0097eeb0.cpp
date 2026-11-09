// from server: 100% by nuck16
// roc 2009-12 0097eeb0  unit: seg_00970000  size: 55 bytes
//
// 0097eeb0  51                   push ecx
// 0097eeb1  68b0ac4900           push 0x49acb0
// 0097eeb6  68f0cdb700           push 0xb7cdf0
// 0097eebb  c70514fdb000203d9b00 mov dword ptr [0xb0fd14], 0x9b3d20
// 0097eec5  e86627a8ff           call 0x401630
// 0097eeca  83c408               add esp, 8
// 0097eecd  e8eeb8b1ff           call 0x49a7c0
// 0097eed2  890424               mov dword ptr [esp], eax
// 0097eed5  8d0424               lea eax, [esp]
// 0097eed8  50                   push eax
// 0097eed9  e8a22aa8ff           call 0x401980
// 0097eede  8bc8                 mov ecx, eax
// 0097eee0  e86b29a8ff           call 0x401850
// 0097eee5  59                   pop ecx
// 0097eee6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7cdf0;
extern const int data_009b3d20[];
extern int global_b0fd14;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_49acb0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b0fd14 = (int)data_009b3d20;
    call_once(flag_b7cdf0, &callDoDeclare_49acb0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
