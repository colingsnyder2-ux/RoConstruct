// from server: 100% by nuck16
// roc 2009-12 0097d940  unit: seg_00970000  size: 55 bytes
//
// 0097d940  51                   push ecx
// 0097d941  68a0954000           push 0x4095a0
// 0097d946  681c96b700           push 0xb7961c
// 0097d94b  c705601db0008c039a00 mov dword ptr [0xb01d60], 0x9a038c
// 0097d955  e8d63ca8ff           call 0x401630
// 0097d95a  83c408               add esp, 8
// 0097d95d  e85eb9a8ff           call 0x4092c0
// 0097d962  890424               mov dword ptr [esp], eax
// 0097d965  8d0424               lea eax, [esp]
// 0097d968  50                   push eax
// 0097d969  e81240a8ff           call 0x401980
// 0097d96e  8bc8                 mov ecx, eax
// 0097d970  e8db3ea8ff           call 0x401850
// 0097d975  59                   pop ecx
// 0097d976  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7961c;
extern const int data_009a038c[];
extern int global_b01d60;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4095a0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b01d60 = (int)data_009a038c;
    call_once(flag_b7961c, &callDoDeclare_4095a0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
