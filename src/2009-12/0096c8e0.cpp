// from server: 100% by nuck16
// roc 2009-12 0096c8e0  unit: seg_00960000  size: 73 bytes
//
// 0096c8e0  51                   push ecx
// 0096c8e1  68203a5100           push 0x513a20
// 0096c8e6  6830e9b700           push 0xb7e930
// 0096c8eb  e8404da9ff           call 0x401630
// 0096c8f0  83c408               add esp, 8
// 0096c8f3  e84862baff           call 0x512b40
// 0096c8f8  890424               mov dword ptr [esp], eax
// 0096c8fb  8d0424               lea eax, [esp]
// 0096c8fe  50                   push eax
// 0096c8ff  e87c50a9ff           call 0x401980
// 0096c904  8bc8                 mov ecx, eax
// 0096c906  e8158cadff           call 0x445520
// 0096c90b  c700649db100         mov dword ptr [eax], 0xb19d64
// 0096c911  6800fd9700           push 0x97fd00
// 0096c916  c70568eab7009a020000 mov dword ptr [0xb7ea68], 0x29a
// 0096c920  e80480e8ff           call 0x7f4929
// 0096c925  83c408               add esp, 8
// 0096c928  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7e930;
extern int global_b7ea68;
extern ICreator creator_b19d64;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_513a20();
const Name &doDeclare();
void destroy_97fd00();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7e930, &callDoDeclare_513a20);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b19d64;
    global_b7ea68 = 0x29a;
    atexit(&destroy_97fd00);
}
