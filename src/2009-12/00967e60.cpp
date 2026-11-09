// from server: 100% by nuck16
// roc 2009-12 00967e60  unit: seg_00960000  size: 73 bytes
//
// 00967e60  51                   push ecx
// 00967e61  6810214000           push 0x402110
// 00967e66  682895b700           push 0xb79528
// 00967e6b  e8c097a9ff           call 0x401630
// 00967e70  83c408               add esp, 8
// 00967e73  e8a8a1a9ff           call 0x402020
// 00967e78  890424               mov dword ptr [esp], eax
// 00967e7b  8d0424               lea eax, [esp]
// 00967e7e  50                   push eax
// 00967e7f  e8fc9aa9ff           call 0x401980
// 00967e84  8bc8                 mov ecx, eax
// 00967e86  e895d6adff           call 0x445520
// 00967e8b  c70038f6af00         mov dword ptr [eax], 0xaff638
// 00967e91  6820d79700           push 0x97d720
// 00967e96  c7053095b7009a020000 mov dword ptr [0xb79530], 0x29a
// 00967ea0  e884cae8ff           call 0x7f4929
// 00967ea5  83c408               add esp, 8
// 00967ea8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b79528;
extern int global_b79530;
extern ICreator creator_aff638;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_402110();
const Name &doDeclare();
void destroy_97d720();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b79528, &callDoDeclare_402110);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_aff638;
    global_b79530 = 0x29a;
    atexit(&destroy_97d720);
}
