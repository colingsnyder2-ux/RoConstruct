// from server: 100% by nuck16
// roc 2009-12 00971f00  unit: seg_00970000  size: 73 bytes
//
// 00971f00  51                   push ecx
// 00971f01  68009b6400           push 0x649b00
// 00971f06  685460b800           push 0xb86054
// 00971f0b  e820f7a8ff           call 0x401630
// 00971f10  83c408               add esp, 8
// 00971f13  e8c871cdff           call 0x6490e0
// 00971f18  890424               mov dword ptr [esp], eax
// 00971f1b  8d0424               lea eax, [esp]
// 00971f1e  50                   push eax
// 00971f1f  e85cfaa8ff           call 0x401980
// 00971f24  8bc8                 mov ecx, eax
// 00971f26  e8f535adff           call 0x445520
// 00971f2b  c7002c2bb300         mov dword ptr [eax], 0xb32b2c
// 00971f31  68703d9800           push 0x983d70
// 00971f36  c70590fcb8009a020000 mov dword ptr [0xb8fc90], 0x29a
// 00971f40  e8e429e8ff           call 0x7f4929
// 00971f45  83c408               add esp, 8
// 00971f48  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86054;
extern int global_b8fc90;
extern ICreator creator_b32b2c;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649b00();
const Name &doDeclare();
void destroy_983d70();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b86054, &callDoDeclare_649b00);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32b2c;
    global_b8fc90 = 0x29a;
    atexit(&destroy_983d70);
}
