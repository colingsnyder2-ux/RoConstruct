// from server: 100% by nuck16
// roc 2009-12 0096d7e0  unit: seg_00960000  size: 73 bytes
//
// 0096d7e0  51                   push ecx
// 0096d7e1  68f0885300           push 0x5388f0
// 0096d7e6  68dc05b800           push 0xb805dc
// 0096d7eb  e8403ea9ff           call 0x401630
// 0096d7f0  83c408               add esp, 8
// 0096d7f3  e868a1bcff           call 0x537960
// 0096d7f8  890424               mov dword ptr [esp], eax
// 0096d7fb  8d0424               lea eax, [esp]
// 0096d7fe  50                   push eax
// 0096d7ff  e87c41a9ff           call 0x401980
// 0096d804  8bc8                 mov ecx, eax
// 0096d806  e8157dadff           call 0x445520
// 0096d80b  c70034f6b100         mov dword ptr [eax], 0xb1f634
// 0096d811  68d0079800           push 0x9807d0
// 0096d816  c7050806b8009a020000 mov dword ptr [0xb80608], 0x29a
// 0096d820  e80471e8ff           call 0x7f4929
// 0096d825  83c408               add esp, 8
// 0096d828  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b805dc;
extern int global_b80608;
extern ICreator creator_b1f634;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_5388f0();
const Name &doDeclare();
void destroy_9807d0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b805dc, &callDoDeclare_5388f0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b1f634;
    global_b80608 = 0x29a;
    atexit(&destroy_9807d0);
}
