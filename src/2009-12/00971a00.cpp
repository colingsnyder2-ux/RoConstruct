// from server: 100% by nuck16
// roc 2009-12 00971a00  unit: seg_00970000  size: 73 bytes
//
// 00971a00  51                   push ecx
// 00971a01  68009a6400           push 0x649a00
// 00971a06  681460b800           push 0xb86014
// 00971a0b  e820fca8ff           call 0x401630
// 00971a10  83c408               add esp, 8
// 00971a13  e8c86fcdff           call 0x6489e0
// 00971a18  890424               mov dword ptr [esp], eax
// 00971a1b  8d0424               lea eax, [esp]
// 00971a1e  50                   push eax
// 00971a1f  e85cffa8ff           call 0x401980
// 00971a24  8bc8                 mov ecx, eax
// 00971a26  e8f53aadff           call 0x445520
// 00971a2b  c700ec2ab300         mov dword ptr [eax], 0xb32aec
// 00971a31  6870419800           push 0x984170
// 00971a36  c70540fcb8009a020000 mov dword ptr [0xb8fc40], 0x29a
// 00971a40  e8e42ee8ff           call 0x7f4929
// 00971a45  83c408               add esp, 8
// 00971a48  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86014;
extern int global_b8fc40;
extern ICreator creator_b32aec;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649a00();
const Name &doDeclare();
void destroy_984170();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b86014, &callDoDeclare_649a00);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32aec;
    global_b8fc40 = 0x29a;
    atexit(&destroy_984170);
}
