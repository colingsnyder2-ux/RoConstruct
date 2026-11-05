// from server: 100% by nuck16
// roc 2009-12 00969900  unit: seg_00960000  size: 73 bytes
//
// 00969900  51                   push ecx
// 00969901  68002d4600           push 0x462d00
// 00969906  68bcb9b700           push 0xb7b9bc
// 0096990b  e8207da9ff           call 0x401630
// 00969910  83c408               add esp, 8
// 00969913  e80883afff           call 0x461c20
// 00969918  890424               mov dword ptr [esp], eax
// 0096991b  8d0424               lea eax, [esp]
// 0096991e  50                   push eax
// 0096991f  e85c80a9ff           call 0x401980
// 00969924  8bc8                 mov ecx, eax
// 00969926  e8f5bbadff           call 0x445520
// 0096992b  c700c4b4b000         mov dword ptr [eax], 0xb0b4c4
// 00969931  68d0ec9700           push 0x97ecd0
// 00969936  c705ecbab7009a020000 mov dword ptr [0xb7baec], 0x29a
// 00969940  e8e4afe8ff           call 0x7f4929
// 00969945  83c408               add esp, 8
// 00969948  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7b9bc;
extern int global_b7baec;
extern ICreator creator_b0b4c4;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_462d00();
const Name &doDeclare();
void destroy_97ecd0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7b9bc, &callDoDeclare_462d00);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b0b4c4;
    global_b7baec = 0x29a;
    atexit(&destroy_97ecd0);
}
