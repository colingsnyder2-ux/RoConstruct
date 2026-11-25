// from server: 100% by Xemicl
// from server: 100% by tajop
// roc 2012-06 007dd8f0  unit: RBX::VObjectValue::?$EventDesc  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007dd8f0
//
// 007dd8f0  8b442404             mov eax, dword ptr [esp + 4]
// 007dd8f4  83ec08               sub esp, 8
// 007dd8f7  56                   push esi
// 007dd8f8  8bf1                 mov esi, ecx
// 007dd8fa  50                   push eax
// 007dd8fb  8d4c2408             lea ecx, [esp + 8]
// 007dd8ff  e89cfdffff           call 0x7dd6a0
// 007dd904  3bc6                 cmp eax, esi
// 007dd906  7408                 je 0x7dd910
// 007dd908  8b16                 mov edx, dword ptr [esi]
// 007dd90a  8b08                 mov ecx, dword ptr [eax]
// 007dd90c  8910                 mov dword ptr [eax], edx
// 007dd90e  890e                 mov dword ptr [esi], ecx
// 007dd910  8b4e04               mov ecx, dword ptr [esi + 4]
// 007dd913  8b5004               mov edx, dword ptr [eax + 4]
// 007dd916  895604               mov dword ptr [esi + 4], edx
// 007dd919  894804               mov dword ptr [eax + 4], ecx
// 007dd91c  8b742408             mov esi, dword ptr [esp + 8]
// 007dd920  85f6                 test esi, esi
// 007dd922  742a                 je 0x7dd94e
// 007dd924  8d4604               lea eax, [esi + 4]
// 007dd927  83c9ff               or ecx, 0xffffffff
// 007dd92a  f00fc108             lock xadd dword ptr [eax], ecx
// 007dd92e  751e                 jne 0x7dd94e
// 007dd930  8b16                 mov edx, dword ptr [esi]
// 007dd932  8b4204               mov eax, dword ptr [edx + 4]
// 007dd935  8bce                 mov ecx, esi
// 007dd937  ffd0                 call eax
// 007dd939  8d4e08               lea ecx, [esi + 8]
// 007dd93c  83caff               or edx, 0xffffffff
// 007dd93f  f00fc111             lock xadd dword ptr [ecx], edx
// 007dd943  7509                 jne 0x7dd94e
// 007dd945  8b06                 mov eax, dword ptr [esi]
// 007dd947  8b5008               mov edx, dword ptr [eax + 8]
// 007dd94a  8bce                 mov ecx, esi
// 007dd94c  ffd2                 call edx
// 007dd94e  5e                   pop esi
// 007dd94f  83c408               add esp, 8
// 007dd952  c20400               ret 4



extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct sp_counted_base {
    long use_count_;
    long weak_count_;
    virtual ~sp_counted_base();
    virtual void dispose();
    virtual void destroy();
    void weak_release();
    void release();
};

inline void sp_counted_base::weak_release()
{
    if (_InterlockedDecrement(&weak_count_) == 0) {
        destroy();
    }
}

inline void sp_counted_base::release()
{
    if (_InterlockedDecrement(&use_count_) == 0) {
        dispose();
        weak_release();
    }
}

struct shared_count {
    sp_counted_base* pi_;
    ~shared_count();
    void swap(shared_count& r);
};

inline shared_count::~shared_count()
{
    if (pi_ != 0) {
        pi_->release();
    }
}

inline void shared_count::swap(shared_count& r)
{
    sp_counted_base* tmp = r.pi_;
    r.pi_ = pi_;
    pi_ = tmp;
}

struct T;

inline void swap_ptr(T*& left, T*& right)
{
    if (&left != &right) {
        T* tmp = left;
        left = right;
        right = tmp;
    }
}

struct S {
    T* px;
    shared_count pn;
    S(T* p);
    void swap(S& other);
    void reset(T* p);
};

inline void S::swap(S& other)
{
    swap_ptr(px, other.px);
    pn.swap(other.pn);
}

void S::reset(T* p)
{
    S(p).swap(*this);
}
