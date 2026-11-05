// from server: 100% by nuck16
// roc 2009-12 00969950  unit: seg_00960000  size: 73 bytes
//
// 00969950  51                   push ecx
// 00969951  68102d4600           push 0x462d10
// 00969956  68c0b9b700           push 0xb7b9c0
// 0096995b  e8d07ca9ff           call 0x401630
// 00969960  83c408               add esp, 8
// 00969963  e82883afff           call 0x461c90
// 00969968  890424               mov dword ptr [esp], eax
// 0096996b  8d0424               lea eax, [esp]
// 0096996e  50                   push eax
// 0096996f  e80c80a9ff           call 0x401980
// 00969974  8bc8                 mov ecx, eax
// 00969976  e8a5bbadff           call 0x445520
// 0096997b  c700c8b4b000         mov dword ptr [eax], 0xb0b4c8
// 00969981  6890ec9700           push 0x97ec90
// 00969986  c705f0bab7009a020000 mov dword ptr [0xb7baf0], 0x29a
// 00969990  e894afe8ff           call 0x7f4929
// 00969995  83c408               add esp, 8
// 00969998  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7b9c0;
extern int global_b7baf0;
extern ICreator creator_b0b4c8;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_462d10();
const Name &doDeclare();
void destroy_97ec90();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7b9c0, &callDoDeclare_462d10);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b0b4c8;
    global_b7baf0 = 0x29a;
    atexit(&destroy_97ec90);
}
