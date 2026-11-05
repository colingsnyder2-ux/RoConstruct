// from server: 100% by nuck16
// roc 2009-12 0097f7a0  unit: seg_00970000  size: 55 bytes
//
// 0097f7a0  51                   push ecx
// 0097f7a1  6880684f00           push 0x4f6880
// 0097f7a6  6854deb700           push 0xb7de54
// 0097f7ab  c705847fb100cca49b00 mov dword ptr [0xb17f84], 0x9ba4cc
// 0097f7b5  e8761ea8ff           call 0x401630
// 0097f7ba  83c408               add esp, 8
// 0097f7bd  e8ce5fb7ff           call 0x4f5790
// 0097f7c2  890424               mov dword ptr [esp], eax
// 0097f7c5  8d0424               lea eax, [esp]
// 0097f7c8  50                   push eax
// 0097f7c9  e8b221a8ff           call 0x401980
// 0097f7ce  8bc8                 mov ecx, eax
// 0097f7d0  e87b20a8ff           call 0x401850
// 0097f7d5  59                   pop ecx
// 0097f7d6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7de54;
extern const int data_009ba4cc[];
extern int global_b17f84;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4f6880();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b17f84 = (int)data_009ba4cc;
    call_once(flag_b7de54, &callDoDeclare_4f6880);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
