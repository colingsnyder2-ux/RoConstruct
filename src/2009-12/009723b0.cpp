// from server: 100% by nuck16
// roc 2009-12 009723b0  unit: seg_00970000  size: 73 bytes
//
// 009723b0  51                   push ecx
// 009723b1  68f09b6400           push 0x649bf0
// 009723b6  689060b800           push 0xb86090
// 009723bb  e870f2a8ff           call 0x401630
// 009723c0  83c408               add esp, 8
// 009723c3  e8a873cdff           call 0x649770
// 009723c8  890424               mov dword ptr [esp], eax
// 009723cb  8d0424               lea eax, [esp]
// 009723ce  50                   push eax
// 009723cf  e8acf5a8ff           call 0x401980
// 009723d4  8bc8                 mov ecx, eax
// 009723d6  e84531adff           call 0x445520
// 009723db  c700682bb300         mov dword ptr [eax], 0xb32b68
// 009723e1  68b0399800           push 0x9839b0
// 009723e6  c705ccfcb8009a020000 mov dword ptr [0xb8fccc], 0x29a
// 009723f0  e83425e8ff           call 0x7f4929
// 009723f5  83c408               add esp, 8
// 009723f8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86090;
extern int global_b8fccc;
extern ICreator creator_b32b68;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649bf0();
const Name &doDeclare();
void destroy_9839b0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b86090, &callDoDeclare_649bf0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32b68;
    global_b8fccc = 0x29a;
    atexit(&destroy_9839b0);
}
