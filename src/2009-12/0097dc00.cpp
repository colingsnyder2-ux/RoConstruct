// from server: 100% by nuck16
// roc 2009-12 0097dc00  unit: seg_00970000  size: 55 bytes
//
// 0097dc00  51                   push ecx
// 0097dc01  68d03a4100           push 0x413ad0
// 0097dc06  6810a1b700           push 0xb7a110
// 0097dc0b  c7059833b00004239a00 mov dword ptr [0xb03398], 0x9a2304
// 0097dc15  e8163aa8ff           call 0x401630
// 0097dc1a  83c408               add esp, 8
// 0097dc1d  e89e5aa9ff           call 0x4136c0
// 0097dc22  890424               mov dword ptr [esp], eax
// 0097dc25  8d0424               lea eax, [esp]
// 0097dc28  50                   push eax
// 0097dc29  e8523da8ff           call 0x401980
// 0097dc2e  8bc8                 mov ecx, eax
// 0097dc30  e81b3ca8ff           call 0x401850
// 0097dc35  59                   pop ecx
// 0097dc36  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7a110;
extern const int data_009a2304[];
extern int global_b03398;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_413ad0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b03398 = (int)data_009a2304;
    call_once(flag_b7a110, &callDoDeclare_413ad0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
