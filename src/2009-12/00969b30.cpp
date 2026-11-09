// from server: 100% by nuck16
// roc 2009-12 00969b30  unit: seg_00960000  size: 73 bytes
//
// 00969b30  51                   push ecx
// 00969b31  68802d4600           push 0x462d80
// 00969b36  68dcb9b700           push 0xb7b9dc
// 00969b3b  e8f07aa9ff           call 0x401630
// 00969b40  83c408               add esp, 8
// 00969b43  e85884afff           call 0x461fa0
// 00969b48  890424               mov dword ptr [esp], eax
// 00969b4b  8d0424               lea eax, [esp]
// 00969b4e  50                   push eax
// 00969b4f  e82c7ea9ff           call 0x401980
// 00969b54  8bc8                 mov ecx, eax
// 00969b56  e8c5b9adff           call 0x445520
// 00969b5b  c700e0b4b000         mov dword ptr [eax], 0xb0b4e0
// 00969b61  6810eb9700           push 0x97eb10
// 00969b66  c70508bbb7009a020000 mov dword ptr [0xb7bb08], 0x29a
// 00969b70  e8b4ade8ff           call 0x7f4929
// 00969b75  83c408               add esp, 8
// 00969b78  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7b9dc;
extern int global_b7bb08;
extern ICreator creator_b0b4e0;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_462d80();
const Name &doDeclare();
void destroy_97eb10();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7b9dc, &callDoDeclare_462d80);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b0b4e0;
    global_b7bb08 = 0x29a;
    atexit(&destroy_97eb10);
}
