// from server: 100% by nuck16
// roc 2009-12 0097eb50  unit: seg_00970000  size: 55 bytes
//
// 0097eb50  51                   push ecx
// 0097eb51  68702d4600           push 0x462d70
// 0097eb56  68d8b9b700           push 0xb7b9d8
// 0097eb5b  c705dcb4b0004ceb9a00 mov dword ptr [0xb0b4dc], 0x9aeb4c
// 0097eb65  e8c62aa8ff           call 0x401630
// 0097eb6a  83c408               add esp, 8
// 0097eb6d  e8be33aeff           call 0x461f30
// 0097eb72  890424               mov dword ptr [esp], eax
// 0097eb75  8d0424               lea eax, [esp]
// 0097eb78  50                   push eax
// 0097eb79  e8022ea8ff           call 0x401980
// 0097eb7e  8bc8                 mov ecx, eax
// 0097eb80  e8cb2ca8ff           call 0x401850
// 0097eb85  59                   pop ecx
// 0097eb86  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7b9d8;
extern const int data_009aeb4c[];
extern int global_b0b4dc;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_462d70();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b0b4dc = (int)data_009aeb4c;
    call_once(flag_b7b9d8, &callDoDeclare_462d70);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
