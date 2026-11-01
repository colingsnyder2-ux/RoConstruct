// from server: 100% by colin
// from server: 88% by king_originala
// roc 2008-06 005574d0  unit: RBX::VInstance::?$NonFactoryProduct  size: 249 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005574d0
//
// 005574d0  6aff                 push -1
// 005574d2  6802c57c00           push 0x7cc502
// 005574d7  64a100000000         mov eax, dword ptr fs:[0]
// 005574dd  50                   push eax
// 005574de  64892500000000       mov dword ptr fs:[0], esp
// 005574e5  83ec3c               sub esp, 0x3c
// 005574e8  56                   push esi
// 005574e9  8bf1                 mov esi, ecx
// 005574eb  8b8e04010000         mov ecx, dword ptr [esi + 0x104]
// 005574f1  c744240400000000     mov dword ptr [esp + 4], 0
// 005574f9  85c9                 test ecx, ecx
// 005574fb  0f84a3000000         je 0x5575a4
// 00557501  83b90401000000       cmp dword ptr [ecx + 0x104], 0
// 00557508  7473                 je 0x55757d
// 0055750a  8d442424             lea eax, [esp + 0x24]
// 0055750e  50                   push eax
// 0055750f  e8bcffffff           call 0x5574d0
// 00557514  688cca8100           push 0x81ca8c
// 00557519  50                   push eax
// 0055751a  8d4c2410             lea ecx, [esp + 0x10]
// 0055751e  51                   push ecx
// 0055751f  c744245400000000     mov dword ptr [esp + 0x54], 0
// 00557527  ff15e4238000         call dword ptr [0x8023e4]
// 0055752d  81c610010000         add esi, 0x110
// 00557533  56                   push esi
// 00557534  8b742460             mov esi, dword ptr [esp + 0x60]
// 00557538  50                   push eax
// 00557539  56                   push esi
// 0055753a  c644246001           mov byte ptr [esp + 0x60], 1
// 0055753f  ff15a8248000         call dword ptr [0x8024a8]
// 00557545  83c418               add esp, 0x18
// 00557548  8d4c2408             lea ecx, [esp + 8]
// 0055754c  c644244800           mov byte ptr [esp + 0x48], 0
// 00557551  ff1568248000         call dword ptr [0x802468]
// 00557557  8d4c2424             lea ecx, [esp + 0x24]
// 0055755b  c7442448ffffffff     mov dword ptr [esp + 0x48], 0xffffffff
// 00557563  ff1568248000         call dword ptr [0x802468]
// 00557569  8bc6                 mov eax, esi
// 0055756b  5e                   pop esi
// 0055756c  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 00557570  64890d00000000       mov dword ptr fs:[0], ecx
// 00557577  83c448               add esp, 0x48
// 0055757a  c20400               ret 4
// 0055757d  81c610010000         add esi, 0x110
// 00557583  56                   push esi
// 00557584  8b742454             mov esi, dword ptr [esp + 0x54]
// 00557588  8bce                 mov ecx, esi
// 0055758a  ff155c248000         call dword ptr [0x80245c]
// 00557590  8bc6                 mov eax, esi
// 00557592  5e                   pop esi
// 00557593  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 00557597  64890d00000000       mov dword ptr fs:[0], ecx
// 0055759e  83c448               add esp, 0x48
// 005575a1  c20400               ret 4
// 005575a4  8b742450             mov esi, dword ptr [esp + 0x50]
// 005575a8  6816b78000           push 0x80b716
// 005575ad  8bce                 mov ecx, esi
// 005575af  ff1558248000         call dword ptr [0x802458]
// 005575b5  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 005575b9  8bc6                 mov eax, esi
// 005575bb  5e                   pop esi
// 005575bc  64890d00000000       mov dword ptr fs:[0], ecx
// 005575c3  83c448               add esp, 0x48
// 005575c6  c20400               ret 4



#include <string>
typedef std::string String;

struct Instance {
    char padding[0x104];
    Instance *parent;
    char reserved[8];
    String name;

    String fullName();
};

String Instance::fullName()
{
    if (parent) {
        if (parent->parent)
            return parent->fullName() + "." + name;
        return name;
    }
    return "";
}
