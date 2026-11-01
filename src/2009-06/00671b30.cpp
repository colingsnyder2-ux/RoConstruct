// from server: 100% by EspClaude
// from server: 89% by EspClaude
// roc 2009-06 00671b30  unit: RBX::VSpawnerService::?$FactoryProduct  size: 219 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00671b30
//
// 00671b30  64a100000000         mov eax, dword ptr fs:[0]
// 00671b36  6aff                 push -1
// 00671b38  6838938500           push 0x859338
// 00671b3d  50                   push eax
// 00671b3e  64892500000000       mov dword ptr fs:[0], esp
// 00671b45  56                   push esi
// 00671b46  57                   push edi
// 00671b47  8bf9                 mov edi, ecx
// 00671b49  80bf4502000000       cmp byte ptr [edi + 0x245], 0
// 00671b50  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00671b58  7520                 jne 0x671b7a
// 00671b5a  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00671b5e  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 00671b66  85f6                 test esi, esi
// 00671b68  0f848a000000         je 0x671bf8
// 00671b6e  8d4604               lea eax, [esi + 4]
// 00671b71  83c9ff               or ecx, 0xffffffff
// 00671b74  f00fc108             lock xadd dword ptr [eax], ecx
// 00671b78  eb5e                 jmp 0x671bd8
// 00671b7a  8b442418             mov eax, dword ptr [esp + 0x18]
// 00671b7e  8b7048               mov esi, dword ptr [eax + 0x48]
// 00671b81  85f6                 test esi, esi
// 00671b83  7439                 je 0x671bbe
// 00671b85  56                   push esi
// 00671b86  e8e569ffff           call 0x668570
// 00671b8b  83c404               add esp, 4
// 00671b8e  85c0                 test eax, eax
// 00671b90  742c                 je 0x671bbe
// 00671b92  56                   push esi
// 00671b93  e81894e5ff           call 0x4cafb0
// 00671b98  8bf0                 mov esi, eax
// 00671b9a  83c404               add esp, 4
// 00671b9d  85f6                 test esi, esi
// 00671b9f  741d                 je 0x671bbe
// 00671ba1  8b8738020000         mov eax, dword ptr [edi + 0x238]
// 00671ba7  50                   push eax
// 00671ba8  8bce                 mov ecx, esi
// 00671baa  e8b1f1e4ff           call 0x4c0d60
// 00671baf  0fb68f44020000       movzx ecx, byte ptr [edi + 0x244]
// 00671bb6  51                   push ecx
// 00671bb7  8bce                 mov ecx, esi
// 00671bb9  e8c2f1e4ff           call 0x4c0d80
// 00671bbe  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00671bc2  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 00671bca  85f6                 test esi, esi
// 00671bcc  742a                 je 0x671bf8
// 00671bce  8d5604               lea edx, [esi + 4]
// 00671bd1  83c8ff               or eax, 0xffffffff
// 00671bd4  f00fc102             lock xadd dword ptr [edx], eax
// 00671bd8  751e                 jne 0x671bf8
// 00671bda  8b16                 mov edx, dword ptr [esi]
// 00671bdc  8b4204               mov eax, dword ptr [edx + 4]
// 00671bdf  8bce                 mov ecx, esi
// 00671be1  ffd0                 call eax
// 00671be3  83caff               or edx, 0xffffffff
// 00671be6  8d4e08               lea ecx, [esi + 8]
// 00671be9  f00fc111             lock xadd dword ptr [ecx], edx
// 00671bed  7509                 jne 0x671bf8
// 00671bef  8b06                 mov eax, dword ptr [esi]
// 00671bf1  8b5008               mov edx, dword ptr [eax + 8]
// 00671bf4  8bce                 mov ecx, esi
// 00671bf6  ffd2                 call edx
// 00671bf8  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00671bfc  5f                   pop edi
// 00671bfd  64890d00000000       mov dword ptr fs:[0], ecx
// 00671c04  5e                   pop esi
// 00671c05  83c40c               add esp, 0xc
// 00671c08  c20800               ret 8

// from server: 100% by EspClaude
// roc 2008-06 005d1ec0  unit: RBX::VSpawnerService::?$FactoryProduct  size: 222 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005d1ec0
//
// 005d1ec0  64a100000000         mov eax, dword ptr fs:[0]
// 005d1ec6  6aff                 push -1
// 005d1ec8  6868617c00           push 0x7c6168
// 005d1ecd  50                   push eax
// 005d1ece  64892500000000       mov dword ptr fs:[0], esp
// 005d1ed5  56                   push esi
// 005d1ed6  57                   push edi
// 005d1ed7  8bf9                 mov edi, ecx
// 005d1ed9  80bf0104000000       cmp byte ptr [edi + 0x401], 0
// 005d1ee0  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005d1ee8  7520                 jne 0x5d1f0a
// 005d1eea  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 005d1eee  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 005d1ef6  85f6                 test esi, esi
// 005d1ef8  0f848d000000         je 0x5d1f8b
// 005d1efe  8d4604               lea eax, [esi + 4]
// 005d1f01  83c9ff               or ecx, 0xffffffff
// 005d1f04  f00fc108             lock xadd dword ptr [eax], ecx
// 005d1f08  eb61                 jmp 0x5d1f6b
// 005d1f0a  8b442418             mov eax, dword ptr [esp + 0x18]
// 005d1f0e  8bb004010000         mov esi, dword ptr [eax + 0x104]
// 005d1f14  85f6                 test esi, esi
// 005d1f16  7439                 je 0x5d1f51
// 005d1f18  56                   push esi
// 005d1f19  e8027b0000           call 0x5d9a20
// 005d1f1e  83c404               add esp, 4
// 005d1f21  85c0                 test eax, eax
// 005d1f23  742c                 je 0x5d1f51
// 005d1f25  56                   push esi
// 005d1f26  e8a58decff           call 0x49acd0
// 005d1f2b  8bf0                 mov esi, eax
// 005d1f2d  83c404               add esp, 4
// 005d1f30  85f6                 test esi, esi
// 005d1f32  741d                 je 0x5d1f51
// 005d1f34  8b87e8030000         mov eax, dword ptr [edi + 0x3e8]
// 005d1f3a  50                   push eax
// 005d1f3b  8bce                 mov ecx, esi
// 005d1f3d  e8be26ecff           call 0x494600
// 005d1f42  0fb68f00040000       movzx ecx, byte ptr [edi + 0x400]
// 005d1f49  51                   push ecx
// 005d1f4a  8bce                 mov ecx, esi
// 005d1f4c  e8cf26ecff           call 0x494620
// 005d1f51  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 005d1f55  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 005d1f5d  85f6                 test esi, esi
// 005d1f5f  742a                 je 0x5d1f8b
// 005d1f61  8d5604               lea edx, [esi + 4]
// 005d1f64  83c8ff               or eax, 0xffffffff
// 005d1f67  f00fc102             lock xadd dword ptr [edx], eax
// 005d1f6b  751e                 jne 0x5d1f8b
// 005d1f6d  8b16                 mov edx, dword ptr [esi]
// 005d1f6f  8b4204               mov eax, dword ptr [edx + 4]
// 005d1f72  8bce                 mov ecx, esi
// 005d1f74  ffd0                 call eax
// 005d1f76  83caff               or edx, 0xffffffff
// 005d1f79  8d4e08               lea ecx, [esi + 8]
// 005d1f7c  f00fc111             lock xadd dword ptr [ecx], edx
// 005d1f80  7509                 jne 0x5d1f8b
// 005d1f82  8b06                 mov eax, dword ptr [esi]
// 005d1f84  8b5008               mov edx, dword ptr [eax + 8]
// 005d1f87  8bce                 mov ecx, esi
// 005d1f89  ffd2                 call edx
// 005d1f8b  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005d1f8f  5f                   pop edi
// 005d1f90  64890d00000000       mov dword ptr fs:[0], ecx
// 005d1f97  5e                   pop esi
// 005d1f98  83c40c               add esp, 0xc
// 005d1f9b  c20800               ret 8

// from server: 74% by king_originala
// roc 2008-06 005d1ec0  unit: RBX::VSpawnerService::?$FactoryProduct  size: 222 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005d1ec0
//

#include <intrin.h>

struct Control {
    virtual ~Control();
    virtual void dispose();
    virtual void destroy();

    long strong;
    long weak;
};

struct Object {
    char padding[0x48];
    void* instance;
};

struct Shared {
    Object* object;
    Control* control;

    ~Shared();
};

inline Shared::~Shared()
{
    Control* p = control;
    if (p) {
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

struct BrickColor {
    int value;
};

struct Player {
    void setTeamColor(BrickColor color);
    void setNeutral(bool neutral);
};

int __cdecl checkInstance(void* instance);
Player* __cdecl getPlayer(void* instance);

struct S {
    char padding0[0x238];
    BrickColor color;
    char padding1[0x8];
    bool neutral;
    bool enabled;

    void f(Shared object);
    BrickColor getTeamColor() const { return color; }
};

void S::f(Shared object)
{
    if (!enabled)
        return;

    void* instance = object.object->instance;
    if (instance && checkInstance(instance)) {
        Player* player = getPlayer(instance);
        if (player) {
            player->setTeamColor(getTeamColor());
            player->setNeutral(neutral);
        }
    }
}
