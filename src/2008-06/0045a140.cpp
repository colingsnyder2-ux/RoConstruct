// from server: 100% by colin
// from server: 99% by colin
// roc 2008-06 0045a140  unit: CRobloxView  size: 422 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0045a140
//
// 0045a140  6aff                 push -1
// 0045a142  68b1297c00           push 0x7c29b1
// 0045a147  64a100000000         mov eax, dword ptr fs:[0]
// 0045a14d  50                   push eax
// 0045a14e  64892500000000       mov dword ptr fs:[0], esp
// 0045a155  83ec24               sub esp, 0x24
// 0045a158  53                   push ebx
// 0045a159  56                   push esi
// 0045a15a  8bf1                 mov esi, ecx
// 0045a15c  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0045a164  837e2000             cmp dword ptr [esi + 0x20], 0
// 0045a168  57                   push edi
// 0045a169  0f8461010000         je 0x45a2d0
// 0045a16f  8b8670010000         mov eax, dword ptr [esi + 0x170]
// 0045a175  83ec08               sub esp, 8
// 0045a178  8bcc                 mov ecx, esp
// 0045a17a  8901                 mov dword ptr [ecx], eax
// 0045a17c  8b8674010000         mov eax, dword ptr [esi + 0x174]
// 0045a182  89642418             mov dword ptr [esp + 0x18], esp
// 0045a186  894104               mov dword ptr [ecx + 4], eax
// 0045a189  85c0                 test eax, eax
// 0045a18b  740c                 je 0x45a199
// 0045a18d  83c004               add eax, 4
// 0045a190  b901000000           mov ecx, 1
// 0045a195  f00fc108             lock xadd dword ptr [eax], ecx
// 0045a199  8d4c242c             lea ecx, [esp + 0x2c]
// 0045a19d  e89e79fbff           call 0x411b40
// 0045a1a2  8d542414             lea edx, [esp + 0x14]
// 0045a1a6  52                   push edx
// 0045a1a7  8bce                 mov ecx, esi
// 0045a1a9  c744243c00000000     mov dword ptr [esp + 0x3c], 0
// 0045a1b1  c644241300           mov byte ptr [esp + 0x13], 0
// 0045a1b6  e8b5f0ffff           call 0x459270
// 0045a1bb  8b08                 mov ecx, dword ptr [eax]
// 0045a1bd  c644243801           mov byte ptr [esp + 0x38], 1
// 0045a1c2  85c9                 test ecx, ecx
// 0045a1c4  7409                 je 0x45a1cf
// 0045a1c6  e80584fbff           call 0x4125d0
// 0045a1cb  8bd8                 mov ebx, eax
// 0045a1cd  eb02                 jmp 0x45a1d1
// 0045a1cf  33db                 xor ebx, ebx
// 0045a1d1  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0045a1d5  c644243800           mov byte ptr [esp + 0x38], 0
// 0045a1da  85ff                 test edi, edi
// 0045a1dc  742a                 je 0x45a208
// 0045a1de  8d4704               lea eax, [edi + 4]
// 0045a1e1  83c9ff               or ecx, 0xffffffff
// 0045a1e4  f00fc108             lock xadd dword ptr [eax], ecx
// 0045a1e8  751e                 jne 0x45a208
// 0045a1ea  8b17                 mov edx, dword ptr [edi]
// 0045a1ec  8b4204               mov eax, dword ptr [edx + 4]
// 0045a1ef  8bcf                 mov ecx, edi
// 0045a1f1  ffd0                 call eax
// 0045a1f3  8d4f08               lea ecx, [edi + 8]
// 0045a1f6  83caff               or edx, 0xffffffff
// 0045a1f9  f00fc111             lock xadd dword ptr [ecx], edx
// 0045a1fd  7509                 jne 0x45a208
// 0045a1ff  8b07                 mov eax, dword ptr [edi]
// 0045a201  8b5008               mov edx, dword ptr [eax + 8]
// 0045a204  8bcf                 mov ecx, edi
// 0045a206  ffd2                 call edx
// 0045a208  85db                 test ebx, ebx
// 0045a20a  7455                 je 0x45a261
// 0045a20c  8d44241c             lea eax, [esp + 0x1c]
// 0045a210  50                   push eax
// 0045a211  8bce                 mov ecx, esi
// 0045a213  e858f0ffff           call 0x459270
// 0045a218  8b00                 mov eax, dword ptr [eax]
// 0045a21a  6a01                 push 1
// 0045a21c  50                   push eax
// 0045a21d  c644244002           mov byte ptr [esp + 0x40], 2
// 0045a222  c744241801000000     mov dword ptr [esp + 0x18], 1
// 0045a22a  e831bc0300           call 0x495e60
// 0045a22f  83c408               add esp, 8
// 0045a232  84c0                 test al, al
// 0045a234  740f                 je 0x45a245
// 0045a236  8bcb                 mov ecx, ebx
// 0045a238  e8c3d30300           call 0x497600
// 0045a23d  84c0                 test al, al
// 0045a23f  7504                 jne 0x45a245
// 0045a241  b301                 mov bl, 1
// 0045a243  eb02                 jmp 0x45a247
// 0045a245  32db                 xor bl, bl
// 0045a247  8d4c241c             lea ecx, [esp + 0x1c]
// 0045a24b  c744243800000000     mov dword ptr [esp + 0x38], 0
// 0045a253  e808641a00           call 0x600660
// 0045a258  84db                 test bl, bl
// 0045a25a  7405                 je 0x45a261
// 0045a25c  c644240f01           mov byte ptr [esp + 0xf], 1
// 0045a261  83bea001000000       cmp dword ptr [esi + 0x1a0], 0
// 0045a268  8a4c240f             mov cl, byte ptr [esp + 0xf]
// 0045a26c  0f95c0               setne al
// 0045a26f  3ac8                 cmp cl, al
// 0045a271  744c                 je 0x45a2bf
// 0045a273  84c9                 test cl, cl
// 0045a275  7430                 je 0x45a2a7
// 0045a277  8d4c241c             lea ecx, [esp + 0x1c]
// 0045a27b  51                   push ecx
// 0045a27c  8bce                 mov ecx, esi
// 0045a27e  e8edefffff           call 0x459270
// 0045a283  8b00                 mov eax, dword ptr [eax]
// 0045a285  50                   push eax
// 0045a286  56                   push esi
// 0045a287  8d8e80010000         lea ecx, [esi + 0x180]
// 0045a28d  c644244003           mov byte ptr [esp + 0x40], 3
// 0045a292  e8c98bfdff           call 0x432e60
// 0045a297  8d4c241c             lea ecx, [esp + 0x1c]
// 0045a29b  c644243800           mov byte ptr [esp + 0x38], 0
// 0045a2a0  e8bb631a00           call 0x600660
// 0045a2a5  eb11                 jmp 0x45a2b8
// 0045a2a7  8b9680010000         mov edx, dword ptr [esi + 0x180]
// 0045a2ad  8b4268               mov eax, dword ptr [edx + 0x68]
// 0045a2b0  8d8e80010000         lea ecx, [esi + 0x180]
// 0045a2b6  ffd0                 call eax
// 0045a2b8  8bce                 mov ecx, esi
// 0045a2ba  e8f1efffff           call 0x4592b0
// 0045a2bf  8d4c2424             lea ecx, [esp + 0x24]
// 0045a2c3  c7442438ffffffff     mov dword ptr [esp + 0x38], 0xffffffff
// 0045a2cb  e8f0d01100           call 0x5773c0
// 0045a2d0  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0045a2d4  5f                   pop edi
// 0045a2d5  5e                   pop esi
// 0045a2d6  33c0                 xor eax, eax
// 0045a2d8  64890d00000000       mov dword ptr fs:[0], ecx
// 0045a2df  5b                   pop ebx
// 0045a2e0  83c430               add esp, 0x30
// 0045a2e3  c20800               ret 8

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void reserved();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Service {
    bool active();
};

struct Object {
    Service* service();
};

struct Shared {
    Object* pointer;
    Control* control;

    Shared(const Shared&);
    ~Shared();
    Service* service() const;
    Object* object() const { return pointer; }
};

inline Shared::Shared(const Shared& other)
    : pointer(other.pointer), control(other.control)
{
    if (control) {
        volatile long* c = &control->strong;
        _InterlockedExchangeAdd(c, 1);
    }
}

inline Shared::~Shared()
{
    Control* p = control;
    if (p && _InterlockedDecrement(&p->strong) == 0) {
        p->dispose();
        if (_InterlockedDecrement(&p->weak) == 0)
            p->destroy();
    }
}

inline Service* Shared::service() const
{
    return pointer ? pointer->service() : 0;
}

struct Guard {
    char storage[12];
    Guard(Shared);
    ~Guard();
};

struct View;
struct Pane;

struct PaneTable {
    void* unused[26];
    void (__thiscall* close)(Pane*);
};

struct Pane {
    PaneTable* table;
    char storage[28];
    void configure(View*, Object*);
};

extern bool __cdecl eligible(Object*, int);

struct View {
    char prefix[32];
    int enabled;
    char padding[332];
    Shared shared;
    char gap[8];
    Pane pane;
    int state;

    Shared getObject();
    void update();
    int refresh(int, int);
};

int View::refresh(int, int)
{
    if (enabled) {
        Guard guard(shared);
        bool desired = false;
        Service* service = getObject().service();

        if (service) {
            if (eligible(getObject().object(), 1) && !service->active())
                desired = true;
        }

        bool current = (state != 0);
        if (desired != current) {
            if (desired)
                pane.configure(this, getObject().object());
            else
                pane.table->close(&pane);
            update();
        }
    }
    return 0;
}
