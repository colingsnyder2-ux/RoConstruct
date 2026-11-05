// from server: 100% by nuck16
// roc 2009-12 00968360  unit: seg_00960000  size: 73 bytes
//
// 00968360  51                   push ecx
// 00968361  68f03a4100           push 0x413af0
// 00968366  6818a1b700           push 0xb7a118
// 0096836b  e8c092a9ff           call 0x401630
// 00968370  83c408               add esp, 8
// 00968373  e828b4aaff           call 0x4137a0
// 00968378  890424               mov dword ptr [esp], eax
// 0096837b  8d0424               lea eax, [esp]
// 0096837e  50                   push eax
// 0096837f  e8fc95a9ff           call 0x401980
// 00968384  8bc8                 mov ecx, eax
// 00968386  e895d1adff           call 0x445520
// 0096838b  c700a033b000         mov dword ptr [eax], 0xb033a0
// 00968391  6880db9700           push 0x97db80
// 00968396  c70534a1b7009a020000 mov dword ptr [0xb7a134], 0x29a
// 009683a0  e884c5e8ff           call 0x7f4929
// 009683a5  83c408               add esp, 8
// 009683a8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7a118;
extern int global_b7a134;
extern ICreator creator_b033a0;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_413af0();
const Name &doDeclare();
void destroy_97db80();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7a118, &callDoDeclare_413af0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b033a0;
    global_b7a134 = 0x29a;
    atexit(&destroy_97db80);
}
