// from server: 100% by nuck16
// roc 2009-12 00983af0  unit: seg_00980000  size: 55 bytes
//
// 00983af0  51                   push ecx
// 00983af1  68a09b6400           push 0x649ba0
// 00983af6  687c60b800           push 0xb8607c
// 00983afb  c705542bb300f8da9c00 mov dword ptr [0xb32b54], 0x9cdaf8
// 00983b05  e826dba7ff           call 0x401630
// 00983b0a  83c408               add esp, 8
// 00983b0d  e82e5accff           call 0x649540
// 00983b12  890424               mov dword ptr [esp], eax
// 00983b15  8d0424               lea eax, [esp]
// 00983b18  50                   push eax
// 00983b19  e862dea7ff           call 0x401980
// 00983b1e  8bc8                 mov ecx, eax
// 00983b20  e82bdda7ff           call 0x401850
// 00983b25  59                   pop ecx
// 00983b26  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b8607c;
extern const int data_009cdaf8[];
extern int global_b32b54;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649ba0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32b54 = (int)data_009cdaf8;
    call_once(flag_b8607c, &callDoDeclare_649ba0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
