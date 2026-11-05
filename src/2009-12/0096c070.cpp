// from server: 100% by nuck16
// roc 2009-12 0096c070  unit: seg_00960000  size: 73 bytes
//
// 0096c070  51                   push ecx
// 0096c071  6890684f00           push 0x4f6890
// 0096c076  6858deb700           push 0xb7de58
// 0096c07b  e8b055a9ff           call 0x401630
// 0096c080  83c408               add esp, 8
// 0096c083  e87897b8ff           call 0x4f5800
// 0096c088  890424               mov dword ptr [esp], eax
// 0096c08b  8d0424               lea eax, [esp]
// 0096c08e  50                   push eax
// 0096c08f  e8ec58a9ff           call 0x401980
// 0096c094  8bc8                 mov ecx, eax
// 0096c096  e88594adff           call 0x445520
// 0096c09b  c700887fb100         mov dword ptr [eax], 0xb17f88
// 0096c0a1  6860f79700           push 0x97f760
// 0096c0a6  c705bcdfb7009a020000 mov dword ptr [0xb7dfbc], 0x29a
// 0096c0b0  e87488e8ff           call 0x7f4929
// 0096c0b5  83c408               add esp, 8
// 0096c0b8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7de58;
extern int global_b7dfbc;
extern ICreator creator_b17f88;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4f6890();
const Name &doDeclare();
void destroy_97f760();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7de58, &callDoDeclare_4f6890);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b17f88;
    global_b7dfbc = 0x29a;
    atexit(&destroy_97f760);
}
