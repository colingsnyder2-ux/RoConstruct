// from server: 100% by nuck16
// roc 2009-12 00983cf0  unit: seg_00980000  size: 55 bytes
//
// 00983cf0  51                   push ecx
// 00983cf1  68209b6400           push 0x649b20
// 00983cf6  685c60b800           push 0xb8605c
// 00983cfb  c705342bb300d4d89c00 mov dword ptr [0xb32b34], 0x9cd8d4
// 00983d05  e826d9a7ff           call 0x401630
// 00983d0a  83c408               add esp, 8
// 00983d0d  e8ae54ccff           call 0x6491c0
// 00983d12  890424               mov dword ptr [esp], eax
// 00983d15  8d0424               lea eax, [esp]
// 00983d18  50                   push eax
// 00983d19  e862dca7ff           call 0x401980
// 00983d1e  8bc8                 mov ecx, eax
// 00983d20  e82bdba7ff           call 0x401850
// 00983d25  59                   pop ecx
// 00983d26  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b8605c;
extern const int data_009cd8d4[];
extern int global_b32b34;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649b20();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32b34 = (int)data_009cd8d4;
    call_once(flag_b8605c, &callDoDeclare_649b20);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
