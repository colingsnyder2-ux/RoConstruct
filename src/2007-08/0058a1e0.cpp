// from server: 86% by EspClaude
// from server: 42% by TrollStein
// roc 2007-08 0058a1e0  unit: VStockSound::?$FactoryProduct  size: 490 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0058a1e0
// 0058a1e0  6aff                 push -1
// 0058a1e2  6874617500           push 0x756174
// 0058a1e7  64a100000000         mov eax, dword ptr fs:[0]
// 0058a1ed  50                   push eax
// 0058a1ee  64892500000000       mov dword ptr fs:[0], esp
// 0058a1f5  83ec14               sub esp, 0x14
// 0058a1f8  53                   push ebx
// 0058a1f9  55                   push ebp
// 0058a1fa  56                   push esi
// 0058a1fb  57                   push edi
// 0058a1fc  8bd9                 mov ebx, ecx
// 0058a1fe  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0058a206  807c245800           cmp byte ptr [esp + 0x58], 0
// 0058a20b  c744242c01000000     mov dword ptr [esp + 0x2c], 1
// 0058a213  8dbb2c010000         lea edi, [ebx + 0x12c]
// 0058a219  7506                 jne 0x58a221
// 0058a21b  8dbb20010000         lea edi, [ebx + 0x120]
// 0058a221  8d442438             lea eax, [esp + 0x38]
// 0058a225  50                   push eax
// 0058a226  8d4c2418             lea ecx, [esp + 0x18]
// 0058a22a  51                   push ecx
// 0058a22b  8bcf                 mov ecx, edi
// 0058a22d  e8feecffff           call 0x588f30
// 0058a232  8b742414             mov esi, dword ptr [esp + 0x14]
// 0058a236  85f6                 test esi, esi
// 0058a238  8b5704               mov edx, dword ptr [edi + 4]
// 0058a23b  89542420             mov dword ptr [esp + 0x20], edx
// 0058a23f  7404                 je 0x58a245
// 0058a241  3bf7                 cmp esi, edi
// 0058a243  7406                 je 0x58a24b
// 0058a245  ff15d8e67700         call dword ptr [0x77e6d8]
// 0058a24b  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0058a24f  3b6c2420             cmp ebp, dword ptr [esp + 0x20]
// 0058a253  7462                 je 0x58a2b7
// 0058a255  85f6                 test esi, esi
// 0058a257  7506                 jne 0x58a25f
// 0058a259  ff15d8e67700         call dword ptr [0x77e6d8]
// 0058a25f  3b6e04               cmp ebp, dword ptr [esi + 4]
// 0058a262  7506                 jne 0x58a26a
// 0058a264  ff15d8e67700         call dword ptr [0x77e6d8]
// 0058a26a  8b452c               mov eax, dword ptr [ebp + 0x2c]
// 0058a26d  8b742434             mov esi, dword ptr [esp + 0x34]
// 0058a271  8906                 mov dword ptr [esi], eax
// 0058a273  8b4530               mov eax, dword ptr [ebp + 0x30]
// 0058a276  85c0                 test eax, eax
// 0058a278  894604               mov dword ptr [esi + 4], eax
// 0058a27b  740c                 je 0x58a289
// 0058a27d  83c004               add eax, 4
// 0058a280  b901000000           mov ecx, 1
// 0058a285  f00fc108             lock xadd dword ptr [eax], ecx
// 0058a289  8d4c2438             lea ecx, [esp + 0x38]
// 0058a28d  c744241001000000     mov dword ptr [esp + 0x10], 1
// 0058a295  c644242c00           mov byte ptr [esp + 0x2c], 0
// 0058a29a  ff15ace67700         call dword ptr [0x77e6ac]
// 0058a2a0  8bc6                 mov eax, esi
// 0058a2a2  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0058a2a6  64890d00000000       mov dword ptr fs:[0], ecx
// 0058a2ad  5f                   pop edi
// 0058a2ae  5e                   pop esi
// 0058a2af  5d                   pop ebp
// 0058a2b0  5b                   pop ebx
// 0058a2b1  83c420               add esp, 0x20
// 0058a2b4  c22800               ret 0x28
// 0058a2b7  6a30                 push 0x30
// 0058a2b9  e8385c0a00           call 0x62fef6
// 0058a2be  8be8                 mov ebp, eax
// 0058a2c0  83c404               add esp, 4
// 0058a2c3  896c2414             mov dword ptr [esp + 0x14], ebp
// 0058a2c7  85ed                 test ebp, ebp
// 0058a2c9  c644242c02           mov byte ptr [esp + 0x2c], 2
// 0058a2ce  7434                 je 0x58a304
// 0058a2d0  8b542458             mov edx, dword ptr [esp + 0x58]
// 0058a2d4  52                   push edx
// 0058a2d5  83ec20               sub esp, 0x20
// 0058a2d8  8bf4                 mov esi, esp
// 0058a2da  8d44245c             lea eax, [esp + 0x5c]
// 0058a2de  8964247c             mov dword ptr [esp + 0x7c], esp
// 0058a2e2  50                   push eax
// 0058a2e3  8bce                 mov ecx, esi
// 0058a2e5  ff159ce67700         call dword ptr [0x77e69c]
// 0058a2eb  8b4c2478             mov ecx, dword ptr [esp + 0x78]
// 0058a2ef  894e1c               mov dword ptr [esi + 0x1c], ecx
// 0058a2f2  8b93ec000000         mov edx, dword ptr [ebx + 0xec]
// 0058a2f8  52                   push edx
// 0058a2f9  8bcd                 mov ecx, ebp
// 0058a2fb  e8f0daffff           call 0x587df0
// 0058a300  8bf0                 mov esi, eax
// 0058a302  eb02                 jmp 0x58a306
// 0058a304  33f6                 xor esi, esi
// 0058a306  56                   push esi
// 0058a307  8d4c241c             lea ecx, [esp + 0x1c]
// 0058a30b  c644243001           mov byte ptr [esp + 0x30], 1
// 0058a310  89742418             mov dword ptr [esp + 0x18], esi
// 0058a314  e867eaffff           call 0x588d80
// 0058a319  56                   push esi
// 0058a31a  8d44241c             lea eax, [esp + 0x1c]
// 0058a31e  56                   push esi
// 0058a31f  50                   push eax
// 0058a320  e8fb28e8ff           call 0x40cc20
// 0058a325  83c40c               add esp, 0xc
// 0058a328  8d4c2438             lea ecx, [esp + 0x38]
// 0058a32c  51                   push ecx
// 0058a32d  8bcf                 mov ecx, edi
// 0058a32f  c644243003           mov byte ptr [esp + 0x30], 3
// 0058a334  e8d7fdffff           call 0x58a110
// 0058a339  8b742414             mov esi, dword ptr [esp + 0x14]
// 0058a33d  8d542418             lea edx, [esp + 0x18]
// 0058a341  52                   push edx
// 0058a342  8d4804               lea ecx, [eax + 4]
// 0058a345  8930                 mov dword ptr [eax], esi
// 0058a347  e81487e7ff           call 0x402a60
// 0058a34c  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 0058a350  8937                 mov dword ptr [edi], esi
// 0058a352  8b742418             mov esi, dword ptr [esp + 0x18]
// 0058a356  85f6                 test esi, esi
// 0058a358  897704               mov dword ptr [edi + 4], esi
// 0058a35b  740c                 je 0x58a369
// 0058a35d  8d4604               lea eax, [esi + 4]
// 0058a360  b901000000           mov ecx, 1
// 0058a365  f00fc108             lock xadd dword ptr [eax], ecx
// 0058a369  85f6                 test esi, esi
// 0058a36b  c744241001000000     mov dword ptr [esp + 0x10], 1
// 0058a373  c644242c01           mov byte ptr [esp + 0x2c], 1
// 0058a378  742a                 je 0x58a3a4
// 0058a37a  8d5604               lea edx, [esi + 4]
// 0058a37d  83c8ff               or eax, 0xffffffff
// 0058a380  f00fc102             lock xadd dword ptr [edx], eax
// 0058a384  751e                 jne 0x58a3a4
// 0058a386  8b16                 mov edx, dword ptr [esi]
// 0058a388  8b4204               mov eax, dword ptr [edx + 4]
// 0058a38b  8bce                 mov ecx, esi
// 0058a38d  ffd0                 call eax
// 0058a38f  8d4e08               lea ecx, [esi + 8]
// 0058a392  83caff               or edx, 0xffffffff
// 0058a395  f00fc111             lock xadd dword ptr [ecx], edx
// 0058a399  7509                 jne 0x58a3a4
// 0058a39b  8b06                 mov eax, dword ptr [esi]
// 0058a39d  8b5008               mov edx, dword ptr [eax + 8]
// 0058a3a0  8bce                 mov ecx, esi
// 0058a3a2  ffd2                 call edx
// 0058a3a4  8d4c2438             lea ecx, [esp + 0x38]
// 0058a3a8  c644242c00           mov byte ptr [esp + 0x2c], 0
// 0058a3ad  ff15ace67700         call dword ptr [0x77e6ac]
// 0058a3b3  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0058a3b7  8bc7                 mov eax, edi
// 0058a3b9  5f                   pop edi
// 0058a3ba  5e                   pop esi
// 0058a3bb  5d                   pop ebp
// 0058a3bc  64890d00000000       mov dword ptr fs:[0], ecx
// 0058a3c3  5b                   pop ebx
// 0058a3c4  83c420               add esp, 0x20
// 0058a3c7  c22800               ret 0x28

// roc-flags: /O2 /GS- /EHsc /MD
#include <map>
#include <string>

extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)

class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
private:
    long use_count_;
    long weak_count_;
};

class shared_count {
public:
    shared_count() : pi_(0) {}
    template <class Y> explicit shared_count(Y* p);
    shared_count(const shared_count& r) : pi_(r.pi_) {
        if (pi_ != 0)
            pi_->add_ref_copy();
    }
    ~shared_count() {
        if (pi_ != 0)
            pi_->release();
    }
    shared_count& operator=(const shared_count& r);
private:
    sp_counted_base* pi_;
};

inline void sp_enable_shared_from_this(const shared_count&, ...) {}

template <class T>
class shared_ptr {
public:
    shared_ptr() : px(0), pn() {}
    template <class Y> explicit shared_ptr(Y* p) : px(p), pn(p) {
        sp_enable_shared_from_this(pn, p, p);
    }
    T* px;
    shared_count pn;
};

struct ContentId {
    std::string id;
    int kind;
};

bool operator<(const ContentId& a, const ContentId& b);

struct StockSound {
    StockSound(void* owner, ContentId id, bool stock);
    char storage[0x30];
};

typedef std::map<ContentId, shared_ptr<StockSound> > SoundMap;

struct SoundFactory {
    char pad0[0xec];
    void* owner;
    char pad1[0x120 - 0xf0];
    SoundMap sounds;
    SoundMap stockSounds;

    shared_ptr<StockSound> getSound(ContentId id, bool stock);
};

shared_ptr<StockSound> SoundFactory::getSound(ContentId id, bool stock)
{
    SoundMap& m = stock ? stockSounds : sounds;
    SoundMap::iterator it = m.find(id);
    if (it != m.end())
        return it->second;
    else {
        shared_ptr<StockSound> sound(new StockSound(owner, id, stock));
        m[id] = sound;
        return sound;
    }
}
