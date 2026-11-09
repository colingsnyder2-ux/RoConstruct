// from server: 100% by nuck16
// roc 2009-12 0097d720  unit: seg_00970000  size: 55 bytes
//
// 0097d720  51                   push ecx
// 0097d721  6810214000           push 0x402110
// 0097d726  682895b700           push 0xb79528
// 0097d72b  c70538f6af0090f59900 mov dword ptr [0xaff638], 0x99f590
// 0097d735  e8f63ea8ff           call 0x401630
// 0097d73a  83c408               add esp, 8
// 0097d73d  e8de48a8ff           call 0x402020
// 0097d742  890424               mov dword ptr [esp], eax
// 0097d745  8d0424               lea eax, [esp]
// 0097d748  50                   push eax
// 0097d749  e83242a8ff           call 0x401980
// 0097d74e  8bc8                 mov ecx, eax
// 0097d750  e8fb40a8ff           call 0x401850
// 0097d755  59                   pop ecx
// 0097d756  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b79528;
extern const int data_0099f590[];
extern int global_aff638;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_402110();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_aff638 = (int)data_0099f590;
    call_once(flag_b79528, &callDoDeclare_402110);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
