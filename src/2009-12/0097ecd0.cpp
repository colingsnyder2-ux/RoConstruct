// from server: 100% by nuck16
// roc 2009-12 0097ecd0  unit: seg_00970000  size: 55 bytes
//
// 0097ecd0  51                   push ecx
// 0097ecd1  68002d4600           push 0x462d00
// 0097ecd6  68bcb9b700           push 0xb7b9bc
// 0097ecdb  c705c4b4b000b8ea9a00 mov dword ptr [0xb0b4c4], 0x9aeab8
// 0097ece5  e84629a8ff           call 0x401630
// 0097ecea  83c408               add esp, 8
// 0097eced  e82e2faeff           call 0x461c20
// 0097ecf2  890424               mov dword ptr [esp], eax
// 0097ecf5  8d0424               lea eax, [esp]
// 0097ecf8  50                   push eax
// 0097ecf9  e8822ca8ff           call 0x401980
// 0097ecfe  8bc8                 mov ecx, eax
// 0097ed00  e84b2ba8ff           call 0x401850
// 0097ed05  59                   pop ecx
// 0097ed06  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7b9bc;
extern const int data_009aeab8[];
extern int global_b0b4c4;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_462d00();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b0b4c4 = (int)data_009aeab8;
    call_once(flag_b7b9bc, &callDoDeclare_462d00);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
