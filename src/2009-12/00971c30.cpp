// from server: 100% by nuck16
// roc 2009-12 00971c30  unit: seg_00970000  size: 73 bytes
//
// 00971c30  51                   push ecx
// 00971c31  68709a6400           push 0x649a70
// 00971c36  683060b800           push 0xb86030
// 00971c3b  e8f0f9a8ff           call 0x401630
// 00971c40  83c408               add esp, 8
// 00971c43  e8a870cdff           call 0x648cf0
// 00971c48  890424               mov dword ptr [esp], eax
// 00971c4b  8d0424               lea eax, [esp]
// 00971c4e  50                   push eax
// 00971c4f  e82cfda8ff           call 0x401980
// 00971c54  8bc8                 mov ecx, eax
// 00971c56  e8c538adff           call 0x445520
// 00971c5b  c700082bb300         mov dword ptr [eax], 0xb32b08
// 00971c61  68b03f9800           push 0x983fb0
// 00971c66  c7056cfcb8009a020000 mov dword ptr [0xb8fc6c], 0x29a
// 00971c70  e8b42ce8ff           call 0x7f4929
// 00971c75  83c408               add esp, 8
// 00971c78  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86030;
extern int global_b8fc6c;
extern ICreator creator_b32b08;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649a70();
const Name &doDeclare();
void destroy_983fb0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b86030, &callDoDeclare_649a70);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32b08;
    global_b8fc6c = 0x29a;
    atexit(&destroy_983fb0);
}
