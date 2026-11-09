// from server: 100% by nuck16
// roc 2009-12 00971690  unit: seg_00970000  size: 73 bytes
//
// 00971690  51                   push ecx
// 00971691  6850996400           push 0x649950
// 00971696  68e85fb800           push 0xb85fe8
// 0097169b  e890ffa8ff           call 0x401630
// 009716a0  83c408               add esp, 8
// 009716a3  e8686ecdff           call 0x648510
// 009716a8  890424               mov dword ptr [esp], eax
// 009716ab  8d0424               lea eax, [esp]
// 009716ae  50                   push eax
// 009716af  e8cc02a9ff           call 0x401980
// 009716b4  8bc8                 mov ecx, eax
// 009716b6  e8653eadff           call 0x445520
// 009716bb  c700c02ab300         mov dword ptr [eax], 0xb32ac0
// 009716c1  6830449800           push 0x984430
// 009716c6  c70514fcb8009a020000 mov dword ptr [0xb8fc14], 0x29a
// 009716d0  e85432e8ff           call 0x7f4929
// 009716d5  83c408               add esp, 8
// 009716d8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b85fe8;
extern int global_b8fc14;
extern ICreator creator_b32ac0;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649950();
const Name &doDeclare();
void destroy_984430();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b85fe8, &callDoDeclare_649950);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32ac0;
    global_b8fc14 = 0x29a;
    atexit(&destroy_984430);
}
