// from server: 100% by nuck16
// roc 2009-12 0096d880  unit: seg_00960000  size: 73 bytes
//
// 0096d880  51                   push ecx
// 0096d881  6810895300           push 0x538910
// 0096d886  68e405b800           push 0xb805e4
// 0096d88b  e8a03da9ff           call 0x401630
// 0096d890  83c408               add esp, 8
// 0096d893  e8a8a1bcff           call 0x537a40
// 0096d898  890424               mov dword ptr [esp], eax
// 0096d89b  8d0424               lea eax, [esp]
// 0096d89e  50                   push eax
// 0096d89f  e8dc40a9ff           call 0x401980
// 0096d8a4  8bc8                 mov ecx, eax
// 0096d8a6  e8757cadff           call 0x445520
// 0096d8ab  c7003cf6b100         mov dword ptr [eax], 0xb1f63c
// 0096d8b1  6850079800           push 0x980750
// 0096d8b6  c7051006b8009a020000 mov dword ptr [0xb80610], 0x29a
// 0096d8c0  e86470e8ff           call 0x7f4929
// 0096d8c5  83c408               add esp, 8
// 0096d8c8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b805e4;
extern int global_b80610;
extern ICreator creator_b1f63c;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_538910();
const Name &doDeclare();
void destroy_980750();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b805e4, &callDoDeclare_538910);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b1f63c;
    global_b80610 = 0x29a;
    atexit(&destroy_980750);
}
