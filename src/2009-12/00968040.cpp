// from server: 100% by nuck16
// roc 2009-12 00968040  unit: seg_00960000  size: 73 bytes
//
// 00968040  51                   push ecx
// 00968041  6830954000           push 0x409530
// 00968046  680096b700           push 0xb79600
// 0096804b  e8e095a9ff           call 0x401630
// 00968050  83c408               add esp, 8
// 00968053  e8580faaff           call 0x408fb0
// 00968058  890424               mov dword ptr [esp], eax
// 0096805b  8d0424               lea eax, [esp]
// 0096805e  50                   push eax
// 0096805f  e81c99a9ff           call 0x401980
// 00968064  8bc8                 mov ecx, eax
// 00968066  e8b5d4adff           call 0x445520
// 0096806b  c700441db000         mov dword ptr [eax], 0xb01d44
// 00968071  6800db9700           push 0x97db00
// 00968076  c7052499b7009a020000 mov dword ptr [0xb79924], 0x29a
// 00968080  e8a4c8e8ff           call 0x7f4929
// 00968085  83c408               add esp, 8
// 00968088  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b79600;
extern int global_b79924;
extern ICreator creator_b01d44;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_409530();
const Name &doDeclare();
void destroy_97db00();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b79600, &callDoDeclare_409530);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b01d44;
    global_b79924 = 0x29a;
    atexit(&destroy_97db00);
}
