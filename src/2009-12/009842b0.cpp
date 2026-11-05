// from server: 100% by nuck16
// roc 2009-12 009842b0  unit: seg_00980000  size: 55 bytes
//
// 009842b0  51                   push ecx
// 009842b1  68b0996400           push 0x6499b0
// 009842b6  680060b800           push 0xb86000
// 009842bb  c705d82ab30050d19c00 mov dword ptr [0xb32ad8], 0x9cd150
// 009842c5  e866d3a7ff           call 0x401630
// 009842ca  83c408               add esp, 8
// 009842cd  e8de44ccff           call 0x6487b0
// 009842d2  890424               mov dword ptr [esp], eax
// 009842d5  8d0424               lea eax, [esp]
// 009842d8  50                   push eax
// 009842d9  e8a2d6a7ff           call 0x401980
// 009842de  8bc8                 mov ecx, eax
// 009842e0  e86bd5a7ff           call 0x401850
// 009842e5  59                   pop ecx
// 009842e6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86000;
extern const int data_009cd150[];
extern int global_b32ad8;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_6499b0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32ad8 = (int)data_009cd150;
    call_once(flag_b86000, &callDoDeclare_6499b0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
