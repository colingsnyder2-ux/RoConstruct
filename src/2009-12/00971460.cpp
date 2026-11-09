// from server: 100% by nuck16
// roc 2009-12 00971460  unit: seg_00970000  size: 73 bytes
//
// 00971460  51                   push ecx
// 00971461  68e0986400           push 0x6498e0
// 00971466  68cc5fb800           push 0xb85fcc
// 0097146b  e8c001a9ff           call 0x401630
// 00971470  83c408               add esp, 8
// 00971473  e8886dcdff           call 0x648200
// 00971478  890424               mov dword ptr [esp], eax
// 0097147b  8d0424               lea eax, [esp]
// 0097147e  50                   push eax
// 0097147f  e8fc04a9ff           call 0x401980
// 00971484  8bc8                 mov ecx, eax
// 00971486  e89540adff           call 0x445520
// 0097148b  c700a42ab300         mov dword ptr [eax], 0xb32aa4
// 00971491  68f0459800           push 0x9845f0
// 00971496  c705f8fbb8009a020000 mov dword ptr [0xb8fbf8], 0x29a
// 009714a0  e88434e8ff           call 0x7f4929
// 009714a5  83c408               add esp, 8
// 009714a8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b85fcc;
extern int global_b8fbf8;
extern ICreator creator_b32aa4;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_6498e0();
const Name &doDeclare();
void destroy_9845f0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b85fcc, &callDoDeclare_6498e0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32aa4;
    global_b8fbf8 = 0x29a;
    atexit(&destroy_9845f0);
}
