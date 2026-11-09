// from server: 100% by nuck16
// roc 2009-12 00971dc0  unit: seg_00970000  size: 73 bytes
//
// 00971dc0  51                   push ecx
// 00971dc1  68c09a6400           push 0x649ac0
// 00971dc6  684460b800           push 0xb86044
// 00971dcb  e860f8a8ff           call 0x401630
// 00971dd0  83c408               add esp, 8
// 00971dd3  e84871cdff           call 0x648f20
// 00971dd8  890424               mov dword ptr [esp], eax
// 00971ddb  8d0424               lea eax, [esp]
// 00971dde  50                   push eax
// 00971ddf  e89cfba8ff           call 0x401980
// 00971de4  8bc8                 mov ecx, eax
// 00971de6  e83537adff           call 0x445520
// 00971deb  c7001c2bb300         mov dword ptr [eax], 0xb32b1c
// 00971df1  68703e9800           push 0x983e70
// 00971df6  c70580fcb8009a020000 mov dword ptr [0xb8fc80], 0x29a
// 00971e00  e8242be8ff           call 0x7f4929
// 00971e05  83c408               add esp, 8
// 00971e08  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86044;
extern int global_b8fc80;
extern ICreator creator_b32b1c;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649ac0();
const Name &doDeclare();
void destroy_983e70();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b86044, &callDoDeclare_649ac0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32b1c;
    global_b8fc80 = 0x29a;
    atexit(&destroy_983e70);
}
