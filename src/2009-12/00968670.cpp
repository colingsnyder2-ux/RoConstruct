// from server: 100% by nuck16
// roc 2009-12 00968670  unit: seg_00960000  size: 73 bytes
//
// 00968670  51                   push ecx
// 00968671  68c0a44200           push 0x42a4c0
// 00968676  68fca2b700           push 0xb7a2fc
// 0096867b  e8b08fa9ff           call 0x401630
// 00968680  83c408               add esp, 8
// 00968683  e85804acff           call 0x428ae0
// 00968688  890424               mov dword ptr [esp], eax
// 0096868b  8d0424               lea eax, [esp]
// 0096868e  50                   push eax
// 0096868f  e8ec92a9ff           call 0x401980
// 00968694  8bc8                 mov ecx, eax
// 00968696  e885ceadff           call 0x445520
// 0096869b  c7008450b000         mov dword ptr [eax], 0xb05084
// 009686a1  68d0de9700           push 0x97ded0
// 009686a6  c7050ca3b7009a020000 mov dword ptr [0xb7a30c], 0x29a
// 009686b0  e874c2e8ff           call 0x7f4929
// 009686b5  83c408               add esp, 8
// 009686b8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7a2fc;
extern int global_b7a30c;
extern ICreator creator_b05084;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_42a4c0();
const Name &doDeclare();
void destroy_97ded0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7a2fc, &callDoDeclare_42a4c0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b05084;
    global_b7a30c = 0x29a;
    atexit(&destroy_97ded0);
}
