// from server: 100% by nuck16
// roc 2009-12 00972360  unit: seg_00970000  size: 73 bytes
//
// 00972360  51                   push ecx
// 00972361  68e09b6400           push 0x649be0
// 00972366  688c60b800           push 0xb8608c
// 0097236b  e8c0f2a8ff           call 0x401630
// 00972370  83c408               add esp, 8
// 00972373  e88873cdff           call 0x649700
// 00972378  890424               mov dword ptr [esp], eax
// 0097237b  8d0424               lea eax, [esp]
// 0097237e  50                   push eax
// 0097237f  e8fcf5a8ff           call 0x401980
// 00972384  8bc8                 mov ecx, eax
// 00972386  e89531adff           call 0x445520
// 0097238b  c700642bb300         mov dword ptr [eax], 0xb32b64
// 00972391  68f0399800           push 0x9839f0
// 00972396  c705c8fcb8009a020000 mov dword ptr [0xb8fcc8], 0x29a
// 009723a0  e88425e8ff           call 0x7f4929
// 009723a5  83c408               add esp, 8
// 009723a8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b8608c;
extern int global_b8fcc8;
extern ICreator creator_b32b64;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649be0();
const Name &doDeclare();
void destroy_9839f0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b8608c, &callDoDeclare_649be0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32b64;
    global_b8fcc8 = 0x29a;
    atexit(&destroy_9839f0);
}
