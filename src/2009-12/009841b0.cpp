// from server: 100% by nuck16
// roc 2009-12 009841b0  unit: seg_00980000  size: 55 bytes
//
// 009841b0  51                   push ecx
// 009841b1  68f0996400           push 0x6499f0
// 009841b6  681060b800           push 0xb86010
// 009841bb  c705e82ab300c0d19c00 mov dword ptr [0xb32ae8], 0x9cd1c0
// 009841c5  e866d4a7ff           call 0x401630
// 009841ca  83c408               add esp, 8
// 009841cd  e89e47ccff           call 0x648970
// 009841d2  890424               mov dword ptr [esp], eax
// 009841d5  8d0424               lea eax, [esp]
// 009841d8  50                   push eax
// 009841d9  e8a2d7a7ff           call 0x401980
// 009841de  8bc8                 mov ecx, eax
// 009841e0  e86bd6a7ff           call 0x401850
// 009841e5  59                   pop ecx
// 009841e6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86010;
extern const int data_009cd1c0[];
extern int global_b32ae8;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_6499f0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32ae8 = (int)data_009cd1c0;
    call_once(flag_b86010, &callDoDeclare_6499f0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
