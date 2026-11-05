// from server: 100% by nuck16
// roc 2009-12 0097f6e0  unit: seg_00970000  size: 55 bytes
//
// 0097f6e0  51                   push ecx
// 0097f6e1  68b0684f00           push 0x4f68b0
// 0097f6e6  6860deb700           push 0xb7de60
// 0097f6eb  c705907fb1000ca59b00 mov dword ptr [0xb17f90], 0x9ba50c
// 0097f6f5  e8361fa8ff           call 0x401630
// 0097f6fa  83c408               add esp, 8
// 0097f6fd  e8de61b7ff           call 0x4f58e0
// 0097f702  890424               mov dword ptr [esp], eax
// 0097f705  8d0424               lea eax, [esp]
// 0097f708  50                   push eax
// 0097f709  e87222a8ff           call 0x401980
// 0097f70e  8bc8                 mov ecx, eax
// 0097f710  e83b21a8ff           call 0x401850
// 0097f715  59                   pop ecx
// 0097f716  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7de60;
extern const int data_009ba50c[];
extern int global_b17f90;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4f68b0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b17f90 = (int)data_009ba50c;
    call_once(flag_b7de60, &callDoDeclare_4f68b0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
