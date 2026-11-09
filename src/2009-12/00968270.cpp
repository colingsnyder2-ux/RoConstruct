// from server: 100% by nuck16
// roc 2009-12 00968270  unit: seg_00960000  size: 73 bytes
//
// 00968270  51                   push ecx
// 00968271  68a0954000           push 0x4095a0
// 00968276  681c96b700           push 0xb7961c
// 0096827b  e8b093a9ff           call 0x401630
// 00968280  83c408               add esp, 8
// 00968283  e83810aaff           call 0x4092c0
// 00968288  890424               mov dword ptr [esp], eax
// 0096828b  8d0424               lea eax, [esp]
// 0096828e  50                   push eax
// 0096828f  e8ec96a9ff           call 0x401980
// 00968294  8bc8                 mov ecx, eax
// 00968296  e885d2adff           call 0x445520
// 0096829b  c700601db000         mov dword ptr [eax], 0xb01d60
// 009682a1  6840d99700           push 0x97d940
// 009682a6  c7053ca0b7009a020000 mov dword ptr [0xb7a03c], 0x29a
// 009682b0  e874c6e8ff           call 0x7f4929
// 009682b5  83c408               add esp, 8
// 009682b8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7961c;
extern int global_b7a03c;
extern ICreator creator_b01d60;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4095a0();
const Name &doDeclare();
void destroy_97d940();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7961c, &callDoDeclare_4095a0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b01d60;
    global_b7a03c = 0x29a;
    atexit(&destroy_97d940);
}
