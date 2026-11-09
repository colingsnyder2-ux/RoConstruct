// from server: 100% by nuck16
// roc 2009-12 00972220  unit: seg_00970000  size: 73 bytes
//
// 00972220  51                   push ecx
// 00972221  68a09b6400           push 0x649ba0
// 00972226  687c60b800           push 0xb8607c
// 0097222b  e800f4a8ff           call 0x401630
// 00972230  83c408               add esp, 8
// 00972233  e80873cdff           call 0x649540
// 00972238  890424               mov dword ptr [esp], eax
// 0097223b  8d0424               lea eax, [esp]
// 0097223e  50                   push eax
// 0097223f  e83cf7a8ff           call 0x401980
// 00972244  8bc8                 mov ecx, eax
// 00972246  e8d532adff           call 0x445520
// 0097224b  c700542bb300         mov dword ptr [eax], 0xb32b54
// 00972251  68f03a9800           push 0x983af0
// 00972256  c705b8fcb8009a020000 mov dword ptr [0xb8fcb8], 0x29a
// 00972260  e8c426e8ff           call 0x7f4929
// 00972265  83c408               add esp, 8
// 00972268  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b8607c;
extern int global_b8fcb8;
extern ICreator creator_b32b54;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649ba0();
const Name &doDeclare();
void destroy_983af0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b8607c, &callDoDeclare_649ba0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32b54;
    global_b8fcb8 = 0x29a;
    atexit(&destroy_983af0);
}
