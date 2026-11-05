// from server: 100% by nuck16
// roc 2009-12 00968400  unit: seg_00960000  size: 73 bytes
//
// 00968400  51                   push ecx
// 00968401  68c0774100           push 0x4177c0
// 00968406  68bca1b700           push 0xb7a1bc
// 0096840b  e82092a9ff           call 0x401630
// 00968410  83c408               add esp, 8
// 00968413  e878f1aaff           call 0x417590
// 00968418  890424               mov dword ptr [esp], eax
// 0096841b  8d0424               lea eax, [esp]
// 0096841e  50                   push eax
// 0096841f  e85c95a9ff           call 0x401980
// 00968424  8bc8                 mov ecx, eax
// 00968426  e8f5d0adff           call 0x445520
// 0096842b  c7001839b000         mov dword ptr [eax], 0xb03918
// 00968431  6870dd9700           push 0x97dd70
// 00968436  c705d0a1b7009a020000 mov dword ptr [0xb7a1d0], 0x29a
// 00968440  e8e4c4e8ff           call 0x7f4929
// 00968445  83c408               add esp, 8
// 00968448  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7a1bc;
extern int global_b7a1d0;
extern ICreator creator_b03918;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4177c0();
const Name &doDeclare();
void destroy_97dd70();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7a1bc, &callDoDeclare_4177c0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b03918;
    global_b7a1d0 = 0x29a;
    atexit(&destroy_97dd70);
}
