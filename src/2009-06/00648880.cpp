// from server: 93% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005bd4b0  unit: VStockSound::?$FactoryProduct  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005bd4b0
//
// 005bd4b0  8a442404             mov al, byte ptr [esp + 4]
// 005bd4b4  56                   push esi
// 005bd4b5  8bf1                 mov esi, ecx
// 005bd4b7  8a8e65010000         mov cl, byte ptr [esi + 0x165]
// 005bd4bd  8ad1                 mov dl, cl
// 005bd4bf  d0ea                 shr dl, 1
// 005bd4c1  80e201               and dl, 1
// 005bd4c4  3ad0                 cmp dl, al
// 005bd4c6  7421                 je 0x5bd4e9
// 005bd4c8  02c0                 add al, al
// 005bd4ca  32c1                 xor al, cl
// 005bd4cc  2402                 and al, 2
// 005bd4ce  32c1                 xor al, cl
// 005bd4d0  8bce                 mov ecx, esi
// 005bd4d2  888665010000         mov byte ptr [esi + 0x165], al
// 005bd4d8  e8b3c3ffff           call 0x5b9890
// 005bd4dd  6818719700           push 0x977118
// 005bd4e2  8bce                 mov ecx, esi
// 005bd4e4  e81706e5ff           call 0x40db00
// 005bd4e9  5e                   pop esi
// 005bd4ea  c20400               ret 4

extern unsigned char loopingProperty;

struct SoundChannel {
    unsigned char padding0[0x13c];
    void *handle;
    unsigned char padding1[0x25];
    unsigned char unused : 1;
    unsigned char looping : 1;
    unsigned char remaining : 6;

    void setLooping(bool value);
    void updateLooping();
    void notifyProperty(const void *property);
};

void SoundChannel::setLooping(bool value)
{
    if (looping != value) {
        looping = value;
        updateLooping();
        notifyProperty(&loopingProperty);
    }
}
