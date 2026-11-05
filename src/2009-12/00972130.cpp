// from server: 100% by nuck16
// roc 2009-12 00972130  unit: seg_00970000  size: 73 bytes
//
// 00972130  51                   push ecx
// 00972131  68709b6400           push 0x649b70
// 00972136  687060b800           push 0xb86070
// 0097213b  e8f0f4a8ff           call 0x401630
// 00972140  83c408               add esp, 8
// 00972143  e8a872cdff           call 0x6493f0
// 00972148  890424               mov dword ptr [esp], eax
// 0097214b  8d0424               lea eax, [esp]
// 0097214e  50                   push eax
// 0097214f  e82cf8a8ff           call 0x401980
// 00972154  8bc8                 mov ecx, eax
// 00972156  e8c533adff           call 0x445520
// 0097215b  c700482bb300         mov dword ptr [eax], 0xb32b48
// 00972161  68b03b9800           push 0x983bb0
// 00972166  c705acfcb8009a020000 mov dword ptr [0xb8fcac], 0x29a
// 00972170  e8b427e8ff           call 0x7f4929
// 00972175  83c408               add esp, 8
// 00972178  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86070;
extern int global_b8fcac;
extern ICreator creator_b32b48;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649b70();
const Name &doDeclare();
void destroy_983bb0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b86070, &callDoDeclare_649b70);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32b48;
    global_b8fcac = 0x29a;
    atexit(&destroy_983bb0);
}
