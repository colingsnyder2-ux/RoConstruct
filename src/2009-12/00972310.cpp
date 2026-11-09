// from server: 100% by nuck16
// roc 2009-12 00972310  unit: seg_00970000  size: 73 bytes
//
// 00972310  51                   push ecx
// 00972311  68d09b6400           push 0x649bd0
// 00972316  688860b800           push 0xb86088
// 0097231b  e810f3a8ff           call 0x401630
// 00972320  83c408               add esp, 8
// 00972323  e86873cdff           call 0x649690
// 00972328  890424               mov dword ptr [esp], eax
// 0097232b  8d0424               lea eax, [esp]
// 0097232e  50                   push eax
// 0097232f  e84cf6a8ff           call 0x401980
// 00972334  8bc8                 mov ecx, eax
// 00972336  e8e531adff           call 0x445520
// 0097233b  c700602bb300         mov dword ptr [eax], 0xb32b60
// 00972341  68303a9800           push 0x983a30
// 00972346  c705c4fcb8009a020000 mov dword ptr [0xb8fcc4], 0x29a
// 00972350  e8d425e8ff           call 0x7f4929
// 00972355  83c408               add esp, 8
// 00972358  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86088;
extern int global_b8fcc4;
extern ICreator creator_b32b60;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649bd0();
const Name &doDeclare();
void destroy_983a30();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b86088, &callDoDeclare_649bd0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32b60;
    global_b8fcc4 = 0x29a;
    atexit(&destroy_983a30);
}
