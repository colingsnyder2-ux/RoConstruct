// from server: 100% by nuck16
// roc 2009-12 0097dd70  unit: seg_00970000  size: 55 bytes
//
// 0097dd70  51                   push ecx
// 0097dd71  68c0774100           push 0x4177c0
// 0097dd76  68bca1b700           push 0xb7a1bc
// 0097dd7b  c7051839b000dc249a00 mov dword ptr [0xb03918], 0x9a24dc
// 0097dd85  e8a638a8ff           call 0x401630
// 0097dd8a  83c408               add esp, 8
// 0097dd8d  e8fe97a9ff           call 0x417590
// 0097dd92  890424               mov dword ptr [esp], eax
// 0097dd95  8d0424               lea eax, [esp]
// 0097dd98  50                   push eax
// 0097dd99  e8e23ba8ff           call 0x401980
// 0097dd9e  8bc8                 mov ecx, eax
// 0097dda0  e8ab3aa8ff           call 0x401850
// 0097dda5  59                   pop ecx
// 0097dda6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7a1bc;
extern const int data_009a24dc[];
extern int global_b03918;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4177c0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b03918 = (int)data_009a24dc;
    call_once(flag_b7a1bc, &callDoDeclare_4177c0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
