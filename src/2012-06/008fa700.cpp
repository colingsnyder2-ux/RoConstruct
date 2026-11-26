// from server: 100% by Xemicl
// from server: 100% by tajop
// roc 2012-06 005658c0  unit: RBX::VInstance::$$A6AXV?$shared_ptr::?$signal::Vslot::?$callable  size: 475 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005658c0
//
// 005658c0  6aff                 push -1
// 005658c2  6870daa900           push 0xa9da70
// 005658c7  64a100000000         mov eax, dword ptr fs:[0]
// 005658cd  50                   push eax
// 005658ce  64892500000000       mov dword ptr fs:[0], esp
// 005658d5  83ec08               sub esp, 8
// 005658d8  53                   push ebx
// 005658d9  55                   push ebp
// 005658da  56                   push esi
// 005658db  8b742424             mov esi, dword ptr [esp + 0x24]
// 005658df  57                   push edi
// 005658e0  8b3e                 mov edi, dword ptr [esi]
// 005658e2  33db                 xor ebx, ebx
// 005658e4  8be9                 mov ebp, ecx
// 005658e6  897c2428             mov dword ptr [esp + 0x28], edi
// 005658ea  3bfb                 cmp edi, ebx
// 005658ec  740c                 je 0x5658fa
// 005658ee  8d4705               lea eax, [edi + 5]
// 005658f1  50                   push eax
// 005658f2  e8596eeaff           call 0x40c750
// 005658f7  83c404               add esp, 4
// 005658fa  6890225600           push 0x562290
// 005658ff  685043e200           push 0xe24350
// 00565904  895c2428             mov dword ptr [esp + 0x28], ebx
// 00565908  e893bce9ff           call 0x4015a0
// 0056590d  83c408               add esp, 8
// 00565910  f6054c43e20001       test byte ptr [0xe2434c], 1
// 00565917  7520                 jne 0x565939
// 00565919  830d4c43e20001       or dword ptr [0xe2434c], 1
// 00565920  68d043b100           push 0xb143d0
// 00565925  891d4443e200         mov dword ptr [0xe24344], ebx
// 0056592b  891d4843e200         mov dword ptr [0xe24348], ebx
// 00565931  e8bfd84100           call 0x9831f5
// 00565936  83c404               add esp, 4
// 00565939  8d4c2410             lea ecx, [esp + 0x10]
// 0056593d  c74424104443e200     mov dword ptr [esp + 0x10], 0xe24344
// 00565945  885c2414             mov byte ptr [esp + 0x14], bl
// 00565949  e842dfeaff           call 0x413890
// 0056594e  8b06                 mov eax, dword ptr [esi]
// 00565950  c644242001           mov byte ptr [esp + 0x20], 1
// 00565955  8bce                 mov ecx, esi
// 00565957  3bc3                 cmp eax, ebx
// 00565959  7503                 jne 0x56595e
// 0056595b  55                   push ebp
// 0056595c  eb04                 jmp 0x565962
// 0056595e  83c00c               add eax, 0xc
// 00565961  50                   push eax
// 00565962  e869d81600           call 0x6d31d0
// 00565967  885c2420             mov byte ptr [esp + 0x20], bl
// 0056596b  391e                 cmp dword ptr [esi], ebx
// 0056596d  0f8594000000         jne 0x565a07
// 00565973  385c2414             cmp byte ptr [esp + 0x14], bl
// 00565977  7432                 je 0x5659ab
// 00565979  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0056597d  b800000080           mov eax, 0x80000000
// 00565982  8bd1                 mov edx, ecx
// 00565984  f00fc102             lock xadd dword ptr [edx], eax
// 00565988  a900000040           test eax, 0x40000000
// 0056598d  751c                 jne 0x5659ab
// 0056598f  3d00000080           cmp eax, 0x80000000
// 00565994  7e15                 jle 0x5659ab
// 00565996  8bc1                 mov eax, ecx
// 00565998  f00fba281e           lock bts dword ptr [eax], 0x1e
// 0056599d  720c                 jb 0x5659ab
// 0056599f  e81c60eaff           call 0x40b9c0
// 005659a4  50                   push eax
// 005659a5  ff150c23b200         call dword ptr [0xb2230c]
// 005659ab  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 005659b3  3bfb                 cmp edi, ebx
// 005659b5  7439                 je 0x5659f0
// 005659b7  8d4705               lea eax, [edi + 5]
// 005659ba  3bc3                 cmp eax, ebx
// 005659bc  7405                 je 0x5659c3
// 005659be  8d48fb               lea ecx, [eax - 5]
// 005659c1  eb02                 jmp 0x5659c5
// 005659c3  33c9                 xor ecx, ecx
// 005659c5  8d71f8               lea esi, [ecx - 8]
// 005659c8  8bd6                 mov edx, esi
// 005659ca  83c8ff               or eax, 0xffffffff
// 005659cd  f00fc102             lock xadd dword ptr [edx], eax
// 005659d1  751d                 jne 0x5659f0
// 005659d3  8b11                 mov edx, dword ptr [ecx]
// 005659d5  8b02                 mov eax, dword ptr [edx]
// 005659d7  53                   push ebx
// 005659d8  ffd0                 call eax
// 005659da  8d4e04               lea ecx, [esi + 4]
// 005659dd  83caff               or edx, 0xffffffff
// 005659e0  f00fc111             lock xadd dword ptr [ecx], edx
// 005659e4  750a                 jne 0x5659f0
// 005659e6  56                   push esi
// 005659e7  ff15c829b200         call dword ptr [0xb229c8]
// 005659ed  83c404               add esp, 4
// 005659f0  5f                   pop edi
// 005659f1  5e                   pop esi
// 005659f2  5d                   pop ebp
// 005659f3  32c0                 xor al, al
// 005659f5  5b                   pop ebx
// 005659f6  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005659fa  64890d00000000       mov dword ptr fs:[0], ecx
// 00565a01  83c414               add esp, 0x14
// 00565a04  c20400               ret 4
// 00565a07  385c2414             cmp byte ptr [esp + 0x14], bl
// 00565a0b  7432                 je 0x565a3f
// 00565a0d  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00565a11  b800000080           mov eax, 0x80000000
// 00565a16  8bd1                 mov edx, ecx
// 00565a18  f00fc102             lock xadd dword ptr [edx], eax
// 00565a1c  a900000040           test eax, 0x40000000
// 00565a21  751c                 jne 0x565a3f
// 00565a23  3d00000080           cmp eax, 0x80000000
// 00565a28  7e15                 jle 0x565a3f
// 00565a2a  8bc1                 mov eax, ecx
// 00565a2c  f00fba281e           lock bts dword ptr [eax], 0x1e
// 00565a31  720c                 jb 0x565a3f
// 00565a33  e8885feaff           call 0x40b9c0
// 00565a38  50                   push eax
// 00565a39  ff150c23b200         call dword ptr [0xb2230c]
// 00565a3f  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 00565a47  3bfb                 cmp edi, ebx
// 00565a49  7439                 je 0x565a84
// 00565a4b  8d4705               lea eax, [edi + 5]
// 00565a4e  3bc3                 cmp eax, ebx
// 00565a50  7405                 je 0x565a57
// 00565a52  8d48fb               lea ecx, [eax - 5]
// 00565a55  eb02                 jmp 0x565a59
// 00565a57  33c9                 xor ecx, ecx
// 00565a59  8d71f8               lea esi, [ecx - 8]
// 00565a5c  8bd6                 mov edx, esi
// 00565a5e  83c8ff               or eax, 0xffffffff
// 00565a61  f00fc102             lock xadd dword ptr [edx], eax
// 00565a65  751d                 jne 0x565a84
// 00565a67  8b11                 mov edx, dword ptr [ecx]
// 00565a69  8b02                 mov eax, dword ptr [edx]
// 00565a6b  53                   push ebx
// 00565a6c  ffd0                 call eax
// 00565a6e  8d4e04               lea ecx, [esi + 4]
// 00565a71  83caff               or edx, 0xffffffff
// 00565a74  f00fc111             lock xadd dword ptr [ecx], edx
// 00565a78  750a                 jne 0x565a84
// 00565a7a  56                   push esi
// 00565a7b  ff15c829b200         call dword ptr [0xb229c8]
// 00565a81  83c404               add esp, 4
// 00565a84  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00565a88  5f                   pop edi
// 00565a89  5e                   pop esi
// 00565a8a  5d                   pop ebp
// 00565a8b  b001                 mov al, 1
// 00565a8d  5b                   pop ebx
// 00565a8e  64890d00000000       mov dword ptr fs:[0], ecx
// 00565a95  83c414               add esp, 0x14
// 00565a98  c20400               ret 4

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)
extern "C" unsigned char __cdecl _interlockedbittestandset(long*, long);
#pragma intrinsic(_interlockedbittestandset)
extern "C" int (__stdcall* SetEvent_ptr)(void*);
extern "C" void (__cdecl* free_ptr)(void*);

struct Empty {};
struct Base {};
struct Node;
void intrusive_ptr_add_ref(Base*);
void call_once(long&, void (*)());
void init_once();

struct Ptr {
    Node* px;
    Ptr(const Ptr& o);
    ~Ptr();
    Ptr& operator=(const Ptr& o);
};

struct Node : Empty, Base {
    virtual ~Node();
    int pad;
    Ptr next;
};

inline void intrusive_ptr_release(Base* p) {
    Node* n = static_cast<Node*>(p);
    long* c = (long*)((char*)n - 8);
    if (_InterlockedDecrement(c) == 0) {
        n->~Node();
        if (_InterlockedDecrement(c + 1) == 0)
            free_ptr(c);
    }
}

inline Ptr::Ptr(const Ptr& o) : px(o.px) {
    if (px)
        intrusive_ptr_add_ref(px);
}

inline Ptr::~Ptr() {
    if (px)
        intrusive_ptr_release(px);
}

struct Mutex {
    long count;
    void* event;
    Mutex() { count = 0; event = 0; }
    ~Mutex();
    void* get_event();
    void unlock() {
        long const offset = (long)0x80000000;
        long const old = _InterlockedExchangeAdd(&count, offset);
        if (!(old & 0x40000000) && old > offset) {
            if (!_interlockedbittestandset(&count, 30))
                SetEvent_ptr(get_event());
        }
    }
};

struct Lock {
    Mutex* m;
    bool locked;
    Lock(Mutex& mm) : m(&mm), locked(false) { lock(); }
    ~Lock() {
        if (locked)
            m->unlock();
    }
    void lock();
};

struct S {
    Ptr head;
    bool step(Ptr& cur);
};

bool S::step(Ptr& cur) {
    Ptr old(cur);
    static long flag = 0;
    call_once(flag, init_once);
    static Mutex m;
    Lock lock(m);
    if (!cur.px)
        cur = head;
    else
        cur = cur.px->next;
    if (!cur.px)
        return false;
    return true;
}
