// from server: 100% by colin
// from server: 91% by king_originala
// roc 2008-06 0040e5b0  unit: CBrowserView  size: 189 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0040e5b0
//
// 0040e5b0  8b442404             mov eax, dword ptr [esp + 4]
// 0040e5b4  56                   push esi
// 0040e5b5  50                   push eax
// 0040e5b6  8bf1                 mov esi, ecx
// 0040e5b8  e863262900           call 0x6a0c20
// 0040e5bd  83f8ff               cmp eax, -1
// 0040e5c0  7506                 jne 0x40e5c8
// 0040e5c2  0bc0                 or eax, eax
// 0040e5c4  5e                   pop esi
// 0040e5c5  c20400               ret 4
// 0040e5c8  57                   push edi
// 0040e5c9  6800e80000           push 0xe800
// 0040e5ce  56                   push esi
// 0040e5cf  8dbe1c010000         lea edi, [esi + 0x11c]
// 0040e5d5  6810000150           push 0x50010010
// 0040e5da  8bcf                 mov ecx, edi
// 0040e5dc  e85f3e2b00           call 0x6c2440
// 0040e5e1  85f6                 test esi, esi
// 0040e5e3  7405                 je 0x40e5ea
// 0040e5e5  8b4620               mov eax, dword ptr [esi + 0x20]
// 0040e5e8  eb02                 jmp 0x40e5ec
// 0040e5ea  33c0                 xor eax, eax
// 0040e5ec  898654010000         mov dword ptr [esi + 0x154], eax
// 0040e5f2  a160e09700           mov eax, dword ptr [0x97e060]
// 0040e5f7  8b35b0218000         mov esi, dword ptr [0x8021b0]
// 0040e5fd  85c0                 test eax, eax
// 0040e5ff  7513                 jne 0x40e614
// 0040e601  6a00                 push 0
// 0040e603  e8980a2a00           call 0x6af0a0
// 0040e608  a160e09700           mov eax, dword ptr [0x97e060]
// 0040e60d  83c404               add esp, 4
// 0040e610  85c0                 test eax, eax
// 0040e612  7427                 je 0x40e63b
// 0040e614  83c004               add eax, 4
// 0040e617  50                   push eax
// 0040e618  ffd6                 call esi
// 0040e61a  833d60e0970000       cmp dword ptr [0x97e060], 0
// 0040e621  750a                 jne 0x40e62d
// 0040e623  6a00                 push 0
// 0040e625  e8760a2a00           call 0x6af0a0
// 0040e62a  83c404               add esp, 4
// 0040e62d  8b0d60e09700         mov ecx, dword ptr [0x97e060]
// 0040e633  51                   push ecx
// 0040e634  8bcf                 mov ecx, edi
// 0040e636  e865682a00           call 0x6b4ea0
// 0040e63b  e840282b00           call 0x6c0e80
// 0040e640  83c004               add eax, 4
// 0040e643  50                   push eax
// 0040e644  ffd6                 call esi
// 0040e646  e835282b00           call 0x6c0e80
// 0040e64b  50                   push eax
// 0040e64c  8bcf                 mov ecx, edi
// 0040e64e  e8cd682a00           call 0x6b4f20
// 0040e653  8b17                 mov edx, dword ptr [edi]
// 0040e655  8b8254010000         mov eax, dword ptr [edx + 0x154]
// 0040e65b  6a00                 push 0
// 0040e65d  6893000000           push 0x93
// 0040e662  8bcf                 mov ecx, edi
// 0040e664  ffd0                 call eax
// 0040e666  5f                   pop edi
// 0040e667  33c0                 xor eax, eax
// 0040e669  5e                   pop esi
// 0040e66a  c20400               ret 4

struct Manager {
    long reserved;
    volatile long references;
};

extern Manager* paintManager;
extern void __cdecl InitializePaintManager(int);
extern Manager* __cdecl GetOtherManager();
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);

struct Browser;

struct Bar {
    typedef int (__thiscall *Dispatch)(Bar*, unsigned int, int);

    struct Table {
        void* slots[85];
        Dispatch invoke;
    };

    Table* table;
    char reserved[0x34];
    void* ownerWindow;

    int Create(unsigned long style, Browser* parent, unsigned int id);
    void SetPaintManager(Manager*);
    void SetOtherManager(Manager*);
};

struct Browser {
    char reserved0[0x20];
    void* window;
    char reserved1[0xF8];
    Bar bar;

    int BaseCreate(void*);
    int OnCreate(void*);
};

int Browser::OnCreate(void* creation)
{
    int result = BaseCreate(creation);
    if (result == -1)
        return result;

    bar.Create(0x50010010UL, this, 0xE800);
    bar.ownerWindow = this ? window : 0;

    if (!paintManager)
        InitializePaintManager(0);

    long (__stdcall *increment)(volatile long*) = InterlockedIncrement;

    if (paintManager) {
        increment(&paintManager->references);

        if (!paintManager)
            InitializePaintManager(0);

        bar.SetPaintManager(paintManager);
    }

    increment(&GetOtherManager()->references);
    bar.SetOtherManager(GetOtherManager());
    bar.table->invoke(&bar, 0x93, 0);
    return 0;
}
