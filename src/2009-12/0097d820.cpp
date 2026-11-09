// from server: 100% by nuck16
// roc 2009-12 0097d820  unit: seg_00970000  size: 55 bytes
//
// 0097d820  51                   push ecx
// 0097d821  6800414000           push 0x404100
// 0097d826  688495b700           push 0xb79584
// 0097d82b  c70598fdaf00d0fc9900 mov dword ptr [0xaffd98], 0x99fcd0
// 0097d835  e8f63da8ff           call 0x401630
// 0097d83a  83c408               add esp, 8
// 0097d83d  e8ae60a8ff           call 0x4038f0
// 0097d842  890424               mov dword ptr [esp], eax
// 0097d845  8d0424               lea eax, [esp]
// 0097d848  50                   push eax
// 0097d849  e83241a8ff           call 0x401980
// 0097d84e  8bc8                 mov ecx, eax
// 0097d850  e8fb3fa8ff           call 0x401850
// 0097d855  59                   pop ecx
// 0097d856  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b79584;
extern const int data_0099fcd0[];
extern int global_affd98;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_404100();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_affd98 = (int)data_0099fcd0;
    call_once(flag_b79584, &callDoDeclare_404100);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
