// from server: 100% by nuck16
// roc 2009-12 009745c0  unit: seg_00970000  size: 73 bytes
//
// 009745c0  51                   push ecx
// 009745c1  6810416b00           push 0x6b4110
// 009745c6  68a01cb900           push 0xb91ca0
// 009745cb  e860d0a8ff           call 0x401630
// 009745d0  83c408               add esp, 8
// 009745d3  e808f6d3ff           call 0x6b3be0
// 009745d8  890424               mov dword ptr [esp], eax
// 009745db  8d0424               lea eax, [esp]
// 009745de  50                   push eax
// 009745df  e89cd3a8ff           call 0x401980
// 009745e4  8bc8                 mov ecx, eax
// 009745e6  e8350fadff           call 0x445520
// 009745eb  c700f4b8b300         mov dword ptr [eax], 0xb3b8f4
// 009745f1  68d0579800           push 0x9857d0
// 009745f6  c705a41fb9009a020000 mov dword ptr [0xb91fa4], 0x29a
// 00974600  e82403e8ff           call 0x7f4929
// 00974605  83c408               add esp, 8
// 00974608  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b91ca0;
extern int global_b91fa4;
extern ICreator creator_b3b8f4;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_6b4110();
const Name &doDeclare();
void destroy_9857d0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b91ca0, &callDoDeclare_6b4110);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b3b8f4;
    global_b91fa4 = 0x29a;
    atexit(&destroy_9857d0);
}
