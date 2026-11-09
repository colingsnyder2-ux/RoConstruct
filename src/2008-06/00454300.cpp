// from server: 100% by colin
// from server: 93% by colin
// roc 2008-06 00454300  unit: CRobloxDoc  size: 393 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00454300
//
// 00454300  6aff                 push -1
// 00454302  68f01f7c00           push 0x7c1ff0
// 00454307  64a100000000         mov eax, dword ptr fs:[0]
// 0045430d  50                   push eax
// 0045430e  64892500000000       mov dword ptr fs:[0], esp
// 00454315  83ec24               sub esp, 0x24
// 00454318  53                   push ebx
// 00454319  55                   push ebp
// 0045431a  56                   push esi
// 0045431b  57                   push edi
// 0045431c  8bf1                 mov esi, ecx
// 0045431e  8b8e94000000         mov ecx, dword ptr [esi + 0x94]
// 00454324  8d442418             lea eax, [esp + 0x18]
// 00454328  50                   push eax
// 00454329  e812660100           call 0x46a940
// 0045432e  8b10                 mov edx, dword ptr [eax]
// 00454330  83ec08               sub esp, 8
// 00454333  8bcc                 mov ecx, esp
// 00454335  8911                 mov dword ptr [ecx], edx
// 00454337  8b4004               mov eax, dword ptr [eax + 4]
// 0045433a  c744244400000000     mov dword ptr [esp + 0x44], 0
// 00454342  89642418             mov dword ptr [esp + 0x18], esp
// 00454346  894104               mov dword ptr [ecx + 4], eax
// 00454349  85c0                 test eax, eax
// 0045434b  740c                 je 0x454359
// 0045434d  83c004               add eax, 4
// 00454350  b901000000           mov ecx, 1
// 00454355  f00fc108             lock xadd dword ptr [eax], ecx
// 00454359  8d4c2430             lea ecx, [esp + 0x30]
// 0045435d  e8ded7fbff           call 0x411b40
// 00454362  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00454366  c644243c02           mov byte ptr [esp + 0x3c], 2
// 0045436b  85ff                 test edi, edi
// 0045436d  742a                 je 0x454399
// 0045436f  8d5704               lea edx, [edi + 4]
// 00454372  83c8ff               or eax, 0xffffffff
// 00454375  f00fc102             lock xadd dword ptr [edx], eax
// 00454379  751e                 jne 0x454399
// 0045437b  8b17                 mov edx, dword ptr [edi]
// 0045437d  8b4204               mov eax, dword ptr [edx + 4]
// 00454380  8bcf                 mov ecx, edi
// 00454382  ffd0                 call eax
// 00454384  8d4f08               lea ecx, [edi + 8]
// 00454387  83caff               or edx, 0xffffffff
// 0045438a  f00fc111             lock xadd dword ptr [ecx], edx
// 0045438e  7509                 jne 0x454399
// 00454390  8b07                 mov eax, dword ptr [edi]
// 00454392  8b5008               mov edx, dword ptr [eax + 8]
// 00454395  8bcf                 mov ecx, edi
// 00454397  ffd2                 call edx
// 00454399  8d442410             lea eax, [esp + 0x10]
// 0045439d  50                   push eax
// 0045439e  8bce                 mov ecx, esi
// 004543a0  e89becfaff           call 0x403040
// 004543a5  8b08                 mov ecx, dword ptr [eax]
// 004543a7  c644243c03           mov byte ptr [esp + 0x3c], 3
// 004543ac  e83fedffff           call 0x4530f0
// 004543b1  8be8                 mov ebp, eax
// 004543b3  8b442414             mov eax, dword ptr [esp + 0x14]
// 004543b7  c644243c02           mov byte ptr [esp + 0x3c], 2
// 004543bc  85c0                 test eax, eax
// 004543be  742c                 je 0x4543ec
// 004543c0  8bf8                 mov edi, eax
// 004543c2  83c004               add eax, 4
// 004543c5  83c9ff               or ecx, 0xffffffff
// 004543c8  f00fc108             lock xadd dword ptr [eax], ecx
// 004543cc  751e                 jne 0x4543ec
// 004543ce  8b17                 mov edx, dword ptr [edi]
// 004543d0  8b4204               mov eax, dword ptr [edx + 4]
// 004543d3  8bcf                 mov ecx, edi
// 004543d5  ffd0                 call eax
// 004543d7  8d4f08               lea ecx, [edi + 8]
// 004543da  83caff               or edx, 0xffffffff
// 004543dd  f00fc111             lock xadd dword ptr [ecx], edx
// 004543e1  7509                 jne 0x4543ec
// 004543e3  8b07                 mov eax, dword ptr [edi]
// 004543e5  8b5008               mov edx, dword ptr [eax + 8]
// 004543e8  8bcf                 mov ecx, edi
// 004543ea  ffd2                 call edx
// 004543ec  8d442420             lea eax, [esp + 0x20]
// 004543f0  50                   push eax
// 004543f1  8bce                 mov ecx, esi
// 004543f3  e848ecfaff           call 0x403040
// 004543f8  8b00                 mov eax, dword ptr [eax]
// 004543fa  6a01                 push 1
// 004543fc  50                   push eax
// 004543fd  c644244404           mov byte ptr [esp + 0x44], 4
// 00454402  e8591a0400           call 0x495e60
// 00454407  8ad8                 mov bl, al
// 00454409  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0045440d  83c408               add esp, 8
// 00454410  c644243c02           mov byte ptr [esp + 0x3c], 2
// 00454415  85c0                 test eax, eax
// 00454417  742c                 je 0x454445
// 00454419  8bf0                 mov esi, eax
// 0045441b  83c004               add eax, 4
// 0045441e  83c9ff               or ecx, 0xffffffff
// 00454421  f00fc108             lock xadd dword ptr [eax], ecx
// 00454425  751e                 jne 0x454445
// 00454427  8b16                 mov edx, dword ptr [esi]
// 00454429  8b4204               mov eax, dword ptr [edx + 4]
// 0045442c  8bce                 mov ecx, esi
// 0045442e  ffd0                 call eax
// 00454430  8d4e08               lea ecx, [esi + 8]
// 00454433  83caff               or edx, 0xffffffff
// 00454436  f00fc111             lock xadd dword ptr [ecx], edx
// 0045443a  7509                 jne 0x454445
// 0045443c  8b06                 mov eax, dword ptr [esi]
// 0045443e  8b5008               mov edx, dword ptr [eax + 8]
// 00454441  8bce                 mov ecx, esi
// 00454443  ffd2                 call edx
// 00454445  84db                 test bl, bl
// 00454447  750d                 jne 0x454456
// 00454449  b801000000           mov eax, 1
// 0045444e  3985b4010000         cmp dword ptr [ebp + 0x1b4], eax
// 00454454  7502                 jne 0x454458
// 00454456  33c0                 xor eax, eax
// 00454458  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 0045445c  8b11                 mov edx, dword ptr [ecx]
// 0045445e  50                   push eax
// 0045445f  8b02                 mov eax, dword ptr [edx]
// 00454461  ffd0                 call eax
// 00454463  8d4c2428             lea ecx, [esp + 0x28]
// 00454467  c744243cffffffff     mov dword ptr [esp + 0x3c], 0xffffffff
// 0045446f  e84c2f1200           call 0x5773c0
// 00454474  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 00454478  5f                   pop edi
// 00454479  5e                   pop esi
// 0045447a  5d                   pop ebp
// 0045447b  64890d00000000       mov dword ptr fs:[0], ecx
// 00454482  5b                   pop ebx
// 00454483  83c430               add esp, 0x30
// 00454486  c20400               ret 4

// from server: 92% by king_originala
// roc 2008-06 00454300  unit: CRobloxDoc  size: 393 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00454300
//
// 00454300  6aff                 push -1
// 00454302  68f01f7c00           push 0x7c1ff0
// 00454307  64a100000000         mov eax, dword ptr fs:[0]
// 0045430d  50                   push eax
// 0045430e  64892500000000       mov dword ptr fs:[0], esp
// 00454315  83ec24               sub esp, 0x24
// 00454318  53                   push ebx
// 00454319  55                   push ebp
// 0045431a  56                   push esi
// 0045431b  57                   push edi
// 0045431c  8bf1                 mov esi, ecx
// 0045431e  8b8e94000000         mov ecx, dword ptr [esi + 0x94]
// 00454324  8d442418             lea eax, [esp + 0x18]
// 00454328  50                   push eax
// 00454329  e812660100           call 0x46a940
// 0045432e  8b10                 mov edx, dword ptr [eax]
// 00454330  83ec08               sub esp, 8
// 00454333  8bcc                 mov ecx, esp
// 00454335  8911                 mov dword ptr [ecx], edx
// 00454337  8b4004               mov eax, dword ptr [eax + 4]
// 0045433a  c744244400000000     mov dword ptr [esp + 0x44], 0
// 00454342  89642418             mov dword ptr [esp + 0x18], esp
// 00454346  894104               mov dword ptr [ecx + 4], eax
// 00454349  85c0                 test eax, eax
// 0045434b  740c                 je 0x454359
// 0045434d  83c004               add eax, 4
// 00454350  b901000000           mov ecx, 1
// 00454355  f00fc108             lock xadd dword ptr [eax], ecx
// 00454359  8d4c2430             lea ecx, [esp + 0x30]
// 0045435d  e8ded7fbff           call 0x411b40
// 00454362  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00454366  c644243c02           mov byte ptr [esp + 0x3c], 2
// 0045436b  85ff                 test edi, edi
// 0045436d  742a                 je 0x454399
// 0045436f  8d5704               lea edx, [edi + 4]
// 00454372  83c8ff               or eax, 0xffffffff
// 00454375  f00fc102             lock xadd dword ptr [edx], eax
// 00454379  751e                 jne 0x454399
// 0045437b  8b17                 mov edx, dword ptr [edi]
// 0045437d  8b4204               mov eax, dword ptr [edx + 4]
// 00454380  8bcf                 mov ecx, edi
// 00454382  ffd0                 call eax
// 00454384  8d4f08               lea ecx, [edi + 8]
// 00454387  83caff               or edx, 0xffffffff
// 0045438a  f00fc111             lock xadd dword ptr [ecx], edx
// 0045438e  7509                 jne 0x454399
// 00454390  8b07                 mov eax, dword ptr [edi]
// 00454392  8b5008               mov edx, dword ptr [eax + 8]
// 00454395  8bcf                 mov ecx, edi
// 00454397  ffd2                 call edx
// 00454399  8d442410             lea eax, [esp + 0x10]
// 0045439d  50                   push eax
// 0045439e  8bce                 mov ecx, esi
// 004543a0  e89becfaff           call 0x403040
// 004543a5  8b08                 mov ecx, dword ptr [eax]
// 004543a7  c644243c03           mov byte ptr [esp + 0x3c], 3
// 004543ac  e83fedffff           call 0x4530f0
// 004543b1  8be8                 mov ebp, eax
// 004543b3  8b442414             mov eax, dword ptr [esp + 0x14]
// 004543b7  c644243c02           mov byte ptr [esp + 0x3c], 2
// 004543bc  85c0                 test eax, eax
// 004543be  742c                 je 0x4543ec
// 004543c0  8bf8                 mov edi, eax
// 004543c2  83c004               add eax, 4
// 004543c5  83c9ff               or ecx, 0xffffffff
// 004543c8  f00fc108             lock xadd dword ptr [eax], ecx
// 004543cc  751e                 jne 0x4543ec
// 004543ce  8b17                 mov edx, dword ptr [edi]
// 004543d0  8b4204               mov eax, dword ptr [edx + 4]
// 004543d3  8bcf                 mov ecx, edi
// 004543d5  ffd0                 call eax
// 004543d7  8d4f08               lea ecx, [edi + 8]
// 004543da  83caff               or edx, 0xffffffff
// 004543dd  f00fc111             lock xadd dword ptr [ecx], edx
// 004543e1  7509                 jne 0x4543ec
// 004543e3  8b07                 mov eax, dword ptr [edi]
// 004543e5  8b5008               mov edx, dword ptr [eax + 8]
// 004543e8  8bcf                 mov ecx, edi
// 004543ea  ffd2                 call edx
// 004543ec  8d442420             lea eax, [esp + 0x20]
// 004543f0  50                   push eax
// 004543f1  8bce                 mov ecx, esi
// 004543f3  e848ecfaff           call 0x403040
// 004543f8  8b00                 mov eax, dword ptr [eax]
// 004543fa  6a01                 push 1
// 004543fc  50                   push eax
// 004543fd  c644244404           mov byte ptr [esp + 0x44], 4
// 00454402  e8591a0400           call 0x495e60
// 00454407  8ad8                 mov bl, al
// 00454409  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0045440d  83c408               add esp, 8
// 00454410  c644243c02           mov byte ptr [esp + 0x3c], 2
// 00454415  85c0                 test eax, eax
// 00454417  742c                 je 0x454445
// 00454419  8bf0                 mov esi, eax
// 0045441b  83c004               add eax, 4
// 0045441e  83c9ff               or ecx, 0xffffffff
// 00454421  f00fc108             lock xadd dword ptr [eax], ecx
// 00454425  751e                 jne 0x454445
// 00454427  8b16                 mov edx, dword ptr [esi]
// 00454429  8b4204               mov eax, dword ptr [edx + 4]
// 0045442c  8bce                 mov ecx, esi
// 0045442e  ffd0                 call eax
// 00454430  8d4e08               lea ecx, [esi + 8]
// 00454433  83caff               or edx, 0xffffffff
// 00454436  f00fc111             lock xadd dword ptr [ecx], edx
// 0045443a  7509                 jne 0x454445
// 0045443c  8b06                 mov eax, dword ptr [esi]
// 0045443e  8b5008               mov edx, dword ptr [eax + 8]
// 00454441  8bce                 mov ecx, esi
// 00454443  ffd2                 call edx
// 00454445  84db                 test bl, bl
// 00454447  750d                 jne 0x454456
// 00454449  b801000000           mov eax, 1
// 0045444e  3985b4010000         cmp dword ptr [ebp + 0x1b4], eax
// 00454454  7502                 jne 0x454458
// 00454456  33c0                 xor eax, eax
// 00454458  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 0045445c  8b11                 mov edx, dword ptr [ecx]
// 0045445e  50                   push eax
// 0045445f  8b02                 mov eax, dword ptr [edx]
// 00454461  ffd0                 call eax
// 00454463  8d4c2428             lea ecx, [esp + 0x28]
// 00454467  c744243cffffffff     mov dword ptr [esp + 0x3c], 0xffffffff
// 0045446f  e84c2f1200           call 0x5773c0
// 00454474  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 00454478  5f                   pop edi
// 00454479  5e                   pop esi
// 0045447a  5d                   pop ebp
// 0045447b  64890d00000000       mov dword ptr fs:[0], ecx
// 00454482  5b                   pop ebx
// 00454483  83c430               add esp, 0x30
// 00454486  c20400               ret 4

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual ~Control();
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    long strong;
    long weak;
};

struct State {
    unsigned char padding[0x1b4];
    int value;
};

struct Object {
    State* query();
};

struct Result {
    Object* object;
    Object* get() const { return object; }
    Control* control;
    ~Result();
};

struct Pointer {
    Object* object;
    Object* get() const { return object; }
    Control* control;
    Pointer(const Result&);
    ~Pointer();
};

inline Result::~Result()
{
    if (control) {
        Control* p = control;
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

inline Pointer::Pointer(const Result& other)
    : object(other.object), control(other.control)
{
    if (control)
        _InterlockedIncrement(&control->strong);
}

inline Pointer::~Pointer()
{
    if (control) {
        Control* p = control;
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

struct Source {
    Result get();
};

struct Guard {
    unsigned char storage[12];
    Guard(Pointer);
    ~Guard();
};

struct Command {
    virtual void enable(int) = 0;
};

extern bool __cdecl check(Object*, int);

struct S {
    unsigned char padding[0x94];
    Source* source;
    Result f();
    void update(Command*);
};

void S::update(Command* command)
{
    Guard guard(source->get());
    State* state = f().get()->query();
    bool checked = check(f().get(), 1);
    int enabled;
    if (checked)
        enabled = 0;
    else {
        enabled = 1;
        if (state->value == enabled)
            enabled = 0;
    }
    command->enable(enabled);
}
