// from server: 100% by nuck16
// roc 2009-12 00971e60  unit: seg_00970000  size: 73 bytes
//
// 00971e60  51                   push ecx
// 00971e61  68e09a6400           push 0x649ae0
// 00971e66  684c60b800           push 0xb8604c
// 00971e6b  e8c0f7a8ff           call 0x401630
// 00971e70  83c408               add esp, 8
// 00971e73  e88871cdff           call 0x649000
// 00971e78  890424               mov dword ptr [esp], eax
// 00971e7b  8d0424               lea eax, [esp]
// 00971e7e  50                   push eax
// 00971e7f  e8fcfaa8ff           call 0x401980
// 00971e84  8bc8                 mov ecx, eax
// 00971e86  e89536adff           call 0x445520
// 00971e8b  c700242bb300         mov dword ptr [eax], 0xb32b24
// 00971e91  68f03d9800           push 0x983df0
// 00971e96  c70588fcb8009a020000 mov dword ptr [0xb8fc88], 0x29a
// 00971ea0  e8842ae8ff           call 0x7f4929
// 00971ea5  83c408               add esp, 8
// 00971ea8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b8604c;
extern int global_b8fc88;
extern ICreator creator_b32b24;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649ae0();
const Name &doDeclare();
void destroy_983df0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b8604c, &callDoDeclare_649ae0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32b24;
    global_b8fc88 = 0x29a;
    atexit(&destroy_983df0);
}
