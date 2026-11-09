// from server: 100% by nuck16
// roc 2009-12 0096bf80  unit: seg_00960000  size: 73 bytes
//
// 0096bf80  51                   push ecx
// 0096bf81  6850684f00           push 0x4f6850
// 0096bf86  6848deb700           push 0xb7de48
// 0096bf8b  e8a056a9ff           call 0x401630
// 0096bf90  83c408               add esp, 8
// 0096bf93  e8a896b8ff           call 0x4f5640
// 0096bf98  890424               mov dword ptr [esp], eax
// 0096bf9b  8d0424               lea eax, [esp]
// 0096bf9e  50                   push eax
// 0096bf9f  e8dc59a9ff           call 0x401980
// 0096bfa4  8bc8                 mov ecx, eax
// 0096bfa6  e87595adff           call 0x445520
// 0096bfab  c7007c7fb100         mov dword ptr [eax], 0xb17f7c
// 0096bfb1  6820f89700           push 0x97f820
// 0096bfb6  c705b0dfb7009a020000 mov dword ptr [0xb7dfb0], 0x29a
// 0096bfc0  e86489e8ff           call 0x7f4929
// 0096bfc5  83c408               add esp, 8
// 0096bfc8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7de48;
extern int global_b7dfb0;
extern ICreator creator_b17f7c;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4f6850();
const Name &doDeclare();
void destroy_97f820();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7de48, &callDoDeclare_4f6850);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b17f7c;
    global_b7dfb0 = 0x29a;
    atexit(&destroy_97f820);
}
