// from server: 100% by EspClaude
// from server: 92% by EspClaude
// roc 2009-06 006485d0  unit: RBX::Soundscape::SoundChannel  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006485d0
//
// 006485d0  83ec08               sub esp, 8
// 006485d3  803dd8bca40000       cmp byte ptr [0xa4bcd8], 0
// 006485da  56                   push esi
// 006485db  8bf1                 mov esi, ecx
// 006485dd  7540                 jne 0x64861f
// 006485df  f686c500000004       test byte ptr [esi + 0xc5], 4
// 006485e6  7537                 jne 0x64861f
// 006485e8  e8e322e0ff           call 0x44a8d0
// 006485ed  80b89400000000       cmp byte ptr [eax + 0x94], 0
// 006485f4  7429                 je 0x64861f
// 006485f6  56                   push esi
// 006485f7  e864d9e1ff           call 0x465f60
// 006485fc  83c404               add esp, 4
// 006485ff  85c0                 test eax, eax
// 00648601  741c                 je 0x64861f
// 00648603  81c698000000         add esi, 0x98
// 00648609  56                   push esi
// 0064860a  8d4c2408             lea ecx, [esp + 8]
// 0064860e  51                   push ecx
// 0064860f  8bc8                 mov ecx, eax
// 00648611  e88a85f9ff           call 0x5e0ba0
// 00648616  8d4c2404             lea ecx, [esp + 4]
// 0064861a  e891c1fdff           call 0x6247b0
// 0064861f  5e                   pop esi
// 00648620  83c408               add esp, 8
// 00648623  c3                   ret 

// from server: 100% by king_originala
// roc 2008-06 005bc610  unit: RBX::Soundscape::SoundService  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005bc610
//
// 005bc610  83ec08               sub esp, 8
// 005bc613  803dc96f970000       cmp byte ptr [0x976fc9], 0
// 005bc61a  56                   push esi
// 005bc61b  8bf1                 mov esi, ecx
// 005bc61d  7540                 jne 0x5bc65f
// 005bc61f  f6866501000004       test byte ptr [esi + 0x165], 4
// 005bc626  7537                 jne 0x5bc65f
// 005bc628  e8b3f8e8ff           call 0x44bee0
// 005bc62d  80b83801000000       cmp byte ptr [eax + 0x138], 0
// 005bc634  7429                 je 0x5bc65f
// 005bc636  56                   push esi
// 005bc637  e8d48beaff           call 0x465210
// 005bc63c  83c404               add esp, 4
// 005bc63f  85c0                 test eax, eax
// 005bc641  741c                 je 0x5bc65f
// 005bc643  81c640010000         add esi, 0x140
// 005bc649  56                   push esi
// 005bc64a  8d4c2408             lea ecx, [esp + 8]
// 005bc64e  51                   push ecx
// 005bc64f  8bc8                 mov ecx, eax
// 005bc651  e8da60faff           call 0x562730
// 005bc656  8d4c2404             lea ecx, [esp + 4]
// 005bc65a  e801400400           call 0x600660
// 005bc65f  5e                   pop esi
// 005bc660  83c408               add esp, 8
// 005bc663  c3                   ret 

struct Handle {
    void* object;
    void* control;
    void release();
};

struct Context {
    char padding[0x94];
    unsigned char enabled;
};

namespace RBX {
    class Instance {
    public:
        virtual ~Instance();
        char pad[0x90];
        Instance* next;
    };

    class ServiceProvider : public Instance {
    public:
        ServiceProvider* finish();
        void acquire(Handle* result, void* property);
    };
}

extern unsigned char disabled;
RBX::ServiceProvider* func_00465210(RBX::Instance* p);

struct S : RBX::Instance {
    char property[0x2d];
    unsigned char flags;

    Context* context();
    void update();
};

void S::update()
{
    if (disabled)
        return;
    if (flags & 4)
        return;
    if (!context()->enabled)
        return;

    RBX::ServiceProvider* provider = func_00465210(this);
    if (provider) {
        Handle result;
        provider->acquire(&result, property);
        result.release();
    }
}
