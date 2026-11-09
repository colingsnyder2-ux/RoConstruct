// from server: 100% by nuck16
// roc 2009-12 00971aa0  unit: seg_00970000  size: 73 bytes
//
// 00971aa0  51                   push ecx
// 00971aa1  68209a6400           push 0x649a20
// 00971aa6  681c60b800           push 0xb8601c
// 00971aab  e880fba8ff           call 0x401630
// 00971ab0  83c408               add esp, 8
// 00971ab3  e80870cdff           call 0x648ac0
// 00971ab8  890424               mov dword ptr [esp], eax
// 00971abb  8d0424               lea eax, [esp]
// 00971abe  50                   push eax
// 00971abf  e8bcfea8ff           call 0x401980
// 00971ac4  8bc8                 mov ecx, eax
// 00971ac6  e8553aadff           call 0x445520
// 00971acb  c700f42ab300         mov dword ptr [eax], 0xb32af4
// 00971ad1  68f0409800           push 0x9840f0
// 00971ad6  c70548fcb8009a020000 mov dword ptr [0xb8fc48], 0x29a
// 00971ae0  e8442ee8ff           call 0x7f4929
// 00971ae5  83c408               add esp, 8
// 00971ae8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b8601c;
extern int global_b8fc48;
extern ICreator creator_b32af4;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649a20();
const Name &doDeclare();
void destroy_9840f0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b8601c, &callDoDeclare_649a20);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32af4;
    global_b8fc48 = 0x29a;
    atexit(&destroy_9840f0);
}
