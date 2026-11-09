// from server: 100% by nuck16
// roc 2009-12 0097f820  unit: seg_00970000  size: 55 bytes
//
// 0097f820  51                   push ecx
// 0097f821  6850684f00           push 0x4f6850
// 0097f826  6848deb700           push 0xb7de48
// 0097f82b  c7057c7fb100a8a49b00 mov dword ptr [0xb17f7c], 0x9ba4a8
// 0097f835  e8f61da8ff           call 0x401630
// 0097f83a  83c408               add esp, 8
// 0097f83d  e8fe5db7ff           call 0x4f5640
// 0097f842  890424               mov dword ptr [esp], eax
// 0097f845  8d0424               lea eax, [esp]
// 0097f848  50                   push eax
// 0097f849  e83221a8ff           call 0x401980
// 0097f84e  8bc8                 mov ecx, eax
// 0097f850  e8fb1fa8ff           call 0x401850
// 0097f855  59                   pop ecx
// 0097f856  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7de48;
extern const int data_009ba4a8[];
extern int global_b17f7c;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4f6850();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b17f7c = (int)data_009ba4a8;
    call_once(flag_b7de48, &callDoDeclare_4f6850);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
