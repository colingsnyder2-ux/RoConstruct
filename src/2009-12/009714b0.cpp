// from server: 100% by nuck16
// roc 2009-12 009714b0  unit: seg_00970000  size: 73 bytes
//
// 009714b0  51                   push ecx
// 009714b1  68f0986400           push 0x6498f0
// 009714b6  68d05fb800           push 0xb85fd0
// 009714bb  e87001a9ff           call 0x401630
// 009714c0  83c408               add esp, 8
// 009714c3  e8a86dcdff           call 0x648270
// 009714c8  890424               mov dword ptr [esp], eax
// 009714cb  8d0424               lea eax, [esp]
// 009714ce  50                   push eax
// 009714cf  e8ac04a9ff           call 0x401980
// 009714d4  8bc8                 mov ecx, eax
// 009714d6  e84540adff           call 0x445520
// 009714db  c700a82ab300         mov dword ptr [eax], 0xb32aa8
// 009714e1  68b0459800           push 0x9845b0
// 009714e6  c705fcfbb8009a020000 mov dword ptr [0xb8fbfc], 0x29a
// 009714f0  e83434e8ff           call 0x7f4929
// 009714f5  83c408               add esp, 8
// 009714f8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b85fd0;
extern int global_b8fbfc;
extern ICreator creator_b32aa8;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_6498f0();
const Name &doDeclare();
void destroy_9845b0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b85fd0, &callDoDeclare_6498f0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32aa8;
    global_b8fbfc = 0x29a;
    atexit(&destroy_9845b0);
}
