// from server: 100% by nuck16
// roc 2009-12 0096c020  unit: seg_00960000  size: 73 bytes
//
// 0096c020  51                   push ecx
// 0096c021  6880684f00           push 0x4f6880
// 0096c026  6854deb700           push 0xb7de54
// 0096c02b  e80056a9ff           call 0x401630
// 0096c030  83c408               add esp, 8
// 0096c033  e85897b8ff           call 0x4f5790
// 0096c038  890424               mov dword ptr [esp], eax
// 0096c03b  8d0424               lea eax, [esp]
// 0096c03e  50                   push eax
// 0096c03f  e83c59a9ff           call 0x401980
// 0096c044  8bc8                 mov ecx, eax
// 0096c046  e8d594adff           call 0x445520
// 0096c04b  c700847fb100         mov dword ptr [eax], 0xb17f84
// 0096c051  68a0f79700           push 0x97f7a0
// 0096c056  c705b8dfb7009a020000 mov dword ptr [0xb7dfb8], 0x29a
// 0096c060  e8c488e8ff           call 0x7f4929
// 0096c065  83c408               add esp, 8
// 0096c068  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7de54;
extern int global_b7dfb8;
extern ICreator creator_b17f84;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4f6880();
const Name &doDeclare();
void destroy_97f7a0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7de54, &callDoDeclare_4f6880);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b17f84;
    global_b7dfb8 = 0x29a;
    atexit(&destroy_97f7a0);
}
