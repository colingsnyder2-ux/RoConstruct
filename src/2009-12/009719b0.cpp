// from server: 100% by nuck16
// roc 2009-12 009719b0  unit: seg_00970000  size: 73 bytes
//
// 009719b0  51                   push ecx
// 009719b1  68f0996400           push 0x6499f0
// 009719b6  681060b800           push 0xb86010
// 009719bb  e870fca8ff           call 0x401630
// 009719c0  83c408               add esp, 8
// 009719c3  e8a86fcdff           call 0x648970
// 009719c8  890424               mov dword ptr [esp], eax
// 009719cb  8d0424               lea eax, [esp]
// 009719ce  50                   push eax
// 009719cf  e8acffa8ff           call 0x401980
// 009719d4  8bc8                 mov ecx, eax
// 009719d6  e8453badff           call 0x445520
// 009719db  c700e82ab300         mov dword ptr [eax], 0xb32ae8
// 009719e1  68b0419800           push 0x9841b0
// 009719e6  c7053cfcb8009a020000 mov dword ptr [0xb8fc3c], 0x29a
// 009719f0  e8342fe8ff           call 0x7f4929
// 009719f5  83c408               add esp, 8
// 009719f8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86010;
extern int global_b8fc3c;
extern ICreator creator_b32ae8;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_6499f0();
const Name &doDeclare();
void destroy_9841b0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b86010, &callDoDeclare_6499f0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32ae8;
    global_b8fc3c = 0x29a;
    atexit(&destroy_9841b0);
}
