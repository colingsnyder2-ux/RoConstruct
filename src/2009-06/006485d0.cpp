// from server: 92% by EspClaude
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
    char padding[0x138];
    unsigned char enabled;
};

namespace RBX {
    class Instance {
    public:
        virtual ~Instance();
        char pad[0x100];
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
    char padding[0x38];
    char property[0x25];
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
