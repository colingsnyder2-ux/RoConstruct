// from server: 100% by nuck16
// roc 2009-12 00968750  unit: seg_00960000  size: 73 bytes
//
// 00968750  51                   push ecx
// 00968751  6800364300           push 0x433600
// 00968756  686ca3b700           push 0xb7a36c
// 0096875b  e8d08ea9ff           call 0x401630
// 00968760  83c408               add esp, 8
// 00968763  e838a7acff           call 0x432ea0
// 00968768  890424               mov dword ptr [esp], eax
// 0096876b  8d0424               lea eax, [esp]
// 0096876e  50                   push eax
// 0096876f  e80c92a9ff           call 0x401980
// 00968774  8bc8                 mov ecx, eax
// 00968776  e8a5cdadff           call 0x445520
// 0096877b  c700a86bb000         mov dword ptr [eax], 0xb06ba8
// 00968781  68e0df9700           push 0x97dfe0
// 00968786  c7057ca3b7009a020000 mov dword ptr [0xb7a37c], 0x29a
// 00968790  e894c1e8ff           call 0x7f4929
// 00968795  83c408               add esp, 8
// 00968798  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7a36c;
extern int global_b7a37c;
extern ICreator creator_b06ba8;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_433600();
const Name &doDeclare();
void destroy_97dfe0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7a36c, &callDoDeclare_433600);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b06ba8;
    global_b7a37c = 0x29a;
    atexit(&destroy_97dfe0);
}
