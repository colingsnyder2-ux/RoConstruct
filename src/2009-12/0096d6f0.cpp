// from server: 100% by nuck16
// roc 2009-12 0096d6f0  unit: seg_00960000  size: 73 bytes
//
// 0096d6f0  51                   push ecx
// 0096d6f1  68c0885300           push 0x5388c0
// 0096d6f6  68d005b800           push 0xb805d0
// 0096d6fb  e8303fa9ff           call 0x401630
// 0096d700  83c408               add esp, 8
// 0096d703  e808a1bcff           call 0x537810
// 0096d708  890424               mov dword ptr [esp], eax
// 0096d70b  8d0424               lea eax, [esp]
// 0096d70e  50                   push eax
// 0096d70f  e86c42a9ff           call 0x401980
// 0096d714  8bc8                 mov ecx, eax
// 0096d716  e8057eadff           call 0x445520
// 0096d71b  c70028f6b100         mov dword ptr [eax], 0xb1f628
// 0096d721  6890089800           push 0x980890
// 0096d726  c705fc05b8009a020000 mov dword ptr [0xb805fc], 0x29a
// 0096d730  e8f471e8ff           call 0x7f4929
// 0096d735  83c408               add esp, 8
// 0096d738  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b805d0;
extern int global_b805fc;
extern ICreator creator_b1f628;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_5388c0();
const Name &doDeclare();
void destroy_980890();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b805d0, &callDoDeclare_5388c0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b1f628;
    global_b805fc = 0x29a;
    atexit(&destroy_980890);
}
