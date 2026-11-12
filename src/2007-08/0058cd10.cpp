// from server: 100% by EspClaude
// repaired: onServiceProvider listener/stats-item shape, /GS-
// roc 2007-08 0058cd10  unit: RBX::SoundService  size: 359 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0058cd10
//
// 0058cd10  64a100000000         mov eax, dword ptr fs:[0]
// 0058cd16  6aff                 push -1
// 0058cd18  68d8bc7500           push 0x75bcd8
// 0058cd1d  50                   push eax
// 0058cd1e  64892500000000       mov dword ptr fs:[0], esp
// 0058cd25  83ec08               sub esp, 8
// 0058cd28  53                   push ebx
// 0058cd29  56                   push esi
// 0058cd2a  8bf1                 mov esi, ecx
// 0058cd2c  33db                 xor ebx, ebx
// 0058cd2e  3bf3                 cmp esi, ebx
// 0058cd30  57                   push edi
// 0058cd31  7408                 je 0x58cd3b
// 0058cd33  8dbee8000000         lea edi, [esi + 0xe8]
// 0058cd39  eb02                 jmp 0x58cd3d
// 0058cd3b  33ff                 xor edi, edi
// 0058cd3d  55                   push ebp
// 0058cd3e  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 0058cd42  3beb                 cmp ebp, ebx
// 0058cd44  7417                 je 0x58cd5d
// 0058cd46  8bcd                 mov ecx, ebp
// 0058cd48  e8b33fecff           call 0x450d00
// 0058cd4d  3bc3                 cmp eax, ebx
// 0058cd4f  740c                 je 0x58cd5d
// 0058cd51  57                   push edi
// 0058cd52  8d88e8000000         lea ecx, [eax + 0xe8]
// 0058cd58  e8d357eaff           call 0x432530
// 0058cd5d  8b8e0c010000         mov ecx, dword ptr [esi + 0x10c]
// 0058cd63  3bcb                 cmp ecx, ebx
// 0058cd65  7446                 je 0x58cdad
// 0058cd67  53                   push ebx
// 0058cd68  e8c348fbff           call 0x541630
// 0058cd6d  899e0c010000         mov dword ptr [esi + 0x10c], ebx
// 0058cd73  8bbe10010000         mov edi, dword ptr [esi + 0x110]
// 0058cd79  3bfb                 cmp edi, ebx
// 0058cd7b  899e10010000         mov dword ptr [esi + 0x110], ebx
// 0058cd81  742a                 je 0x58cdad
// 0058cd83  8d4704               lea eax, [edi + 4]
// 0058cd86  83c9ff               or ecx, 0xffffffff
// 0058cd89  f00fc108             lock xadd dword ptr [eax], ecx
// 0058cd8d  751e                 jne 0x58cdad
// 0058cd8f  8b17                 mov edx, dword ptr [edi]
// 0058cd91  8b4204               mov eax, dword ptr [edx + 4]
// 0058cd94  8bcf                 mov ecx, edi
// 0058cd96  ffd0                 call eax
// 0058cd98  8d4f08               lea ecx, [edi + 8]
// 0058cd9b  83caff               or edx, 0xffffffff
// 0058cd9e  f00fc111             lock xadd dword ptr [ecx], edx
// 0058cda2  7509                 jne 0x58cdad
// 0058cda4  8b07                 mov eax, dword ptr [edi]
// 0058cda6  8b5008               mov edx, dword ptr [eax + 8]
// 0058cda9  8bcf                 mov ecx, edi
// 0058cdab  ffd2                 call edx
// 0058cdad  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0058cdb1  57                   push edi
// 0058cdb2  55                   push ebp
// 0058cdb3  8bce                 mov ecx, esi
// 0058cdb5  e896dcfeff           call 0x57aa50
// 0058cdba  3bfb                 cmp edi, ebx
// 0058cdbc  747c                 je 0x58ce3a
// 0058cdbe  8bcf                 mov ecx, edi
// 0058cdc0  e8eb86ecff           call 0x4554b0
// 0058cdc5  8be8                 mov ebp, eax
// 0058cdc7  3beb                 cmp ebp, ebx
// 0058cdc9  746f                 je 0x58ce3a
// 0058cdcb  8d442410             lea eax, [esp + 0x10]
// 0058cdcf  56                   push esi
// 0058cdd0  50                   push eax
// 0058cdd1  e8eaf6ffff           call 0x58c4c0
// 0058cdd6  83c408               add esp, 8
// 0058cdd9  8b08                 mov ecx, dword ptr [eax]
// 0058cddb  83c004               add eax, 4
// 0058cdde  898e0c010000         mov dword ptr [esi + 0x10c], ecx
// 0058cde4  50                   push eax
// 0058cde5  8d8e10010000         lea ecx, [esi + 0x110]
// 0058cdeb  895c2424             mov dword ptr [esp + 0x24], ebx
// 0058cdef  e86c5ce7ff           call 0x402a60
// 0058cdf4  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 0058cdf8  85db                 test ebx, ebx
// 0058cdfa  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 0058ce02  742a                 je 0x58ce2e
// 0058ce04  8d5304               lea edx, [ebx + 4]
// 0058ce07  83c8ff               or eax, 0xffffffff
// 0058ce0a  f00fc102             lock xadd dword ptr [edx], eax
// 0058ce0e  751e                 jne 0x58ce2e
// 0058ce10  8b13                 mov edx, dword ptr [ebx]
// 0058ce12  8b4204               mov eax, dword ptr [edx + 4]
// 0058ce15  8bcb                 mov ecx, ebx
// 0058ce17  ffd0                 call eax
// 0058ce19  8d4b08               lea ecx, [ebx + 8]
// 0058ce1c  83caff               or edx, 0xffffffff
// 0058ce1f  f00fc111             lock xadd dword ptr [ecx], edx
// 0058ce23  7509                 jne 0x58ce2e
// 0058ce25  8b03                 mov eax, dword ptr [ebx]
// 0058ce27  8b5008               mov edx, dword ptr [eax + 8]
// 0058ce2a  8bcb                 mov ecx, ebx
// 0058ce2c  ffd2                 call edx
// 0058ce2e  8b8e0c010000         mov ecx, dword ptr [esi + 0x10c]
// 0058ce34  55                   push ebp
// 0058ce35  e8f647fbff           call 0x541630
// 0058ce3a  85ff                 test edi, edi
// 0058ce3c  8d9ee8000000         lea ebx, [esi + 0xe8]
// 0058ce42  5d                   pop ebp
// 0058ce43  741e                 je 0x58ce63
// 0058ce45  8bcf                 mov ecx, edi
// 0058ce47  e8b43eecff           call 0x450d00
// 0058ce4c  85c0                 test eax, eax
// 0058ce4e  740c                 je 0x58ce5c
// 0058ce50  53                   push ebx
// 0058ce51  8d88e8000000         lea ecx, [eax + 0xe8]
// 0058ce57  e8e463e9ff           call 0x423240
// 0058ce5c  8bce                 mov ecx, esi
// 0058ce5e  e8cdfcffff           call 0x58cb30
// 0058ce63  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0058ce67  5f                   pop edi
// 0058ce68  5e                   pop esi
// 0058ce69  5b                   pop ebx
// 0058ce6a  64890d00000000       mov dword ptr fs:[0], ecx
// 0058ce71  83c414               add esp, 0x14
// 0058ce74  c20800               ret 8

// roc-flags: /O2 /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct sp_counted_base {
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    long use_count_;
    long weak_count_;
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            if (_InterlockedDecrement(&weak_count_) == 0)
                destroy();
        }
    }
};

struct shared_count {
    sp_counted_base* pi_;
    shared_count() : pi_(0) {}
    ~shared_count() { if (pi_ != 0) pi_->release(); }
    shared_count& operator=(const shared_count& r);   // 0x402a60, not inlined
    void swap(shared_count& r) { sp_counted_base* tmp = r.pi_; r.pi_ = pi_; pi_ = tmp; }
};

template <class T> struct shared_ptr {
    T* px;
    shared_count pn;
    shared_ptr() : px(0), pn() {}
    template <class Y> shared_ptr& operator=(const shared_ptr<Y>& r) { px = r.px; pn = r.pn; return *this; }
    void reset() { shared_ptr().swap(*this); }
    void swap(shared_ptr& other) { T* tmp = px; px = other.px; other.px = tmp; pn.swap(other.pn); }
    T* operator->() const { return px; }
    operator bool() const { return px != 0; }
};

class Instance;
class ServiceProvider;

class Listener {
public:
    char pad[0x24];
};

class Notifier {
public:
    void removeListener(Listener* l);     // 0x432530
    void addListener(Listener& l);        // 0x423240
};

class NotifierService {
public:
    char pad[0xe8];
    Notifier notifier;                     // +0xe8
};

class Stats;

class ServiceProvider {
public:
    NotifierService* findNotifierService() const;   // 0x450d00, thiscall
    Stats* createStats() const;                     // 0x4554b0, thiscall
};

class Instance {
public:
    void setParent(Instance* parent);      // 0x541630
};

class StatsItem : public Instance {
};

class Service {
public:
    virtual void onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider);  // 0x57aa50
    char pad[0xe4];
};

class SoundService : public Service, public Listener {
public:
    shared_ptr<StatsItem> statsItem;      // +0x10c / +0x110
    virtual void onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider);
    void updateListener();                 // 0x58cb30
};

class Stats : public Instance {
};

shared_ptr<StatsItem> __cdecl createStatsItem(SoundService* service);   // 0x58c4c0, cdecl, hidden return slot

void SoundService::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
{
    Listener* listener = this;
    if (oldProvider) {
        NotifierService* s = oldProvider->findNotifierService();
        if (s)
            s->notifier.removeListener(listener);
    }

    if (statsItem) {
        statsItem->setParent(0);
        statsItem.reset();
    }

    Service::onServiceProvider(oldProvider, newProvider);

    if (newProvider) {
        Stats* stats = newProvider->createStats();
        if (stats) {
            statsItem = createStatsItem(this);
            statsItem->setParent(stats);
        }
    }

    Listener& self = *this;
    if (newProvider) {
        NotifierService* s = newProvider->findNotifierService();
        if (s)
            s->notifier.addListener(self);
        updateListener();
    }
}
