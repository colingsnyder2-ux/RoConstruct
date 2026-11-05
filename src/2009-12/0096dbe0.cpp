// from server: 100% by nuck16
// roc 2009-12 0096dbe0  unit: seg_00960000  size: 73 bytes
//
// 0096dbe0  51                   push ecx
// 0096dbe1  68b0515700           push 0x5751b0
// 0096dbe6  683027b800           push 0xb82730
// 0096dbeb  e8403aa9ff           call 0x401630
// 0096dbf0  83c408               add esp, 8
// 0096dbf3  e8b873c0ff           call 0x574fb0
// 0096dbf8  890424               mov dword ptr [esp], eax
// 0096dbfb  8d0424               lea eax, [esp]
// 0096dbfe  50                   push eax
// 0096dbff  e87c3da9ff           call 0x401980
// 0096dc04  8bc8                 mov ecx, eax
// 0096dc06  e81579adff           call 0x445520
// 0096dc0b  c7001842b200         mov dword ptr [eax], 0xb24218
// 0096dc11  68e00b9800           push 0x980be0
// 0096dc16  c7053c27b8009a020000 mov dword ptr [0xb8273c], 0x29a
// 0096dc20  e8046de8ff           call 0x7f4929
// 0096dc25  83c408               add esp, 8
// 0096dc28  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b82730;
extern int global_b8273c;
extern ICreator creator_b24218;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_5751b0();
const Name &doDeclare();
void destroy_980be0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b82730, &callDoDeclare_5751b0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b24218;
    global_b8273c = 0x29a;
    atexit(&destroy_980be0);
}
