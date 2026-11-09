// from server: 100% by nuck16
// roc 2009-12 0097eb90  unit: seg_00970000  size: 55 bytes
//
// 0097eb90  51                   push ecx
// 0097eb91  68602d4600           push 0x462d60
// 0097eb96  68d4b9b700           push 0xb7b9d4
// 0097eb9b  c705d8b4b00030eb9a00 mov dword ptr [0xb0b4d8], 0x9aeb30
// 0097eba5  e8862aa8ff           call 0x401630
// 0097ebaa  83c408               add esp, 8
// 0097ebad  e80e33aeff           call 0x461ec0
// 0097ebb2  890424               mov dword ptr [esp], eax
// 0097ebb5  8d0424               lea eax, [esp]
// 0097ebb8  50                   push eax
// 0097ebb9  e8c22da8ff           call 0x401980
// 0097ebbe  8bc8                 mov ecx, eax
// 0097ebc0  e88b2ca8ff           call 0x401850
// 0097ebc5  59                   pop ecx
// 0097ebc6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7b9d4;
extern const int data_009aeb30[];
extern int global_b0b4d8;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_462d60();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b0b4d8 = (int)data_009aeb30;
    call_once(flag_b7b9d4, &callDoDeclare_462d60);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
