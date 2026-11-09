// from server: 100% by nuck16
// roc 2009-12 0096c390  unit: seg_00960000  size: 73 bytes
//
// 0096c390  51                   push ecx
// 0096c391  6830694f00           push 0x4f6930
// 0096c396  6880deb700           push 0xb7de80
// 0096c39b  e89052a9ff           call 0x401630
// 0096c3a0  83c408               add esp, 8
// 0096c3a3  e8b898b8ff           call 0x4f5c60
// 0096c3a8  890424               mov dword ptr [esp], eax
// 0096c3ab  8d0424               lea eax, [esp]
// 0096c3ae  50                   push eax
// 0096c3af  e8cc55a9ff           call 0x401980
// 0096c3b4  8bc8                 mov ecx, eax
// 0096c3b6  e86591adff           call 0x445520
// 0096c3bb  c700b07fb100         mov dword ptr [eax], 0xb17fb0
// 0096c3c1  68e0f49700           push 0x97f4e0
// 0096c3c6  c705e4e0b7009a020000 mov dword ptr [0xb7e0e4], 0x29a
// 0096c3d0  e85485e8ff           call 0x7f4929
// 0096c3d5  83c408               add esp, 8
// 0096c3d8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7de80;
extern int global_b7e0e4;
extern ICreator creator_b17fb0;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4f6930();
const Name &doDeclare();
void destroy_97f4e0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7de80, &callDoDeclare_4f6930);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b17fb0;
    global_b7e0e4 = 0x29a;
    atexit(&destroy_97f4e0);
}
