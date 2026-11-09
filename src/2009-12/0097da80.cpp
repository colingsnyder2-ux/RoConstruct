// from server: 100% by nuck16
// roc 2009-12 0097da80  unit: seg_00970000  size: 55 bytes
//
// 0097da80  51                   push ecx
// 0097da81  6850954000           push 0x409550
// 0097da86  680896b700           push 0xb79608
// 0097da8b  c7054c1db00078009a00 mov dword ptr [0xb01d4c], 0x9a0078
// 0097da95  e8963ba8ff           call 0x401630
// 0097da9a  83c408               add esp, 8
// 0097da9d  e8eeb5a8ff           call 0x409090
// 0097daa2  890424               mov dword ptr [esp], eax
// 0097daa5  8d0424               lea eax, [esp]
// 0097daa8  50                   push eax
// 0097daa9  e8d23ea8ff           call 0x401980
// 0097daae  8bc8                 mov ecx, eax
// 0097dab0  e89b3da8ff           call 0x401850
// 0097dab5  59                   pop ecx
// 0097dab6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b79608;
extern const int data_009a0078[];
extern int global_b01d4c;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_409550();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b01d4c = (int)data_009a0078;
    call_once(flag_b79608, &callDoDeclare_409550);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
