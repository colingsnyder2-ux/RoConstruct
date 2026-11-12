// from server: 100% by EspClaude
// from server: 46% by colin
// roc 2007-08 0044e740  unit: CRobloxDoc  size: 173 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0044e740
//
// 0044e740  6aff                 push -1
// 0044e742  6898d97300           push 0x73d998
// 0044e747  64a100000000         mov eax, dword ptr fs:[0]
// 0044e74d  50                   push eax
// 0044e74e  83ec08               sub esp, 8
// 0044e751  56                   push esi
// 0044e752  a188518b00           mov eax, dword ptr [0x8b5188]
// 0044e757  33c4                 xor eax, esp
// 0044e759  50                   push eax
// 0044e75a  8d442410             lea eax, [esp + 0x10]
// 0044e75e  64a300000000         mov dword ptr fs:[0], eax
// 0044e764  8b742420             mov esi, dword ptr [esp + 0x20]
// 0044e768  897148               mov dword ptr [ecx + 0x48], esi
// 0044e76b  8b4978               mov ecx, dword ptr [ecx + 0x78]
// 0044e76e  85c9                 test ecx, ecx
// 0044e770  7468                 je 0x44e7da
// 0044e772  8d442408             lea eax, [esp + 8]
// 0044e776  50                   push eax
// 0044e777  e88450fbff           call 0x403800
// 0044e77c  8b00                 mov eax, dword ptr [eax]
// 0044e77e  8b9060010000         mov edx, dword ptr [eax + 0x160]
// 0044e784  8b5204               mov edx, dword ptr [edx + 4]
// 0044e787  8d8860010000         lea ecx, [eax + 0x160]
// 0044e78d  83fe01               cmp esi, 1
// 0044e790  0f94c0               sete al
// 0044e793  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0044e79b  50                   push eax
// 0044e79c  ffd2                 call edx
// 0044e79e  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0044e7a2  85c0                 test eax, eax
// 0044e7a4  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0044e7ac  742c                 je 0x44e7da
// 0044e7ae  8bf0                 mov esi, eax
// 0044e7b0  83c004               add eax, 4
// 0044e7b3  83c9ff               or ecx, 0xffffffff
// 0044e7b6  f00fc108             lock xadd dword ptr [eax], ecx
// 0044e7ba  751e                 jne 0x44e7da
// 0044e7bc  8b16                 mov edx, dword ptr [esi]
// 0044e7be  8b4204               mov eax, dword ptr [edx + 4]
// 0044e7c1  8bce                 mov ecx, esi
// 0044e7c3  ffd0                 call eax
// 0044e7c5  8d4e08               lea ecx, [esi + 8]
// 0044e7c8  83caff               or edx, 0xffffffff
// 0044e7cb  f00fc111             lock xadd dword ptr [ecx], edx
// 0044e7cf  7509                 jne 0x44e7da
// 0044e7d1  8b06                 mov eax, dword ptr [esi]
// 0044e7d3  8b5008               mov edx, dword ptr [eax + 8]
// 0044e7d6  8bce                 mov ecx, esi
// 0044e7d8  ffd2                 call edx
// 0044e7da  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0044e7de  64890d00000000       mov dword ptr fs:[0], ecx
// 0044e7e5  59                   pop ecx
// 0044e7e6  5e                   pop esi
// 0044e7e7  83c414               add esp, 0x14
// 0044e7ea  c20400               ret 4

extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

class sp_counted_base {
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
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
    long use_count_;
    long weak_count_;
};

class shared_count {
public:
    sp_counted_base* pi_;
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};

template<class T> class shared_ptr {
public:
    T* px;
    shared_count pn;
    T* operator->() const { return px; }
};

class ModeListener {
public:
    virtual void v0();
    virtual void setEnabled(bool on);   // vtable +4
};

class World {
public:
    char pad_0000[0x160];
    ModeListener listener;              // +0x160
};

class WorldHolder {
public:
    shared_ptr<World> getWorld();
};

class CRobloxDoc {
public:
    char pad_0000[0x48];
    int mode;                           // +0x48
    char pad_004c[0x78 - 0x4c];
    WorldHolder* holder;                // +0x78
    void setMode(int m);
};

void CRobloxDoc::setMode(int m)
{
    mode = m;
    if (holder != 0)
        holder->getWorld()->listener.setEnabled(m == 1);
}
