// from server: 100% by nuck16
// roc 2009-12 00971eb0  unit: seg_00970000  size: 73 bytes
//
// 00971eb0  51                   push ecx
// 00971eb1  68f09a6400           push 0x649af0
// 00971eb6  685060b800           push 0xb86050
// 00971ebb  e870f7a8ff           call 0x401630
// 00971ec0  83c408               add esp, 8
// 00971ec3  e8a871cdff           call 0x649070
// 00971ec8  890424               mov dword ptr [esp], eax
// 00971ecb  8d0424               lea eax, [esp]
// 00971ece  50                   push eax
// 00971ecf  e8acfaa8ff           call 0x401980
// 00971ed4  8bc8                 mov ecx, eax
// 00971ed6  e84536adff           call 0x445520
// 00971edb  c700282bb300         mov dword ptr [eax], 0xb32b28
// 00971ee1  68b03d9800           push 0x983db0
// 00971ee6  c7058cfcb8009a020000 mov dword ptr [0xb8fc8c], 0x29a
// 00971ef0  e8342ae8ff           call 0x7f4929
// 00971ef5  83c408               add esp, 8
// 00971ef8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86050;
extern int global_b8fc8c;
extern ICreator creator_b32b28;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649af0();
const Name &doDeclare();
void destroy_983db0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b86050, &callDoDeclare_649af0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32b28;
    global_b8fc8c = 0x29a;
    atexit(&destroy_983db0);
}
