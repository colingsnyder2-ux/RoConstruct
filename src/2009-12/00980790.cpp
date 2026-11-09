// from server: 100% by nuck16
// roc 2009-12 00980790  unit: seg_00980000  size: 55 bytes
//
// 00980790  51                   push ecx
// 00980791  6800895300           push 0x538900
// 00980796  68e005b800           push 0xb805e0
// 0098079b  c70538f6b100a0d39b00 mov dword ptr [0xb1f638], 0x9bd3a0
// 009807a5  e8860ea8ff           call 0x401630
// 009807aa  83c408               add esp, 8
// 009807ad  e81e72bbff           call 0x5379d0
// 009807b2  890424               mov dword ptr [esp], eax
// 009807b5  8d0424               lea eax, [esp]
// 009807b8  50                   push eax
// 009807b9  e8c211a8ff           call 0x401980
// 009807be  8bc8                 mov ecx, eax
// 009807c0  e88b10a8ff           call 0x401850
// 009807c5  59                   pop ecx
// 009807c6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b805e0;
extern const int data_009bd3a0[];
extern int global_b1f638;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_538900();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b1f638 = (int)data_009bd3a0;
    call_once(flag_b805e0, &callDoDeclare_538900);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
