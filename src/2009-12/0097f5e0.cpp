// from server: 100% by nuck16
// roc 2009-12 0097f5e0  unit: seg_00970000  size: 55 bytes
//
// 0097f5e0  51                   push ecx
// 0097f5e1  68f0684f00           push 0x4f68f0
// 0097f5e6  6870deb700           push 0xb7de70
// 0097f5eb  c705a07fb100fca59b00 mov dword ptr [0xb17fa0], 0x9ba5fc
// 0097f5f5  e83620a8ff           call 0x401630
// 0097f5fa  83c408               add esp, 8
// 0097f5fd  e89e64b7ff           call 0x4f5aa0
// 0097f602  890424               mov dword ptr [esp], eax
// 0097f605  8d0424               lea eax, [esp]
// 0097f608  50                   push eax
// 0097f609  e87223a8ff           call 0x401980
// 0097f60e  8bc8                 mov ecx, eax
// 0097f610  e83b22a8ff           call 0x401850
// 0097f615  59                   pop ecx
// 0097f616  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7de70;
extern const int data_009ba5fc[];
extern int global_b17fa0;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4f68f0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b17fa0 = (int)data_009ba5fc;
    call_once(flag_b7de70, &callDoDeclare_4f68f0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
