// from server: 100% by nuck16
// roc 2009-12 0097f5a0  unit: seg_00970000  size: 55 bytes
//
// 0097f5a0  51                   push ecx
// 0097f5a1  6800694f00           push 0x4f6900
// 0097f5a6  6874deb700           push 0xb7de74
// 0097f5ab  c705a47fb10094a69b00 mov dword ptr [0xb17fa4], 0x9ba694
// 0097f5b5  e87620a8ff           call 0x401630
// 0097f5ba  83c408               add esp, 8
// 0097f5bd  e84e65b7ff           call 0x4f5b10
// 0097f5c2  890424               mov dword ptr [esp], eax
// 0097f5c5  8d0424               lea eax, [esp]
// 0097f5c8  50                   push eax
// 0097f5c9  e8b223a8ff           call 0x401980
// 0097f5ce  8bc8                 mov ecx, eax
// 0097f5d0  e87b22a8ff           call 0x401850
// 0097f5d5  59                   pop ecx
// 0097f5d6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7de74;
extern const int data_009ba694[];
extern int global_b17fa4;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4f6900();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b17fa4 = (int)data_009ba694;
    call_once(flag_b7de74, &callDoDeclare_4f6900);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
