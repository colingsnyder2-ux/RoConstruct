// from server: 100% by nuck16
// roc 2009-12 00968840  unit: seg_00960000  size: 73 bytes
//
// 00968840  51                   push ecx
// 00968841  6830364300           push 0x433630
// 00968846  6878a3b700           push 0xb7a378
// 0096884b  e8e08da9ff           call 0x401630
// 00968850  83c408               add esp, 8
// 00968853  e898a7acff           call 0x432ff0
// 00968858  890424               mov dword ptr [esp], eax
// 0096885b  8d0424               lea eax, [esp]
// 0096885e  50                   push eax
// 0096885f  e81c91a9ff           call 0x401980
// 00968864  8bc8                 mov ecx, eax
// 00968866  e8b5ccadff           call 0x445520
// 0096886b  c700b46bb000         mov dword ptr [eax], 0xb06bb4
// 00968871  6820df9700           push 0x97df20
// 00968876  c70588a3b7009a020000 mov dword ptr [0xb7a388], 0x29a
// 00968880  e8a4c0e8ff           call 0x7f4929
// 00968885  83c408               add esp, 8
// 00968888  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7a378;
extern int global_b7a388;
extern ICreator creator_b06bb4;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_433630();
const Name &doDeclare();
void destroy_97df20();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7a378, &callDoDeclare_433630);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b06bb4;
    global_b7a388 = 0x29a;
    atexit(&destroy_97df20);
}
