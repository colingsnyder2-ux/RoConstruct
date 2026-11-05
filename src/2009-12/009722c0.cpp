// from server: 100% by nuck16
// roc 2009-12 009722c0  unit: seg_00970000  size: 73 bytes
//
// 009722c0  51                   push ecx
// 009722c1  68c09b6400           push 0x649bc0
// 009722c6  688460b800           push 0xb86084
// 009722cb  e860f3a8ff           call 0x401630
// 009722d0  83c408               add esp, 8
// 009722d3  e84873cdff           call 0x649620
// 009722d8  890424               mov dword ptr [esp], eax
// 009722db  8d0424               lea eax, [esp]
// 009722de  50                   push eax
// 009722df  e89cf6a8ff           call 0x401980
// 009722e4  8bc8                 mov ecx, eax
// 009722e6  e83532adff           call 0x445520
// 009722eb  c7005c2bb300         mov dword ptr [eax], 0xb32b5c
// 009722f1  68703a9800           push 0x983a70
// 009722f6  c705c0fcb8009a020000 mov dword ptr [0xb8fcc0], 0x29a
// 00972300  e82426e8ff           call 0x7f4929
// 00972305  83c408               add esp, 8
// 00972308  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86084;
extern int global_b8fcc0;
extern ICreator creator_b32b5c;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649bc0();
const Name &doDeclare();
void destroy_983a70();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b86084, &callDoDeclare_649bc0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32b5c;
    global_b8fcc0 = 0x29a;
    atexit(&destroy_983a70);
}
