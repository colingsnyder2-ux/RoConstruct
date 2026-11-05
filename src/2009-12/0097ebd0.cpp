// from server: 100% by nuck16
// roc 2009-12 0097ebd0  unit: seg_00970000  size: 55 bytes
//
// 0097ebd0  51                   push ecx
// 0097ebd1  68502d4600           push 0x462d50
// 0097ebd6  68d0b9b700           push 0xb7b9d0
// 0097ebdb  c705d4b4b00014eb9a00 mov dword ptr [0xb0b4d4], 0x9aeb14
// 0097ebe5  e8462aa8ff           call 0x401630
// 0097ebea  83c408               add esp, 8
// 0097ebed  e85e32aeff           call 0x461e50
// 0097ebf2  890424               mov dword ptr [esp], eax
// 0097ebf5  8d0424               lea eax, [esp]
// 0097ebf8  50                   push eax
// 0097ebf9  e8822da8ff           call 0x401980
// 0097ebfe  8bc8                 mov ecx, eax
// 0097ec00  e84b2ca8ff           call 0x401850
// 0097ec05  59                   pop ecx
// 0097ec06  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7b9d0;
extern const int data_009aeb14[];
extern int global_b0b4d4;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_462d50();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b0b4d4 = (int)data_009aeb14;
    call_once(flag_b7b9d0, &callDoDeclare_462d50);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
