// from server: 100% by nuck16
// roc 2009-12 0096c2f0  unit: seg_00960000  size: 73 bytes
//
// 0096c2f0  51                   push ecx
// 0096c2f1  6810694f00           push 0x4f6910
// 0096c2f6  6878deb700           push 0xb7de78
// 0096c2fb  e83053a9ff           call 0x401630
// 0096c300  83c408               add esp, 8
// 0096c303  e87898b8ff           call 0x4f5b80
// 0096c308  890424               mov dword ptr [esp], eax
// 0096c30b  8d0424               lea eax, [esp]
// 0096c30e  50                   push eax
// 0096c30f  e86c56a9ff           call 0x401980
// 0096c314  8bc8                 mov ecx, eax
// 0096c316  e80592adff           call 0x445520
// 0096c31b  c700a87fb100         mov dword ptr [eax], 0xb17fa8
// 0096c321  6860f59700           push 0x97f560
// 0096c326  c705dce0b7009a020000 mov dword ptr [0xb7e0dc], 0x29a
// 0096c330  e8f485e8ff           call 0x7f4929
// 0096c335  83c408               add esp, 8
// 0096c338  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7de78;
extern int global_b7e0dc;
extern ICreator creator_b17fa8;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4f6910();
const Name &doDeclare();
void destroy_97f560();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7de78, &callDoDeclare_4f6910);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b17fa8;
    global_b7e0dc = 0x29a;
    atexit(&destroy_97f560);
}
