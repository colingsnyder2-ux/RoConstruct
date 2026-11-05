// from server: 100% by nuck16
// roc 2009-12 00968310  unit: seg_00960000  size: 73 bytes
//
// 00968310  51                   push ecx
// 00968311  68e03a4100           push 0x413ae0
// 00968316  6814a1b700           push 0xb7a114
// 0096831b  e81093a9ff           call 0x401630
// 00968320  83c408               add esp, 8
// 00968323  e808b4aaff           call 0x413730
// 00968328  890424               mov dword ptr [esp], eax
// 0096832b  8d0424               lea eax, [esp]
// 0096832e  50                   push eax
// 0096832f  e84c96a9ff           call 0x401980
// 00968334  8bc8                 mov ecx, eax
// 00968336  e8e5d1adff           call 0x445520
// 0096833b  c7009c33b000         mov dword ptr [eax], 0xb0339c
// 00968341  68c0db9700           push 0x97dbc0
// 00968346  c70530a1b7009a020000 mov dword ptr [0xb7a130], 0x29a
// 00968350  e8d4c5e8ff           call 0x7f4929
// 00968355  83c408               add esp, 8
// 00968358  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7a114;
extern int global_b7a130;
extern ICreator creator_b0339c;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_413ae0();
const Name &doDeclare();
void destroy_97dbc0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7a114, &callDoDeclare_413ae0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b0339c;
    global_b7a130 = 0x29a;
    atexit(&destroy_97dbc0);
}
