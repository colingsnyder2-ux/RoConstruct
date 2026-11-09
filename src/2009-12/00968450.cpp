// from server: 100% by nuck16
// roc 2009-12 00968450  unit: seg_00960000  size: 73 bytes
//
// 00968450  51                   push ecx
// 00968451  68d0774100           push 0x4177d0
// 00968456  68c0a1b700           push 0xb7a1c0
// 0096845b  e8d091a9ff           call 0x401630
// 00968460  83c408               add esp, 8
// 00968463  e898f1aaff           call 0x417600
// 00968468  890424               mov dword ptr [esp], eax
// 0096846b  8d0424               lea eax, [esp]
// 0096846e  50                   push eax
// 0096846f  e80c95a9ff           call 0x401980
// 00968474  8bc8                 mov ecx, eax
// 00968476  e8a5d0adff           call 0x445520
// 0096847b  c7001c39b000         mov dword ptr [eax], 0xb0391c
// 00968481  6830dd9700           push 0x97dd30
// 00968486  c705d4a1b7009a020000 mov dword ptr [0xb7a1d4], 0x29a
// 00968490  e894c4e8ff           call 0x7f4929
// 00968495  83c408               add esp, 8
// 00968498  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7a1c0;
extern int global_b7a1d4;
extern ICreator creator_b0391c;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4177d0();
const Name &doDeclare();
void destroy_97dd30();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7a1c0, &callDoDeclare_4177d0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b0391c;
    global_b7a1d4 = 0x29a;
    atexit(&destroy_97dd30);
}
