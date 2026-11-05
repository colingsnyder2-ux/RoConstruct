// from server: 100% by nuck16
// roc 2009-12 0096bf30  unit: seg_00960000  size: 73 bytes
//
// 0096bf30  51                   push ecx
// 0096bf31  6840684f00           push 0x4f6840
// 0096bf36  6844deb700           push 0xb7de44
// 0096bf3b  e8f056a9ff           call 0x401630
// 0096bf40  83c408               add esp, 8
// 0096bf43  e88896b8ff           call 0x4f55d0
// 0096bf48  890424               mov dword ptr [esp], eax
// 0096bf4b  8d0424               lea eax, [esp]
// 0096bf4e  50                   push eax
// 0096bf4f  e82c5aa9ff           call 0x401980
// 0096bf54  8bc8                 mov ecx, eax
// 0096bf56  e8c595adff           call 0x445520
// 0096bf5b  c700787fb100         mov dword ptr [eax], 0xb17f78
// 0096bf61  6860f89700           push 0x97f860
// 0096bf66  c705acdfb7009a020000 mov dword ptr [0xb7dfac], 0x29a
// 0096bf70  e8b489e8ff           call 0x7f4929
// 0096bf75  83c408               add esp, 8
// 0096bf78  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7de44;
extern int global_b7dfac;
extern ICreator creator_b17f78;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4f6840();
const Name &doDeclare();
void destroy_97f860();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7de44, &callDoDeclare_4f6840);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b17f78;
    global_b7dfac = 0x29a;
    atexit(&destroy_97f860);
}
