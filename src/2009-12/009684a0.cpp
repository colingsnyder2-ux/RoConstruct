// from server: 100% by nuck16
// roc 2009-12 009684a0  unit: seg_00960000  size: 73 bytes
//
// 009684a0  51                   push ecx
// 009684a1  68e0774100           push 0x4177e0
// 009684a6  68c4a1b700           push 0xb7a1c4
// 009684ab  e88091a9ff           call 0x401630
// 009684b0  83c408               add esp, 8
// 009684b3  e8b8f1aaff           call 0x417670
// 009684b8  890424               mov dword ptr [esp], eax
// 009684bb  8d0424               lea eax, [esp]
// 009684be  50                   push eax
// 009684bf  e8bc94a9ff           call 0x401980
// 009684c4  8bc8                 mov ecx, eax
// 009684c6  e855d0adff           call 0x445520
// 009684cb  c7002039b000         mov dword ptr [eax], 0xb03920
// 009684d1  68f0dc9700           push 0x97dcf0
// 009684d6  c705d8a1b7009a020000 mov dword ptr [0xb7a1d8], 0x29a
// 009684e0  e844c4e8ff           call 0x7f4929
// 009684e5  83c408               add esp, 8
// 009684e8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7a1c4;
extern int global_b7a1d8;
extern ICreator creator_b03920;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4177e0();
const Name &doDeclare();
void destroy_97dcf0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7a1c4, &callDoDeclare_4177e0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b03920;
    global_b7a1d8 = 0x29a;
    atexit(&destroy_97dcf0);
}
