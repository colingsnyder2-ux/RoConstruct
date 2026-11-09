// from server: 100% by nuck16
// roc 2009-12 00983b70  unit: seg_00980000  size: 55 bytes
//
// 00983b70  51                   push ecx
// 00983b71  68809b6400           push 0x649b80
// 00983b76  687460b800           push 0xb86074
// 00983b7b  c7054c2bb300e8d99c00 mov dword ptr [0xb32b4c], 0x9cd9e8
// 00983b85  e8a6daa7ff           call 0x401630
// 00983b8a  83c408               add esp, 8
// 00983b8d  e8ce58ccff           call 0x649460
// 00983b92  890424               mov dword ptr [esp], eax
// 00983b95  8d0424               lea eax, [esp]
// 00983b98  50                   push eax
// 00983b99  e8e2dda7ff           call 0x401980
// 00983b9e  8bc8                 mov ecx, eax
// 00983ba0  e8abdca7ff           call 0x401850
// 00983ba5  59                   pop ecx
// 00983ba6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86074;
extern const int data_009cd9e8[];
extern int global_b32b4c;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649b80();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32b4c = (int)data_009cd9e8;
    call_once(flag_b86074, &callDoDeclare_649b80);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
