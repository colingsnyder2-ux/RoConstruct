// from server: 100% by EspClaude
// from server: 94% by EspClaude
// roc 2009-06 006488c0  unit: RBX::Soundscape::SoundChannel  size: 116 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006488c0
//
// 006488c0  83ec18               sub esp, 0x18
// 006488c3  56                   push esi
// 006488c4  8bf1                 mov esi, ecx
// 006488c6  f686c500000001       test byte ptr [esi + 0xc5], 1
// 006488cd  745e                 je 0x64892d
// 006488cf  8b8ecc000000         mov ecx, dword ptr [esi + 0xcc]
// 006488d5  85c9                 test ecx, ecx
// 006488d7  7454                 je 0x64892d
// 006488d9  8d442410             lea eax, [esp + 0x10]
// 006488dd  50                   push eax
// 006488de  e86d3c0100           call 0x65c550
// 006488e3  83c024               add eax, 0x24
// 006488e6  50                   push eax
// 006488e7  e844b0ffff           call 0x643930
// 006488ec  83c408               add esp, 8
// 006488ef  84c0                 test al, al
// 006488f1  743a                 je 0x64892d
// 006488f3  8d4c2404             lea ecx, [esp + 4]
// 006488f7  51                   push ecx
// 006488f8  8b8ecc000000         mov ecx, dword ptr [esi + 0xcc]
// 006488fe  e88d3c0100           call 0x65c590
// 00648903  50                   push eax
// 00648904  e827b0ffff           call 0x643930
// 00648909  83c408               add esp, 8
// 0064890c  84c0                 test al, al
// 0064890e  741d                 je 0x64892d
// 00648910  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00648914  8d542404             lea edx, [esp + 4]
// 00648918  52                   push edx
// 00648919  8d442414             lea eax, [esp + 0x14]
// 0064891d  50                   push eax
// 0064891e  51                   push ecx
// 0064891f  e84af50c00           call 0x717e6e
// 00648924  50                   push eax
// 00648925  e886ebffff           call 0x6474b0
// 0064892a  83c404               add esp, 4
// 0064892d  5e                   pop esi
// 0064892e  83c418               add esp, 0x18
// 00648931  c20400               ret 4

// from server: 100% by king_originala
// roc 2008-06 005b9920  unit: RBX::Soundscape::SoundChannel  size: 116 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b9920
//
// 005b9920  83ec18               sub esp, 0x18
// 005b9923  56                   push esi
// 005b9924  8bf1                 mov esi, ecx
// 005b9926  f6866501000001       test byte ptr [esi + 0x165], 1
// 005b992d  745e                 je 0x5b998d
// 005b992f  8b8e6c010000         mov ecx, dword ptr [esi + 0x16c]
// 005b9935  85c9                 test ecx, ecx
// 005b9937  7454                 je 0x5b998d
// 005b9939  8d442410             lea eax, [esp + 0x10]
// 005b993d  50                   push eax
// 005b993e  e86df3fdff           call 0x598cb0
// 005b9943  83c024               add eax, 0x24
// 005b9946  50                   push eax
// 005b9947  e874d7ffff           call 0x5b70c0
// 005b994c  83c408               add esp, 8
// 005b994f  84c0                 test al, al
// 005b9951  743a                 je 0x5b998d
// 005b9953  8d4c2404             lea ecx, [esp + 4]
// 005b9957  51                   push ecx
// 005b9958  8b8e6c010000         mov ecx, dword ptr [esi + 0x16c]
// 005b995e  e8edfefdff           call 0x599850
// 005b9963  50                   push eax
// 005b9964  e857d7ffff           call 0x5b70c0
// 005b9969  83c408               add esp, 8
// 005b996c  84c0                 test al, al
// 005b996e  741d                 je 0x5b998d
// 005b9970  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 005b9974  8d542404             lea edx, [esp + 4]
// 005b9978  52                   push edx
// 005b9979  8d442414             lea eax, [esp + 0x14]
// 005b997d  50                   push eax
// 005b997e  51                   push ecx
// 005b997f  e888620e00           call 0x69fc0c
// 005b9984  50                   push eax
// 005b9985  e816eeffff           call 0x5b87a0
// 005b998a  83c404               add esp, 4
// 005b998d  5e                   pop esi
// 005b998e  83c418               add esp, 0x18
// 005b9991  c20400               ret 4

struct Vector3 {
    float x, y, z;
};

struct Frame {
    unsigned char padding[0x24];
    Vector3 position;
};

struct Body {
    unsigned char padding[0xc4];
    Vector3 value;
    void updatePV();
};

struct PartInstance {
    unsigned char padding[0x2c8];
    Body *body;

    const Frame &getFrame();
    const Vector3 &getValue();
};

bool __cdecl convertVector(const Vector3 &, Vector3 *);
extern "C" int __stdcall setAttributes(int, const Vector3 *, const Vector3 *);
void __cdecl checkResult(int);

struct SoundChannel {
    unsigned char padding[0xc5];
    unsigned char flags;
    unsigned char reserved[6];
    PartInstance *part;

    void update(int channel);
};

void SoundChannel::update(int channel)
{
    Vector3 position;
    Vector3 velocity;

    if ((flags & 1) && part) {
        if (convertVector(part->getFrame().position, &position)) {
            if (convertVector(part->getValue(), &velocity)) {
                checkResult(setAttributes(channel, &position, &velocity));
            }
        }
    }
}
