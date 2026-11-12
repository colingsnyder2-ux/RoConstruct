// from server: 100% by EspClaude
// from server: 48% by colin
// roc 2007-08 0040e850  unit: RBX::Network::VPlayer::?$FactoryProduct::Creator  size: 523 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040e850
//
// 0040e850  6aff                 push -1
// 0040e852  68389f7300           push 0x739f38
// 0040e857  64a100000000         mov eax, dword ptr fs:[0]
// 0040e85d  50                   push eax
// 0040e85e  83ec1c               sub esp, 0x1c
// 0040e861  53                   push ebx
// 0040e862  55                   push ebp
// 0040e863  56                   push esi
// 0040e864  57                   push edi
// 0040e865  a188518b00           mov eax, dword ptr [0x8b5188]
// 0040e86a  33c4                 xor eax, esp
// 0040e86c  50                   push eax
// 0040e86d  8d442430             lea eax, [esp + 0x30]
// 0040e871  64a300000000         mov dword ptr fs:[0], eax
// 0040e877  8bf1                 mov esi, ecx
// 0040e879  8b6c2440             mov ebp, dword ptr [esp + 0x40]
// 0040e87d  8d442414             lea eax, [esp + 0x14]
// 0040e881  55                   push ebp
// 0040e882  50                   push eax
// 0040e883  e8e8ed0800           call 0x49d670
// 0040e888  83c408               add esp, 8
// 0040e88b  8b08                 mov ecx, dword ptr [eax]
// 0040e88d  83c004               add eax, 4
// 0040e890  898e9c000000         mov dword ptr [esi + 0x9c], ecx
// 0040e896  33db                 xor ebx, ebx
// 0040e898  50                   push eax
// 0040e899  8d8ea0000000         lea ecx, [esi + 0xa0]
// 0040e89f  895c243c             mov dword ptr [esp + 0x3c], ebx
// 0040e8a3  e8b841ffff           call 0x402a60
// 0040e8a8  8b442418             mov eax, dword ptr [esp + 0x18]
// 0040e8ac  3bc3                 cmp eax, ebx
// 0040e8ae  c7442438ffffffff     mov dword ptr [esp + 0x38], 0xffffffff
// 0040e8b6  742c                 je 0x40e8e4
// 0040e8b8  8bf8                 mov edi, eax
// 0040e8ba  83c004               add eax, 4
// 0040e8bd  83caff               or edx, 0xffffffff
// 0040e8c0  f00fc110             lock xadd dword ptr [eax], edx
// 0040e8c4  751e                 jne 0x40e8e4
// 0040e8c6  8b07                 mov eax, dword ptr [edi]
// 0040e8c8  8b5004               mov edx, dword ptr [eax + 4]
// 0040e8cb  8bcf                 mov ecx, edi
// 0040e8cd  ffd2                 call edx
// 0040e8cf  8d4708               lea eax, [edi + 8]
// 0040e8d2  83c9ff               or ecx, 0xffffffff
// 0040e8d5  f00fc108             lock xadd dword ptr [eax], ecx
// 0040e8d9  7509                 jne 0x40e8e4
// 0040e8db  8b17                 mov edx, dword ptr [edi]
// 0040e8dd  8b4208               mov eax, dword ptr [edx + 8]
// 0040e8e0  8bcf                 mov ecx, edi
// 0040e8e2  ffd0                 call eax
// 0040e8e4  8b969c000000         mov edx, dword ptr [esi + 0x9c]
// 0040e8ea  83ec08               sub esp, 8
// 0040e8ed  8bcc                 mov ecx, esp
// 0040e8ef  8911                 mov dword ptr [ecx], edx
// 0040e8f1  8b86a0000000         mov eax, dword ptr [esi + 0xa0]
// 0040e8f7  3bc3                 cmp eax, ebx
// 0040e8f9  89642448             mov dword ptr [esp + 0x48], esp
// 0040e8fd  894104               mov dword ptr [ecx + 4], eax
// 0040e900  740c                 je 0x40e90e
// 0040e902  83c004               add eax, 4
// 0040e905  b901000000           mov ecx, 1
// 0040e90a  f00fc108             lock xadd dword ptr [eax], ecx
// 0040e90e  8d4c242c             lea ecx, [esp + 0x2c]
// 0040e912  e839ecffff           call 0x40d550
// 0040e917  8b868c000000         mov eax, dword ptr [esi + 0x8c]
// 0040e91d  3bc3                 cmp eax, ebx
// 0040e91f  c744243801000000     mov dword ptr [esp + 0x38], 1
// 0040e927  7452                 je 0x40e97b
// 0040e929  8998fc000000         mov dword ptr [eax + 0xfc], ebx
// 0040e92f  8b8e8c000000         mov ecx, dword ptr [esi + 0x8c]
// 0040e935  53                   push ebx
// 0040e936  e8f52c1300           call 0x541630
// 0040e93b  899e8c000000         mov dword ptr [esi + 0x8c], ebx
// 0040e941  8bbe90000000         mov edi, dword ptr [esi + 0x90]
// 0040e947  3bfb                 cmp edi, ebx
// 0040e949  899e90000000         mov dword ptr [esi + 0x90], ebx
// 0040e94f  742a                 je 0x40e97b
// 0040e951  8d5704               lea edx, [edi + 4]
// 0040e954  83c8ff               or eax, 0xffffffff
// 0040e957  f00fc102             lock xadd dword ptr [edx], eax
// 0040e95b  751e                 jne 0x40e97b
// 0040e95d  8b17                 mov edx, dword ptr [edi]
// 0040e95f  8b4204               mov eax, dword ptr [edx + 4]
// 0040e962  8bcf                 mov ecx, edi
// 0040e964  ffd0                 call eax
// 0040e966  8d4f08               lea ecx, [edi + 8]
// 0040e969  83caff               or edx, 0xffffffff
// 0040e96c  f00fc111             lock xadd dword ptr [ecx], edx
// 0040e970  7509                 jne 0x40e97b
// 0040e972  8b07                 mov eax, dword ptr [edi]
// 0040e974  8b5008               mov edx, dword ptr [eax + 8]
// 0040e977  8bcf                 mov ecx, edi
// 0040e979  ffd2                 call edx
// 0040e97b  3beb                 cmp ebp, ebx
// 0040e97d  8b442444             mov eax, dword ptr [esp + 0x44]
// 0040e981  898688000000         mov dword ptr [esi + 0x88], eax
// 0040e987  7409                 je 0x40e992
// 0040e989  8bcd                 mov ecx, ebp
// 0040e98b  e8c0fdffff           call 0x40e750
// 0040e990  eb02                 jmp 0x40e994
// 0040e992  33c0                 xor eax, eax
// 0040e994  3beb                 cmp ebp, ebx
// 0040e996  8986a4000000         mov dword ptr [esi + 0xa4], eax
// 0040e99c  747e                 je 0x40ea1c
// 0040e99e  8d4c241c             lea ecx, [esp + 0x1c]
// 0040e9a2  51                   push ecx
// 0040e9a3  e8e8efffff           call 0x40d990
// 0040e9a8  83c404               add esp, 4
// 0040e9ab  8b10                 mov edx, dword ptr [eax]
// 0040e9ad  83c004               add eax, 4
// 0040e9b0  50                   push eax
// 0040e9b1  8d8e90000000         lea ecx, [esi + 0x90]
// 0040e9b7  c644243c02           mov byte ptr [esp + 0x3c], 2
// 0040e9bc  89968c000000         mov dword ptr [esi + 0x8c], edx
// 0040e9c2  e89940ffff           call 0x402a60
// 0040e9c7  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0040e9cb  3bfb                 cmp edi, ebx
// 0040e9cd  c644243801           mov byte ptr [esp + 0x38], 1
// 0040e9d2  742a                 je 0x40e9fe
// 0040e9d4  8d4704               lea eax, [edi + 4]
// 0040e9d7  83c9ff               or ecx, 0xffffffff
// 0040e9da  f00fc108             lock xadd dword ptr [eax], ecx
// 0040e9de  751e                 jne 0x40e9fe
// 0040e9e0  8b17                 mov edx, dword ptr [edi]
// 0040e9e2  8b4204               mov eax, dword ptr [edx + 4]
// 0040e9e5  8bcf                 mov ecx, edi
// 0040e9e7  ffd0                 call eax
// 0040e9e9  8d4f08               lea ecx, [edi + 8]
// 0040e9ec  83caff               or edx, 0xffffffff
// 0040e9ef  f00fc111             lock xadd dword ptr [ecx], edx
// 0040e9f3  7509                 jne 0x40e9fe
// 0040e9f5  8b07                 mov eax, dword ptr [edi]
// 0040e9f7  8b5008               mov edx, dword ptr [eax + 8]
// 0040e9fa  8bcf                 mov ecx, edi

extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement, _InterlockedDecrement)

// boost 1.34 sp_counted_base: vtbl +4 dispose, +8 destroy; use +4, weak +8.
struct sp_counted_base {
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    long use_count_;
    long weak_count_;
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
};

struct shared_count {
    sp_counted_base* pi_;
    shared_count() : pi_(0) {}
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
    shared_count& operator=(const shared_count& r);   // 0x402a60
    void swap(shared_count& r) { sp_counted_base* t = r.pi_; r.pi_ = pi_; pi_ = t; }
};

template<class T> struct shared_ptr {
    T* px;
    shared_count pn;
    shared_ptr() : px(0) {}
    shared_ptr& operator=(const shared_ptr& r) { px = r.px; pn = r.pn; return *this; }
    void reset() { shared_ptr().swap(*this); }
    void swap(shared_ptr& o) { T* t = o.px; o.px = px; px = t; pn.swap(o.pn); }
    T* operator->() const { return px; }
    T* get() const { return px; }
};

struct Player;
struct Instance;

struct Controller {
    char pad[0xfc];
    Player* owner;                 // +0xfc
    void setTarget(void* t);       // 0x541630
};

struct Part;
struct Instance {
    char pad[0x1a8];
    void* m1a8;                    // +0x1a8
    Part* findPart();              // 0x40e750
};

struct Data;
shared_ptr<Data> getData(Instance* i);              // 0x49d670
shared_ptr<Controller> createController();          // 0x40d990

struct Lock {
    int pad[3];
    Lock(shared_ptr<Data> d);      // 0x40d550
    ~Lock();                       // 0x5595a0
};

struct Player {
    char pad0[0x20];
    void* m20;                          // +0x20
    char pad24[0x88 - 0x24];
    int m88;                            // +0x88
    shared_ptr<Controller> controller;  // +0x8c
    char pad94[0x9c - 0x94];
    shared_ptr<Data> data;              // +0x9c
    Part* part;                         // +0xa4
    void onChanged(int hasPart);       // 0x6302ec
    void setInstance(Instance* instance, int value);
};

void Player::setInstance(Instance* instance, int value)
{
    data = getData(instance);
    Lock lock(data);
    if (controller.get() != 0) {
        controller->owner = 0;
        controller->setTarget(0);
        controller.reset();
    }
    m88 = value;
    part = instance ? instance->findPart() : 0;
    if (instance) {
        controller = createController();
        controller->owner = this;
        controller->setTarget(instance->m1a8);
    }
    if (m20 != 0) {
        int has = (part != 0);
        onChanged(has);
    }
}
