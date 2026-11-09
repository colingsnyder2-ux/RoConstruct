// from server: 100% by nuck16
// roc 2009-12 0096c890  unit: seg_00960000  size: 73 bytes
//
// 0096c890  51                   push ecx
// 0096c891  68103a5100           push 0x513a10
// 0096c896  682ce9b700           push 0xb7e92c
// 0096c89b  e8904da9ff           call 0x401630
// 0096c8a0  83c408               add esp, 8
// 0096c8a3  e82862baff           call 0x512ad0
// 0096c8a8  890424               mov dword ptr [esp], eax
// 0096c8ab  8d0424               lea eax, [esp]
// 0096c8ae  50                   push eax
// 0096c8af  e8cc50a9ff           call 0x401980
// 0096c8b4  8bc8                 mov ecx, eax
// 0096c8b6  e8658cadff           call 0x445520
// 0096c8bb  c700609db100         mov dword ptr [eax], 0xb19d60
// 0096c8c1  6840fd9700           push 0x97fd40
// 0096c8c6  c70564eab7009a020000 mov dword ptr [0xb7ea64], 0x29a
// 0096c8d0  e85480e8ff           call 0x7f4929
// 0096c8d5  83c408               add esp, 8
// 0096c8d8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7e92c;
extern int global_b7ea64;
extern ICreator creator_b19d60;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_513a10();
const Name &doDeclare();
void destroy_97fd40();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7e92c, &callDoDeclare_513a10);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b19d60;
    global_b7ea64 = 0x29a;
    atexit(&destroy_97fd40);
}
