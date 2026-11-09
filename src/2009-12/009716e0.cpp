// from server: 100% by nuck16
// roc 2009-12 009716e0  unit: seg_00970000  size: 73 bytes
//
// 009716e0  51                   push ecx
// 009716e1  6860996400           push 0x649960
// 009716e6  68ec5fb800           push 0xb85fec
// 009716eb  e840ffa8ff           call 0x401630
// 009716f0  83c408               add esp, 8
// 009716f3  e8886ecdff           call 0x648580
// 009716f8  890424               mov dword ptr [esp], eax
// 009716fb  8d0424               lea eax, [esp]
// 009716fe  50                   push eax
// 009716ff  e87c02a9ff           call 0x401980
// 00971704  8bc8                 mov ecx, eax
// 00971706  e8153eadff           call 0x445520
// 0097170b  c700c42ab300         mov dword ptr [eax], 0xb32ac4
// 00971711  68f0439800           push 0x9843f0
// 00971716  c70518fcb8009a020000 mov dword ptr [0xb8fc18], 0x29a
// 00971720  e80432e8ff           call 0x7f4929
// 00971725  83c408               add esp, 8
// 00971728  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b85fec;
extern int global_b8fc18;
extern ICreator creator_b32ac4;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649960();
const Name &doDeclare();
void destroy_9843f0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b85fec, &callDoDeclare_649960);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32ac4;
    global_b8fc18 = 0x29a;
    atexit(&destroy_9843f0);
}
