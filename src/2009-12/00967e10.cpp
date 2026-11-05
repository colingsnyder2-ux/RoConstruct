// from server: 100% by nuck16
// roc 2009-12 00967e10  unit: seg_00960000  size: 73 bytes
//
// 00967e10  51                   push ecx
// 00967e11  6800214000           push 0x402100
// 00967e16  682495b700           push 0xb79524
// 00967e1b  e81098a9ff           call 0x401630
// 00967e20  83c408               add esp, 8
// 00967e23  e888a1a9ff           call 0x401fb0
// 00967e28  890424               mov dword ptr [esp], eax
// 00967e2b  8d0424               lea eax, [esp]
// 00967e2e  50                   push eax
// 00967e2f  e84c9ba9ff           call 0x401980
// 00967e34  8bc8                 mov ecx, eax
// 00967e36  e8e5d6adff           call 0x445520
// 00967e3b  c70034f6af00         mov dword ptr [eax], 0xaff634
// 00967e41  6860d79700           push 0x97d760
// 00967e46  c7052c95b7009a020000 mov dword ptr [0xb7952c], 0x29a
// 00967e50  e8d4cae8ff           call 0x7f4929
// 00967e55  83c408               add esp, 8
// 00967e58  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b79524;
extern int global_b7952c;
extern ICreator creator_aff634;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_402100();
const Name &doDeclare();
void destroy_97d760();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b79524, &callDoDeclare_402100);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_aff634;
    global_b7952c = 0x29a;
    atexit(&destroy_97d760);
}
