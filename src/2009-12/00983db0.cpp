// from server: 100% by nuck16
// roc 2009-12 00983db0  unit: seg_00980000  size: 55 bytes
//
// 00983db0  51                   push ecx
// 00983db1  68f09a6400           push 0x649af0
// 00983db6  685060b800           push 0xb86050
// 00983dbb  c705282bb30080d89c00 mov dword ptr [0xb32b28], 0x9cd880
// 00983dc5  e866d8a7ff           call 0x401630
// 00983dca  83c408               add esp, 8
// 00983dcd  e89e52ccff           call 0x649070
// 00983dd2  890424               mov dword ptr [esp], eax
// 00983dd5  8d0424               lea eax, [esp]
// 00983dd8  50                   push eax
// 00983dd9  e8a2dba7ff           call 0x401980
// 00983dde  8bc8                 mov ecx, eax
// 00983de0  e86bdaa7ff           call 0x401850
// 00983de5  59                   pop ecx
// 00983de6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86050;
extern const int data_009cd880[];
extern int global_b32b28;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649af0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32b28 = (int)data_009cd880;
    call_once(flag_b86050, &callDoDeclare_649af0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
