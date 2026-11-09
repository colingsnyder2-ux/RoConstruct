// from server: 100% by nuck16
// roc 2009-12 00968130  unit: seg_00960000  size: 73 bytes
//
// 00968130  51                   push ecx
// 00968131  6860954000           push 0x409560
// 00968136  680c96b700           push 0xb7960c
// 0096813b  e8f094a9ff           call 0x401630
// 00968140  83c408               add esp, 8
// 00968143  e8b80faaff           call 0x409100
// 00968148  890424               mov dword ptr [esp], eax
// 0096814b  8d0424               lea eax, [esp]
// 0096814e  50                   push eax
// 0096814f  e82c98a9ff           call 0x401980
// 00968154  8bc8                 mov ecx, eax
// 00968156  e8c5d3adff           call 0x445520
// 0096815b  c700501db000         mov dword ptr [eax], 0xb01d50
// 00968161  6840da9700           push 0x97da40
// 00968166  c7053c9cb7009a020000 mov dword ptr [0xb79c3c], 0x29a
// 00968170  e8b4c7e8ff           call 0x7f4929
// 00968175  83c408               add esp, 8
// 00968178  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7960c;
extern int global_b79c3c;
extern ICreator creator_b01d50;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_409560();
const Name &doDeclare();
void destroy_97da40();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7960c, &callDoDeclare_409560);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b01d50;
    global_b79c3c = 0x29a;
    atexit(&destroy_97da40);
}
