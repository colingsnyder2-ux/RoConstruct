// from server: 100% by nuck16
// roc 2009-12 0097ec50  unit: seg_00970000  size: 55 bytes
//
// 0097ec50  51                   push ecx
// 0097ec51  68202d4600           push 0x462d20
// 0097ec56  68c4b9b700           push 0xb7b9c4
// 0097ec5b  c705ccb4b000dcea9a00 mov dword ptr [0xb0b4cc], 0x9aeadc
// 0097ec65  e8c629a8ff           call 0x401630
// 0097ec6a  83c408               add esp, 8
// 0097ec6d  e88e30aeff           call 0x461d00
// 0097ec72  890424               mov dword ptr [esp], eax
// 0097ec75  8d0424               lea eax, [esp]
// 0097ec78  50                   push eax
// 0097ec79  e8022da8ff           call 0x401980
// 0097ec7e  8bc8                 mov ecx, eax
// 0097ec80  e8cb2ba8ff           call 0x401850
// 0097ec85  59                   pop ecx
// 0097ec86  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7b9c4;
extern const int data_009aeadc[];
extern int global_b0b4cc;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_462d20();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b0b4cc = (int)data_009aeadc;
    call_once(flag_b7b9c4, &callDoDeclare_462d20);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
