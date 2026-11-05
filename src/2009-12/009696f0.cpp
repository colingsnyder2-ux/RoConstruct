// from server: 100% by nuck16
// roc 2009-12 009696f0  unit: seg_00960000  size: 73 bytes
//
// 009696f0  51                   push ecx
// 009696f1  6820cd4400           push 0x44cd20
// 009696f6  6894b4b700           push 0xb7b494
// 009696fb  e8307fa9ff           call 0x401630
// 00969700  83c408               add esp, 8
// 00969703  e80826aeff           call 0x44bd10
// 00969708  890424               mov dword ptr [esp], eax
// 0096970b  8d0424               lea eax, [esp]
// 0096970e  50                   push eax
// 0096970f  e86c82a9ff           call 0x401980
// 00969714  8bc8                 mov ecx, eax
// 00969716  e805beadff           call 0x445520
// 0096971b  c700ec94b000         mov dword ptr [eax], 0xb094ec
// 00969721  6860e99700           push 0x97e960
// 00969726  c70518b6b7009a020000 mov dword ptr [0xb7b618], 0x29a
// 00969730  e8f4b1e8ff           call 0x7f4929
// 00969735  83c408               add esp, 8
// 00969738  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7b494;
extern int global_b7b618;
extern ICreator creator_b094ec;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_44cd20();
const Name &doDeclare();
void destroy_97e960();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7b494, &callDoDeclare_44cd20);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b094ec;
    global_b7b618 = 0x29a;
    atexit(&destroy_97e960);
}
