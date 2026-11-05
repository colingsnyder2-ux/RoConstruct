// from server: 100% by EspClaude
// from server: 79% by EspClaude
// roc 2009-06 005cda70  unit: VAuthoringSettings::?$FactoryProduct  size: 237 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005cda70
//
// 005cda70  6aff                 push -1
// 005cda72  68c23f8700           push 0x873fc2
// 005cda77  64a100000000         mov eax, dword ptr fs:[0]
// 005cda7d  50                   push eax
// 005cda7e  64892500000000       mov dword ptr fs:[0], esp
// 005cda85  83ec3c               sub esp, 0x3c
// 005cda88  56                   push esi
// 005cda89  8bf1                 mov esi, ecx
// 005cda8b  8b4e48               mov ecx, dword ptr [esi + 0x48]
// 005cda8e  c744240400000000     mov dword ptr [esp + 4], 0
// 005cda96  85c9                 test ecx, ecx
// 005cda98  0f849a000000         je 0x5cdb38
// 005cda9e  83794800             cmp dword ptr [ecx + 0x48], 0
// 005cdaa2  7470                 je 0x5cdb14
// 005cdaa4  8d442424             lea eax, [esp + 0x24]
// 005cdaa8  50                   push eax
// 005cdaa9  e8c2ffffff           call 0x5cda70
// 005cdaae  68a4d08b00           push 0x8bd0a4
// 005cdab3  50                   push eax
// 005cdab4  8d4c2410             lea ecx, [esp + 0x10]
// 005cdab8  51                   push ecx
// 005cdab9  c744245400000000     mov dword ptr [esp + 0x54], 0
// 005cdac1  ff1548e48900         call dword ptr [0x89e448]
// 005cdac7  83c654               add esi, 0x54
// 005cdaca  56                   push esi
// 005cdacb  8b742460             mov esi, dword ptr [esp + 0x60]
// 005cdacf  50                   push eax
// 005cdad0  56                   push esi
// 005cdad1  c644246001           mov byte ptr [esp + 0x60], 1
// 005cdad6  ff150ce58900         call dword ptr [0x89e50c]
// 005cdadc  83c418               add esp, 0x18
// 005cdadf  8d4c2408             lea ecx, [esp + 8]
// 005cdae3  c644244800           mov byte ptr [esp + 0x48], 0
// 005cdae8  ff15c4e48900         call dword ptr [0x89e4c4]
// 005cdaee  8d4c2424             lea ecx, [esp + 0x24]
// 005cdaf2  c7442448ffffffff     mov dword ptr [esp + 0x48], 0xffffffff
// 005cdafa  ff15c4e48900         call dword ptr [0x89e4c4]
// 005cdb00  8bc6                 mov eax, esi
// 005cdb02  5e                   pop esi
// 005cdb03  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 005cdb07  64890d00000000       mov dword ptr fs:[0], ecx
// 005cdb0e  83c448               add esp, 0x48
// 005cdb11  c20400               ret 4
// 005cdb14  83c654               add esi, 0x54
// 005cdb17  56                   push esi
// 005cdb18  8b742454             mov esi, dword ptr [esp + 0x54]
// 005cdb1c  8bce                 mov ecx, esi
// 005cdb1e  ff15b8e48900         call dword ptr [0x89e4b8]
// 005cdb24  8bc6                 mov eax, esi
// 005cdb26  5e                   pop esi
// 005cdb27  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 005cdb2b  64890d00000000       mov dword ptr fs:[0], ecx
// 005cdb32  83c448               add esp, 0x48
// 005cdb35  c20400               ret 4
// 005cdb38  8b742450             mov esi, dword ptr [esp + 0x50]
// 005cdb3c  6816d28a00           push 0x8ad216
// 005cdb41  8bce                 mov ecx, esi
// 005cdb43  ff15b4e48900         call dword ptr [0x89e4b4]
// 005cdb49  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 005cdb4d  8bc6                 mov eax, esi
// 005cdb4f  5e                   pop esi
// 005cdb50  64890d00000000       mov dword ptr fs:[0], ecx
// 005cdb57  83c448               add esp, 0x48
// 005cdb5a  c20400               ret 4

// from server: 100% by colin
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
    char padding[0x48];
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
