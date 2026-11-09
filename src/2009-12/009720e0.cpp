// from server: 100% by nuck16
// roc 2009-12 009720e0  unit: seg_00970000  size: 73 bytes
//
// 009720e0  51                   push ecx
// 009720e1  68609b6400           push 0x649b60
// 009720e6  686c60b800           push 0xb8606c
// 009720eb  e840f5a8ff           call 0x401630
// 009720f0  83c408               add esp, 8
// 009720f3  e88872cdff           call 0x649380
// 009720f8  890424               mov dword ptr [esp], eax
// 009720fb  8d0424               lea eax, [esp]
// 009720fe  50                   push eax
// 009720ff  e87cf8a8ff           call 0x401980
// 00972104  8bc8                 mov ecx, eax
// 00972106  e81534adff           call 0x445520
// 0097210b  c700442bb300         mov dword ptr [eax], 0xb32b44
// 00972111  68f03b9800           push 0x983bf0
// 00972116  c705a8fcb8009a020000 mov dword ptr [0xb8fca8], 0x29a
// 00972120  e80428e8ff           call 0x7f4929
// 00972125  83c408               add esp, 8
// 00972128  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b8606c;
extern int global_b8fca8;
extern ICreator creator_b32b44;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649b60();
const Name &doDeclare();
void destroy_983bf0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b8606c, &callDoDeclare_649b60);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32b44;
    global_b8fca8 = 0x29a;
    atexit(&destroy_983bf0);
}
