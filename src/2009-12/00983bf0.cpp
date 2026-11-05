// from server: 100% by nuck16
// roc 2009-12 00983bf0  unit: seg_00980000  size: 55 bytes
//
// 00983bf0  51                   push ecx
// 00983bf1  68609b6400           push 0x649b60
// 00983bf6  686c60b800           push 0xb8606c
// 00983bfb  c705442bb30044d99c00 mov dword ptr [0xb32b44], 0x9cd944
// 00983c05  e826daa7ff           call 0x401630
// 00983c0a  83c408               add esp, 8
// 00983c0d  e86e57ccff           call 0x649380
// 00983c12  890424               mov dword ptr [esp], eax
// 00983c15  8d0424               lea eax, [esp]
// 00983c18  50                   push eax
// 00983c19  e862dda7ff           call 0x401980
// 00983c1e  8bc8                 mov ecx, eax
// 00983c20  e82bdca7ff           call 0x401850
// 00983c25  59                   pop ecx
// 00983c26  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b8606c;
extern const int data_009cd944[];
extern int global_b32b44;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649b60();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32b44 = (int)data_009cd944;
    call_once(flag_b8606c, &callDoDeclare_649b60);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
