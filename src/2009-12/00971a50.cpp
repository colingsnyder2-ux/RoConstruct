// from server: 100% by nuck16
// roc 2009-12 00971a50  unit: seg_00970000  size: 73 bytes
//
// 00971a50  51                   push ecx
// 00971a51  68109a6400           push 0x649a10
// 00971a56  681860b800           push 0xb86018
// 00971a5b  e8d0fba8ff           call 0x401630
// 00971a60  83c408               add esp, 8
// 00971a63  e8e86fcdff           call 0x648a50
// 00971a68  890424               mov dword ptr [esp], eax
// 00971a6b  8d0424               lea eax, [esp]
// 00971a6e  50                   push eax
// 00971a6f  e80cffa8ff           call 0x401980
// 00971a74  8bc8                 mov ecx, eax
// 00971a76  e8a53aadff           call 0x445520
// 00971a7b  c700f02ab300         mov dword ptr [eax], 0xb32af0
// 00971a81  6830419800           push 0x984130
// 00971a86  c70544fcb8009a020000 mov dword ptr [0xb8fc44], 0x29a
// 00971a90  e8942ee8ff           call 0x7f4929
// 00971a95  83c408               add esp, 8
// 00971a98  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86018;
extern int global_b8fc44;
extern ICreator creator_b32af0;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649a10();
const Name &doDeclare();
void destroy_984130();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b86018, &callDoDeclare_649a10);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32af0;
    global_b8fc44 = 0x29a;
    atexit(&destroy_984130);
}
