// from server: 100% by nuck16
// roc 2009-12 0096bfd0  unit: seg_00960000  size: 73 bytes
//
// 0096bfd0  51                   push ecx
// 0096bfd1  6870684f00           push 0x4f6870
// 0096bfd6  6850deb700           push 0xb7de50
// 0096bfdb  e85056a9ff           call 0x401630
// 0096bfe0  83c408               add esp, 8
// 0096bfe3  e83897b8ff           call 0x4f5720
// 0096bfe8  890424               mov dword ptr [esp], eax
// 0096bfeb  8d0424               lea eax, [esp]
// 0096bfee  50                   push eax
// 0096bfef  e88c59a9ff           call 0x401980
// 0096bff4  8bc8                 mov ecx, eax
// 0096bff6  e82595adff           call 0x445520
// 0096bffb  c700807fb100         mov dword ptr [eax], 0xb17f80
// 0096c001  68e0f79700           push 0x97f7e0
// 0096c006  c705b4dfb7009a020000 mov dword ptr [0xb7dfb4], 0x29a
// 0096c010  e81489e8ff           call 0x7f4929
// 0096c015  83c408               add esp, 8
// 0096c018  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7de50;
extern int global_b7dfb4;
extern ICreator creator_b17f80;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4f6870();
const Name &doDeclare();
void destroy_97f7e0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7de50, &callDoDeclare_4f6870);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b17f80;
    global_b7dfb4 = 0x29a;
    atexit(&destroy_97f7e0);
}
