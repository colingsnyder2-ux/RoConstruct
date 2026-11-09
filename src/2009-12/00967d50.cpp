// from server: 100% by nuck16
// roc 2009-12 00967d50  unit: seg_00960000  size: 73 bytes
//
// 00967d50  51                   push ecx
// 00967d51  68f0164000           push 0x4016f0
// 00967d56  682094b700           push 0xb79420
// 00967d5b  e8d098a9ff           call 0x401630
// 00967d60  83c408               add esp, 8
// 00967d63  e83896a9ff           call 0x4013a0
// 00967d68  890424               mov dword ptr [esp], eax
// 00967d6b  8d0424               lea eax, [esp]
// 00967d6e  50                   push eax
// 00967d6f  e80c9ca9ff           call 0x401980
// 00967d74  8bc8                 mov ecx, eax
// 00967d76  e8a5d7adff           call 0x445520
// 00967d7b  c70074f4af00         mov dword ptr [eax], 0xaff474
// 00967d81  6830d69700           push 0x97d630
// 00967d86  c705b494b7009a020000 mov dword ptr [0xb794b4], 0x29a
// 00967d90  e894cbe8ff           call 0x7f4929
// 00967d95  83c408               add esp, 8
// 00967d98  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b79420;
extern int global_b794b4;
extern ICreator creator_aff474;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4016f0();
const Name &doDeclare();
void destroy_97d630();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b79420, &callDoDeclare_4016f0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_aff474;
    global_b794b4 = 0x29a;
    atexit(&destroy_97d630);
}
