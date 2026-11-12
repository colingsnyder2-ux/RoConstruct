// from server: 100% by EspClaude
// from server: 42% by colin
// roc 2007-08 0041b480  unit: VDHTMLWindowService::?$FactoryProduct::Creator  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0041b480
// 0041b480  6aff                 push -1
// 0041b482  686e887400           push 0x74886e
// 0041b487  64a100000000         mov eax, dword ptr fs:[0]
// 0041b48d  50                   push eax
// 0041b48e  83ec0c               sub esp, 0xc
// 0041b491  53                   push ebx
// 0041b492  56                   push esi
// 0041b493  a188518b00           mov eax, dword ptr [0x8b5188]
// 0041b498  33c4                 xor eax, esp
// 0041b49a  50                   push eax
// 0041b49b  8d442418             lea eax, [esp + 0x18]
// 0041b49f  64a300000000         mov dword ptr fs:[0], eax
// 0041b4a5  8bf1                 mov esi, ecx
// 0041b4a7  89742410             mov dword ptr [esp + 0x10], esi
// 0041b4ab  33db                 xor ebx, ebx
// 0041b4ad  891e                 mov dword ptr [esi], ebx
// 0041b4af  895e04               mov dword ptr [esi + 4], ebx
// 0041b4b2  8b442428             mov eax, dword ptr [esp + 0x28]
// 0041b4b6  8b10                 mov edx, dword ptr [eax]
// 0041b4b8  53                   push ebx
// 0041b4b9  83ec08               sub esp, 8
// 0041b4bc  8bcc                 mov ecx, esp
// 0041b4be  8911                 mov dword ptr [ecx], edx
// 0041b4c0  8b4004               mov eax, dword ptr [eax + 4]
// 0041b4c3  3bc3                 cmp eax, ebx
// 0041b4c5  895c242c             mov dword ptr [esp + 0x2c], ebx
// 0041b4c9  89642420             mov dword ptr [esp + 0x20], esp
// 0041b4cd  894104               mov dword ptr [ecx + 4], eax
// 0041b4d0  740c                 je 0x41b4de
// 0041b4d2  83c004               add eax, 4
// 0041b4d5  b901000000           mov ecx, 1
// 0041b4da  f00fc108             lock xadd dword ptr [eax], ecx
// 0041b4de  8d4e08               lea ecx, [esi + 8]
// 0041b4e1  e88afeffff           call 0x41b370
// 0041b4e6  6a20                 push 0x20
// 0041b4e8  c644242401           mov byte ptr [esp + 0x24], 1
// 0041b4ed  e8044a2100           call 0x62fef6
// 0041b4f2  83c404               add esp, 4
// 0041b4f5  3bc3                 cmp eax, ebx
// 0041b4f7  7414                 je 0x41b50d
// 0041b4f9  895804               mov dword ptr [eax + 4], ebx
// 0041b4fc  895808               mov dword ptr [eax + 8], ebx
// 0041b4ff  89580c               mov dword ptr [eax + 0xc], ebx
// 0041b502  895814               mov dword ptr [eax + 0x14], ebx
// 0041b505  895818               mov dword ptr [eax + 0x18], ebx
// 0041b508  88581c               mov byte ptr [eax + 0x1c], bl
// 0041b50b  eb02                 jmp 0x41b50f
// 0041b50d  33c0                 xor eax, eax
// 0041b50f  50                   push eax
// 0041b510  8bce                 mov ecx, esi
// 0041b512  c644242401           mov byte ptr [esp + 0x24], 1
// 0041b517  e894ccffff           call 0x4181b0
// 0041b51c  8bce                 mov ecx, esi
// 0041b51e  e80dd33000           call 0x728830
// 0041b523  8bc6                 mov eax, esi
// 0041b525  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0041b529  64890d00000000       mov dword ptr fs:[0], ecx
// 0041b530  59                   pop ecx
// 0041b531  5e                   pop esi
// 0041b532  5b                   pop ebx
// 0041b533  83c418               add esp, 0x18
// 0041b536  c20400               ret 4

#include <vector>

extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)

struct CountedBase {
    virtual void dispose() = 0;
    volatile long use_count;
    volatile long weak_count;
    void add_ref() { _InterlockedIncrement(&use_count); }
    void release();
};

template <class T>
struct SharedPtr {
    T* px;
    CountedBase* pn;
    SharedPtr() : px(0), pn(0) {}
    SharedPtr(const SharedPtr& r) : px(r.px), pn(r.pn) {
        if (pn != 0)
            pn->add_ref();
    }
    ~SharedPtr() {
        if (pn != 0)
            pn->release();
    }
};

struct Window;
struct Product;

struct Holder {
    std::vector<int> items;
    int f10;
    int f14;
    int f18;
    bool f1c;
    Holder() : f14(0), f18(0), f1c(false) {}
};

struct Binder {
    Binder(SharedPtr<Window> window, int flags);
    ~Binder();
    int storage[4];
};

struct Creator {
    SharedPtr<Product> product;
    Binder binder;

    Creator(const SharedPtr<Window>& window);
    void attach(Holder* holder);
    void start();
};

Creator::Creator(const SharedPtr<Window>& window)
    : binder(window, 0)
{
    attach(new Holder);
    start();
}
