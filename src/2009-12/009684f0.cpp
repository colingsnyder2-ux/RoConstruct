// from server: 100% by nuck16
// roc 2009-12 009684f0  unit: seg_00960000  size: 73 bytes
//
// 009684f0  51                   push ecx
// 009684f1  68f0774100           push 0x4177f0
// 009684f6  68c8a1b700           push 0xb7a1c8
// 009684fb  e83091a9ff           call 0x401630
// 00968500  83c408               add esp, 8
// 00968503  e8d8f1aaff           call 0x4176e0
// 00968508  890424               mov dword ptr [esp], eax
// 0096850b  8d0424               lea eax, [esp]
// 0096850e  50                   push eax
// 0096850f  e86c94a9ff           call 0x401980
// 00968514  8bc8                 mov ecx, eax
// 00968516  e805d0adff           call 0x445520
// 0096851b  c7002439b000         mov dword ptr [eax], 0xb03924
// 00968521  68b0dc9700           push 0x97dcb0
// 00968526  c705dca1b7009a020000 mov dword ptr [0xb7a1dc], 0x29a
// 00968530  e8f4c3e8ff           call 0x7f4929
// 00968535  83c408               add esp, 8
// 00968538  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7a1c8;
extern int global_b7a1dc;
extern ICreator creator_b03924;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4177f0();
const Name &doDeclare();
void destroy_97dcb0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7a1c8, &callDoDeclare_4177f0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b03924;
    global_b7a1dc = 0x29a;
    atexit(&destroy_97dcb0);
}
