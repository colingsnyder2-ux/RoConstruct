// from server: 100% by nuck16
// roc 2009-12 009681d0  unit: seg_00960000  size: 73 bytes
//
// 009681d0  51                   push ecx
// 009681d1  6880954000           push 0x409580
// 009681d6  681496b700           push 0xb79614
// 009681db  e85094a9ff           call 0x401630
// 009681e0  83c408               add esp, 8
// 009681e3  e8f80faaff           call 0x4091e0
// 009681e8  890424               mov dword ptr [esp], eax
// 009681eb  8d0424               lea eax, [esp]
// 009681ee  50                   push eax
// 009681ef  e88c97a9ff           call 0x401980
// 009681f4  8bc8                 mov ecx, eax
// 009681f6  e825d3adff           call 0x445520
// 009681fb  c700581db000         mov dword ptr [eax], 0xb01d58
// 00968201  68c0d99700           push 0x97d9c0
// 00968206  c7053c9eb7009a020000 mov dword ptr [0xb79e3c], 0x29a
// 00968210  e814c7e8ff           call 0x7f4929
// 00968215  83c408               add esp, 8
// 00968218  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b79614;
extern int global_b79e3c;
extern ICreator creator_b01d58;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_409580();
const Name &doDeclare();
void destroy_97d9c0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b79614, &callDoDeclare_409580);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b01d58;
    global_b79e3c = 0x29a;
    atexit(&destroy_97d9c0);
}
