// from server: 100% by EspClaude
// roc-flags: /O2 /GS- /EHsc /MD
// from server: 51% by colin
// roc 2007-08 005f5fa0  unit: G3D::VColor3::V?$Value::?$FactoryProduct  size: 238 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005f5fa0
//
// 005f5fa0  64a100000000         mov eax, dword ptr fs:[0]
// 005f5fa6  6aff                 push -1
// 005f5fa8  68d8bc7500           push 0x75bcd8
// 005f5fad  50                   push eax
// 005f5fae  8b442410             mov eax, dword ptr [esp + 0x10]
// 005f5fb2  64892500000000       mov dword ptr fs:[0], esp
// 005f5fb9  83ec08               sub esp, 8
// 005f5fbc  56                   push esi
// 005f5fbd  8bf1                 mov esi, ecx
// 005f5fbf  8b8ee8000000         mov ecx, dword ptr [esi + 0xe8]
// 005f5fc5  3bc8                 cmp ecx, eax
// 005f5fc7  57                   push edi
// 005f5fc8  0f84ad000000         je 0x5f607b
// 005f5fce  50                   push eax
// 005f5fcf  8d44240c             lea eax, [esp + 0xc]
// 005f5fd3  50                   push eax
// 005f5fd4  e89776eaff           call 0x49d670
// 005f5fd9  83c408               add esp, 8
// 005f5fdc  8b08                 mov ecx, dword ptr [eax]
// 005f5fde  83c004               add eax, 4
// 005f5fe1  898ee8000000         mov dword ptr [esi + 0xe8], ecx
// 005f5fe7  50                   push eax
// 005f5fe8  8d8eec000000         lea ecx, [esi + 0xec]
// 005f5fee  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 005f5ff6  e865cae0ff           call 0x402a60
// 005f5ffb  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005f5fff  85c0                 test eax, eax
// 005f6001  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 005f6009  742c                 je 0x5f6037
// 005f600b  8bf8                 mov edi, eax
// 005f600d  83c004               add eax, 4
// 005f6010  83caff               or edx, 0xffffffff
// 005f6013  f00fc110             lock xadd dword ptr [eax], edx
// 005f6017  751e                 jne 0x5f6037
// 005f6019  8b07                 mov eax, dword ptr [edi]
// 005f601b  8b5004               mov edx, dword ptr [eax + 4]
// 005f601e  8bcf                 mov ecx, edi
// 005f6020  ffd2                 call edx
// 005f6022  8d4708               lea eax, [edi + 8]
// 005f6025  83c9ff               or ecx, 0xffffffff
// 005f6028  f00fc108             lock xadd dword ptr [eax], ecx
// 005f602c  7509                 jne 0x5f6037
// 005f602e  8b17                 mov edx, dword ptr [edi]
// 005f6030  8b4208               mov eax, dword ptr [edx + 8]
// 005f6033  8bcf                 mov ecx, edi
// 005f6035  ffd0                 call eax
// 005f6037  68f07d8c00           push 0x8c7df0
// 005f603c  8bce                 mov ecx, esi
// 005f603e  e8cde6e4ff           call 0x444710
// 005f6043  8b96e8000000         mov edx, dword ptr [esi + 0xe8]
// 005f6049  83ec08               sub esp, 8
// 005f604c  8bc4                 mov eax, esp
// 005f604e  8910                 mov dword ptr [eax], edx
// 005f6050  8d4e04               lea ecx, [esi + 4]
// 005f6053  8bb6ec000000         mov esi, dword ptr [esi + 0xec]
// 005f6059  85f6                 test esi, esi
// 005f605b  89642428             mov dword ptr [esp + 0x28], esp
// 005f605f  897004               mov dword ptr [eax + 4], esi
// 005f6062  740c                 je 0x5f6070
// 005f6064  83c604               add esi, 4
// 005f6067  b801000000           mov eax, 1
// 005f606c  f00fc106             lock xadd dword ptr [esi], eax
// 005f6070  51                   push ecx
// 005f6071  b9cc7d8c00           mov ecx, 0x8c7dcc
// 005f6076  e895fae9ff           call 0x495b10
// 005f607b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005f607f  5f                   pop edi
// 005f6080  64890d00000000       mov dword ptr fs:[0], ecx
// 005f6087  5e                   pop esi
// 005f6088  83c414               add esp, 0x14
// 005f608b  c20400               ret 4

extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)

// boost-style counted base: dispose at vtable +4, destroy at +8, counts at +4/+8.
struct sp_counted_base {
    virtual void unused0();
    virtual void dispose();
    virtual void destroy();
    long use_count;
    long weak_count;
    void weak_release() { if (_InterlockedDecrement(&weak_count) == 0) destroy(); }
    void release() { if (_InterlockedDecrement(&use_count) == 0) { dispose(); weak_release(); } }
};

struct shared_count {
    sp_counted_base* pi;
    shared_count(const shared_count& r) : pi(r.pi) { if (pi != 0) _InterlockedIncrement(&pi->use_count); }
    ~shared_count() { if (pi != 0) pi->release(); }
    shared_count& operator=(const shared_count& r);     // 00402a60 (out of line)
};

struct Color3;

struct ColorPtr {
    Color3* px;
    shared_count pn;
    ColorPtr& operator=(const ColorPtr& r) { px = r.px; pn = r.pn; return *this; }
    Color3* get() const { return px; }
};

ColorPtr makeShared(Color3* value);                       // 0049d670 (cdecl, hidden ret)

struct PropertyDescriptor;
extern PropertyDescriptor g_valueDescriptor;              // 008c7df0

struct Reflected { virtual void reflectedVfn(); };

struct ChangedSignal {
    void fire(Reflected* source, ColorPtr value);         // 00495b10 (thiscall)
};
extern ChangedSignal g_valueChanged;                      // 008c7dcc

struct InstanceBase { virtual void instanceVfn(); };

class ColorValue : public InstanceBase, public Reflected {
public:
    void raisePropertyChanged(const PropertyDescriptor& desc);   // 00444710
    void setValue(Color3* value);
private:
    char pad8[0xe8 - 8];
    ColorPtr m_value;            // +0xe8
};

void ColorValue::setValue(Color3* value)
{
    if (m_value.get() != value) {
        m_value = makeShared(value);
        raisePropertyChanged(g_valueDescriptor);
        g_valueChanged.fire(this, m_value);
    }
}
