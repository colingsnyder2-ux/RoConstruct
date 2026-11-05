// from server: 100% by nuck16
// roc 2009-12 0097db00  unit: seg_00970000  size: 55 bytes
//
// 0097db00  51                   push ecx
// 0097db01  6830954000           push 0x409530
// 0097db06  680096b700           push 0xb79600
// 0097db0b  c705441db000d4ff9900 mov dword ptr [0xb01d44], 0x99ffd4
// 0097db15  e8163ba8ff           call 0x401630
// 0097db1a  83c408               add esp, 8
// 0097db1d  e88eb4a8ff           call 0x408fb0
// 0097db22  890424               mov dword ptr [esp], eax
// 0097db25  8d0424               lea eax, [esp]
// 0097db28  50                   push eax
// 0097db29  e8523ea8ff           call 0x401980
// 0097db2e  8bc8                 mov ecx, eax
// 0097db30  e81b3da8ff           call 0x401850
// 0097db35  59                   pop ecx
// 0097db36  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b79600;
extern const int data_0099ffd4[];
extern int global_b01d44;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_409530();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b01d44 = (int)data_0099ffd4;
    call_once(flag_b79600, &callDoDeclare_409530);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
