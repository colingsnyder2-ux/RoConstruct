// from server: 100% by colin
// from server: 82% by colin
// roc 2008-06 00424dd0  unit: CRobloxTreeCtrlNode  size: 224 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00424dd0
//
// 00424dd0  6aff                 push -1
// 00424dd2  6820eb7b00           push 0x7beb20
// 00424dd7  64a100000000         mov eax, dword ptr fs:[0]
// 00424ddd  50                   push eax
// 00424dde  64892500000000       mov dword ptr fs:[0], esp
// 00424de5  83ec18               sub esp, 0x18
// 00424de8  53                   push ebx
// 00424de9  56                   push esi
// 00424dea  8bf1                 mov esi, ecx
// 00424dec  8b4e58               mov ecx, dword ptr [esi + 0x58]
// 00424def  8b01                 mov eax, dword ptr [ecx]
// 00424df1  8b8054010000         mov eax, dword ptr [eax + 0x154]
// 00424df7  57                   push edi
// 00424df8  8d542410             lea edx, [esp + 0x10]
// 00424dfc  52                   push edx
// 00424dfd  ffd0                 call eax
// 00424dff  8b10                 mov edx, dword ptr [eax]
// 00424e01  83ec08               sub esp, 8
// 00424e04  8bcc                 mov ecx, esp
// 00424e06  8911                 mov dword ptr [ecx], edx
// 00424e08  8b4004               mov eax, dword ptr [eax + 4]
// 00424e0b  c744243400000000     mov dword ptr [esp + 0x34], 0
// 00424e13  89642414             mov dword ptr [esp + 0x14], esp
// 00424e17  894104               mov dword ptr [ecx + 4], eax
// 00424e1a  85c0                 test eax, eax
// 00424e1c  740c                 je 0x424e2a
// 00424e1e  83c004               add eax, 4
// 00424e21  b901000000           mov ecx, 1
// 00424e26  f00fc108             lock xadd dword ptr [eax], ecx
// 00424e2a  8d4c2420             lea ecx, [esp + 0x20]
// 00424e2e  e80dcdfeff           call 0x411b40
// 00424e33  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00424e37  c644242c02           mov byte ptr [esp + 0x2c], 2
// 00424e3c  85ff                 test edi, edi
// 00424e3e  742a                 je 0x424e6a
// 00424e40  8d5704               lea edx, [edi + 4]
// 00424e43  83c8ff               or eax, 0xffffffff
// 00424e46  f00fc102             lock xadd dword ptr [edx], eax
// 00424e4a  751e                 jne 0x424e6a
// 00424e4c  8b17                 mov edx, dword ptr [edi]
// 00424e4e  8b4204               mov eax, dword ptr [edx + 4]
// 00424e51  8bcf                 mov ecx, edi
// 00424e53  ffd0                 call eax
// 00424e55  8d4f08               lea ecx, [edi + 8]
// 00424e58  83caff               or edx, 0xffffffff
// 00424e5b  f00fc111             lock xadd dword ptr [ecx], edx
// 00424e5f  7509                 jne 0x424e6a
// 00424e61  8b07                 mov eax, dword ptr [edi]
// 00424e63  8b5008               mov edx, dword ptr [eax + 8]
// 00424e66  8bcf                 mov ecx, edi
// 00424e68  ffd2                 call edx
// 00424e6a  817c2438543d9700     cmp dword ptr [esp + 0x38], 0x973d54
// 00424e72  8d4c2418             lea ecx, [esp + 0x18]
// 00424e76  0f94c3               sete bl
// 00424e79  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 00424e81  e83a251500           call 0x5773c0
// 00424e86  84db                 test bl, bl
// 00424e88  7412                 je 0x424e9c
// 00424e8a  8b4e58               mov ecx, dword ptr [esi + 0x58]
// 00424e8d  804e5401             or byte ptr [esi + 0x54], 1
// 00424e91  8b01                 mov eax, dword ptr [ecx]
// 00424e93  8b905c010000         mov edx, dword ptr [eax + 0x15c]
// 00424e99  56                   push esi
// 00424e9a  ffd2                 call edx
// 00424e9c  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00424ea0  5f                   pop edi
// 00424ea1  5e                   pop esi
// 00424ea2  64890d00000000       mov dword ptr fs:[0], ecx
// 00424ea9  5b                   pop ebx
// 00424eaa  83c424               add esp, 0x24
// 00424ead  c20c00               ret 0xc

extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Pair {
    void* value;
    Control* control;

    Pair(const Pair& other) : value(other.value), control(other.control) {
        if (control)
            _InterlockedIncrement(&control->strong);
    }

    ~Pair() {
        Control* p = control;
        if (p) {
            if (_InterlockedDecrement(&p->strong) == 0) {
                p->dispose();
                if (_InterlockedDecrement(&p->weak) == 0)
                    p->destroy();
            }
        }
    }
};

struct Temporary {
    char storage[12];
    Temporary(Pair);
    ~Temporary();
};

struct Node;
struct OwnerTable;

struct Owner {
    OwnerTable* table;
};

struct OwnerTable {
    void* preceding[85];
    Pair (Owner::*get)();
    void* intervening;
    void (__thiscall* attach)(Owner*, Node*);
};

extern char identity;

struct Node {
    char preceding[84];
    unsigned char flags;
    char padding[3];
    Owner* owner;

    void update(void*, const void*, void*);
};

void Node::update(void*, const void* kind, void*) {
    bool matches;
    {
        Temporary temporary((owner->*(owner->table->get))());
        matches = kind == &identity;
    }
    if (matches) {
        Owner* self = owner;
        flags |= 1;
        self->table->attach(self, this);
    }
}
