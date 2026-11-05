// from server: 100% by nuck16
// roc 2009-12 009842f0  unit: seg_00980000  size: 55 bytes
//
// 009842f0  51                   push ecx
// 009842f1  68a0996400           push 0x6499a0
// 009842f6  68fc5fb800           push 0xb85ffc
// 009842fb  c705d42ab30034d19c00 mov dword ptr [0xb32ad4], 0x9cd134
// 00984305  e826d3a7ff           call 0x401630
// 0098430a  83c408               add esp, 8
// 0098430d  e82e44ccff           call 0x648740
// 00984312  890424               mov dword ptr [esp], eax
// 00984315  8d0424               lea eax, [esp]
// 00984318  50                   push eax
// 00984319  e862d6a7ff           call 0x401980
// 0098431e  8bc8                 mov ecx, eax
// 00984320  e82bd5a7ff           call 0x401850
// 00984325  59                   pop ecx
// 00984326  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b85ffc;
extern const int data_009cd134[];
extern int global_b32ad4;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_6499a0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32ad4 = (int)data_009cd134;
    call_once(flag_b85ffc, &callDoDeclare_6499a0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
