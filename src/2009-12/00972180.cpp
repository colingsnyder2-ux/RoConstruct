// from server: 100% by nuck16
// roc 2009-12 00972180  unit: seg_00970000  size: 73 bytes
//
// 00972180  51                   push ecx
// 00972181  68809b6400           push 0x649b80
// 00972186  687460b800           push 0xb86074
// 0097218b  e8a0f4a8ff           call 0x401630
// 00972190  83c408               add esp, 8
// 00972193  e8c872cdff           call 0x649460
// 00972198  890424               mov dword ptr [esp], eax
// 0097219b  8d0424               lea eax, [esp]
// 0097219e  50                   push eax
// 0097219f  e8dcf7a8ff           call 0x401980
// 009721a4  8bc8                 mov ecx, eax
// 009721a6  e87533adff           call 0x445520
// 009721ab  c7004c2bb300         mov dword ptr [eax], 0xb32b4c
// 009721b1  68703b9800           push 0x983b70
// 009721b6  c705b0fcb8009a020000 mov dword ptr [0xb8fcb0], 0x29a
// 009721c0  e86427e8ff           call 0x7f4929
// 009721c5  83c408               add esp, 8
// 009721c8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86074;
extern int global_b8fcb0;
extern ICreator creator_b32b4c;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649b80();
const Name &doDeclare();
void destroy_983b70();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b86074, &callDoDeclare_649b80);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32b4c;
    global_b8fcb0 = 0x29a;
    atexit(&destroy_983b70);
}
