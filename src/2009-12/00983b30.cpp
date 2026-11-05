// from server: 100% by nuck16
// roc 2009-12 00983b30  unit: seg_00980000  size: 55 bytes
//
// 00983b30  51                   push ecx
// 00983b31  68909b6400           push 0x649b90
// 00983b36  687860b800           push 0xb86078
// 00983b3b  c705502bb30070da9c00 mov dword ptr [0xb32b50], 0x9cda70
// 00983b45  e8e6daa7ff           call 0x401630
// 00983b4a  83c408               add esp, 8
// 00983b4d  e87e59ccff           call 0x6494d0
// 00983b52  890424               mov dword ptr [esp], eax
// 00983b55  8d0424               lea eax, [esp]
// 00983b58  50                   push eax
// 00983b59  e822dea7ff           call 0x401980
// 00983b5e  8bc8                 mov ecx, eax
// 00983b60  e8ebdca7ff           call 0x401850
// 00983b65  59                   pop ecx
// 00983b66  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86078;
extern const int data_009cda70[];
extern int global_b32b50;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649b90();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32b50 = (int)data_009cda70;
    call_once(flag_b86078, &callDoDeclare_649b90);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
