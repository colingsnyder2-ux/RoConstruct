// from server: 100% by nuck16
// roc 2009-12 00968220  unit: seg_00960000  size: 73 bytes
//
// 00968220  51                   push ecx
// 00968221  6890954000           push 0x409590
// 00968226  681896b700           push 0xb79618
// 0096822b  e80094a9ff           call 0x401630
// 00968230  83c408               add esp, 8
// 00968233  e81810aaff           call 0x409250
// 00968238  890424               mov dword ptr [esp], eax
// 0096823b  8d0424               lea eax, [esp]
// 0096823e  50                   push eax
// 0096823f  e83c97a9ff           call 0x401980
// 00968244  8bc8                 mov ecx, eax
// 00968246  e8d5d2adff           call 0x445520
// 0096824b  c7005c1db000         mov dword ptr [eax], 0xb01d5c
// 00968251  6880d99700           push 0x97d980
// 00968256  c7053c9fb7009a020000 mov dword ptr [0xb79f3c], 0x29a
// 00968260  e8c4c6e8ff           call 0x7f4929
// 00968265  83c408               add esp, 8
// 00968268  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b79618;
extern int global_b79f3c;
extern ICreator creator_b01d5c;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_409590();
const Name &doDeclare();
void destroy_97d980();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b79618, &callDoDeclare_409590);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b01d5c;
    global_b79f3c = 0x29a;
    atexit(&destroy_97d980);
}
