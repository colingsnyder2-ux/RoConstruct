// from server: 100% by nuck16
// roc 2009-12 00983eb0  unit: seg_00980000  size: 55 bytes
//
// 00983eb0  51                   push ecx
// 00983eb1  68b09a6400           push 0x649ab0
// 00983eb6  684060b800           push 0xb86040
// 00983ebb  c705182bb30010d89c00 mov dword ptr [0xb32b18], 0x9cd810
// 00983ec5  e866d7a7ff           call 0x401630
// 00983eca  83c408               add esp, 8
// 00983ecd  e8de4fccff           call 0x648eb0
// 00983ed2  890424               mov dword ptr [esp], eax
// 00983ed5  8d0424               lea eax, [esp]
// 00983ed8  50                   push eax
// 00983ed9  e8a2daa7ff           call 0x401980
// 00983ede  8bc8                 mov ecx, eax
// 00983ee0  e86bd9a7ff           call 0x401850
// 00983ee5  59                   pop ecx
// 00983ee6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86040;
extern const int data_009cd810[];
extern int global_b32b18;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649ab0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32b18 = (int)data_009cd810;
    call_once(flag_b86040, &callDoDeclare_649ab0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
