// from server: 100% by king_originala
// from server: 93% by king_originala
// roc 2008-06 0059d8a0  unit: VCRenderSettings::?$EnumPropDescriptor  size: 163 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0059d8a0
//
// 0059d8a0  83ec30               sub esp, 0x30
// 0059d8a3  53                   push ebx
// 0059d8a4  56                   push esi
// 0059d8a5  8bf1                 mov esi, ecx
// 0059d8a7  57                   push edi
// 0059d8a8  8dbe28020000         lea edi, [esi + 0x228]
// 0059d8ae  8bcf                 mov ecx, edi
// 0059d8b0  e80baa0400           call 0x5e82c0
// 0059d8b5  8b5c2440             mov ebx, dword ptr [esp + 0x40]
// 0059d8b9  50                   push eax
// 0059d8ba  8bcb                 mov ecx, ebx
// 0059d8bc  e81f8dedff           call 0x4765e0
// 0059d8c1  84c0                 test al, al
// 0059d8c3  7475                 je 0x59d93a
// 0059d8c5  53                   push ebx
// 0059d8c6  8d4c2410             lea ecx, [esp + 0x10]
// 0059d8ca  e85159f7ff           call 0x513220
// 0059d8cf  d94324               fld dword ptr [ebx + 0x24]
// 0059d8d2  d95c2430             fstp dword ptr [esp + 0x30]
// 0059d8d6  8d44240c             lea eax, [esp + 0xc]
// 0059d8da  d94328               fld dword ptr [ebx + 0x28]
// 0059d8dd  50                   push eax
// 0059d8de  d95c2438             fstp dword ptr [esp + 0x38]
// 0059d8e2  d9432c               fld dword ptr [ebx + 0x2c]
// 0059d8e5  d95c243c             fstp dword ptr [esp + 0x3c]
// 0059d8e9  e8b2170400           call 0x5df0a0
// 0059d8ee  83c404               add esp, 4
// 0059d8f1  8bcf                 mov ecx, edi
// 0059d8f3  e8c8a90400           call 0x5e82c0
// 0059d8f8  50                   push eax
// 0059d8f9  8d4c2410             lea ecx, [esp + 0x10]
// 0059d8fd  e8de8cedff           call 0x4765e0
// 0059d902  84c0                 test al, al
// 0059d904  741c                 je 0x59d922
// 0059d906  8d4c240c             lea ecx, [esp + 0xc]
// 0059d90a  51                   push ecx
// 0059d90b  8bcf                 mov ecx, edi
// 0059d90d  e8eea80400           call 0x5e8200
// 0059d912  c6869803000001       mov byte ptr [esi + 0x398], 1
// 0059d919  8b16                 mov edx, dword ptr [esi]
// 0059d91b  8b4250               mov eax, dword ptr [edx + 0x50]
// 0059d91e  8bce                 mov ecx, esi
// 0059d920  ffd0                 call eax
// 0059d922  6898619700           push 0x976198
// 0059d927  8bce                 mov ecx, esi
// 0059d929  e8d201e7ff           call 0x40db00
// 0059d92e  68ac5f9700           push 0x975fac
// 0059d933  8bce                 mov ecx, esi
// 0059d935  e8c601e7ff           call 0x40db00
// 0059d93a  5f                   pop edi
// 0059d93b  5e                   pop esi
// 0059d93c  5b                   pop ebx
// 0059d93d  83c430               add esp, 0x30
// 0059d940  c20400               ret 4

struct Matrix {
    float elements[9];
    Matrix(const Matrix&);
};

struct Frame {
    Matrix rotation;
    float x, y, z;

    bool different(const Frame&) const;
};

struct FrameStorage {
    char data[0x170];

    const Frame& get();
    void set(const Frame&);
};

extern bool __cdecl normalize(Frame*);
extern const int descriptor976198;
extern const int descriptor975fac;

struct S;

struct VTable {
    void* entries[20];
    void (__thiscall *changed)(S*);
};

struct S {
    VTable* volatile vtable;
    char padding[0x224];
    FrameStorage frame;
    volatile bool dirty;

    void notify(const int*);
    void update(const Frame*);
};

void S::update(const Frame* value)
{
    FrameStorage* storage = &frame;
    const Frame& current=storage->get();
    const Frame* source=value;
    if (source->different(current)) {
        Frame temporary(*source);
        normalize(&temporary);

        if (temporary.different(storage->get())) {
            storage->set(temporary);
            dirty = true;
            vtable->changed(this);
        }

        notify(&descriptor976198);
        notify(&descriptor975fac);
    }
}

