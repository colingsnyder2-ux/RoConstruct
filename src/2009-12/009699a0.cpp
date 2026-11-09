// from server: 100% by nuck16
// roc 2009-12 009699a0  unit: seg_00960000  size: 73 bytes
//
// 009699a0  51                   push ecx
// 009699a1  68202d4600           push 0x462d20
// 009699a6  68c4b9b700           push 0xb7b9c4
// 009699ab  e8807ca9ff           call 0x401630
// 009699b0  83c408               add esp, 8
// 009699b3  e84883afff           call 0x461d00
// 009699b8  890424               mov dword ptr [esp], eax
// 009699bb  8d0424               lea eax, [esp]
// 009699be  50                   push eax
// 009699bf  e8bc7fa9ff           call 0x401980
// 009699c4  8bc8                 mov ecx, eax
// 009699c6  e855bbadff           call 0x445520
// 009699cb  c700ccb4b000         mov dword ptr [eax], 0xb0b4cc
// 009699d1  6850ec9700           push 0x97ec50
// 009699d6  c705f4bab7009a020000 mov dword ptr [0xb7baf4], 0x29a
// 009699e0  e844afe8ff           call 0x7f4929
// 009699e5  83c408               add esp, 8
// 009699e8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7b9c4;
extern int global_b7baf4;
extern ICreator creator_b0b4cc;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_462d20();
const Name &doDeclare();
void destroy_97ec50();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7b9c4, &callDoDeclare_462d20);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b0b4cc;
    global_b7baf4 = 0x29a;
    atexit(&destroy_97ec50);
}
