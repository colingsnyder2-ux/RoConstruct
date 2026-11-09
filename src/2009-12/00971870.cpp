// from server: 100% by nuck16
// roc 2009-12 00971870  unit: seg_00970000  size: 73 bytes
//
// 00971870  51                   push ecx
// 00971871  68b0996400           push 0x6499b0
// 00971876  680060b800           push 0xb86000
// 0097187b  e8b0fda8ff           call 0x401630
// 00971880  83c408               add esp, 8
// 00971883  e8286fcdff           call 0x6487b0
// 00971888  890424               mov dword ptr [esp], eax
// 0097188b  8d0424               lea eax, [esp]
// 0097188e  50                   push eax
// 0097188f  e8ec00a9ff           call 0x401980
// 00971894  8bc8                 mov ecx, eax
// 00971896  e8853cadff           call 0x445520
// 0097189b  c700d82ab300         mov dword ptr [eax], 0xb32ad8
// 009718a1  68b0429800           push 0x9842b0
// 009718a6  c7052cfcb8009a020000 mov dword ptr [0xb8fc2c], 0x29a
// 009718b0  e87430e8ff           call 0x7f4929
// 009718b5  83c408               add esp, 8
// 009718b8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86000;
extern int global_b8fc2c;
extern ICreator creator_b32ad8;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_6499b0();
const Name &doDeclare();
void destroy_9842b0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b86000, &callDoDeclare_6499b0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32ad8;
    global_b8fc2c = 0x29a;
    atexit(&destroy_9842b0);
}
