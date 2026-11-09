// from server: 100% by nuck16
// roc 2009-12 00971960  unit: seg_00970000  size: 73 bytes
//
// 00971960  51                   push ecx
// 00971961  68e0996400           push 0x6499e0
// 00971966  680c60b800           push 0xb8600c
// 0097196b  e8c0fca8ff           call 0x401630
// 00971970  83c408               add esp, 8
// 00971973  e8886fcdff           call 0x648900
// 00971978  890424               mov dword ptr [esp], eax
// 0097197b  8d0424               lea eax, [esp]
// 0097197e  50                   push eax
// 0097197f  e8fcffa8ff           call 0x401980
// 00971984  8bc8                 mov ecx, eax
// 00971986  e8953badff           call 0x445520
// 0097198b  c700e42ab300         mov dword ptr [eax], 0xb32ae4
// 00971991  68f0419800           push 0x9841f0
// 00971996  c70538fcb8009a020000 mov dword ptr [0xb8fc38], 0x29a
// 009719a0  e8842fe8ff           call 0x7f4929
// 009719a5  83c408               add esp, 8
// 009719a8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b8600c;
extern int global_b8fc38;
extern ICreator creator_b32ae4;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_6499e0();
const Name &doDeclare();
void destroy_9841f0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b8600c, &callDoDeclare_6499e0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32ae4;
    global_b8fc38 = 0x29a;
    atexit(&destroy_9841f0);
}
