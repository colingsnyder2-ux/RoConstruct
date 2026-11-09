// from server: 100% by nuck16
// roc 2009-12 00971820  unit: seg_00970000  size: 73 bytes
//
// 00971820  51                   push ecx
// 00971821  68a0996400           push 0x6499a0
// 00971826  68fc5fb800           push 0xb85ffc
// 0097182b  e800fea8ff           call 0x401630
// 00971830  83c408               add esp, 8
// 00971833  e8086fcdff           call 0x648740
// 00971838  890424               mov dword ptr [esp], eax
// 0097183b  8d0424               lea eax, [esp]
// 0097183e  50                   push eax
// 0097183f  e83c01a9ff           call 0x401980
// 00971844  8bc8                 mov ecx, eax
// 00971846  e8d53cadff           call 0x445520
// 0097184b  c700d42ab300         mov dword ptr [eax], 0xb32ad4
// 00971851  68f0429800           push 0x9842f0
// 00971856  c70528fcb8009a020000 mov dword ptr [0xb8fc28], 0x29a
// 00971860  e8c430e8ff           call 0x7f4929
// 00971865  83c408               add esp, 8
// 00971868  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b85ffc;
extern int global_b8fc28;
extern ICreator creator_b32ad4;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_6499a0();
const Name &doDeclare();
void destroy_9842f0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b85ffc, &callDoDeclare_6499a0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32ad4;
    global_b8fc28 = 0x29a;
    atexit(&destroy_9842f0);
}
