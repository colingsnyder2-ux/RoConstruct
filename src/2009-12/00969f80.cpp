// from server: 100% by nuck16
// roc 2009-12 00969f80  unit: seg_00960000  size: 73 bytes
//
// 00969f80  51                   push ecx
// 00969f81  6890b44800           push 0x48b490
// 00969f86  68d8ccb700           push 0xb7ccd8
// 00969f8b  e8a076a9ff           call 0x401630
// 00969f90  83c408               add esp, 8
// 00969f93  e86814b2ff           call 0x48b400
// 00969f98  890424               mov dword ptr [esp], eax
// 00969f9b  8d0424               lea eax, [esp]
// 00969f9e  50                   push eax
// 00969f9f  e8dc79a9ff           call 0x401980
// 00969fa4  8bc8                 mov ecx, eax
// 00969fa6  e875b5adff           call 0x445520
// 00969fab  c70010c8b000         mov dword ptr [eax], 0xb0c810
// 00969fb1  68f0ed9700           push 0x97edf0
// 00969fb6  c705dcccb7009a020000 mov dword ptr [0xb7ccdc], 0x29a
// 00969fc0  e864a9e8ff           call 0x7f4929
// 00969fc5  83c408               add esp, 8
// 00969fc8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7ccd8;
extern int global_b7ccdc;
extern ICreator creator_b0c810;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_48b490();
const Name &doDeclare();
void destroy_97edf0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7ccd8, &callDoDeclare_48b490);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b0c810;
    global_b7ccdc = 0x29a;
    atexit(&destroy_97edf0);
}
