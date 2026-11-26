// from server: 100% by Xemicl
// roc 2012-06 0044df80  unit: COutputView  size: 442 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0044df80
//
// 0044df80  6aff                 push -1
// 0044df82  64a100000000         mov eax, dword ptr fs:[0]
// 0044df88  68f0e5a900           push 0xa9e5f0
// 0044df8d  50                   push eax
// 0044df8e  64892500000000       mov dword ptr fs:[0], esp
// 0044df95  83ec38               sub esp, 0x38
// 0044df98  53                   push ebx
// 0044df99  55                   push ebp
// 0044df9a  56                   push esi
// 0044df9b  57                   push edi
// 0044df9c  8bf1                 mov esi, ecx
// 0044df9e  e8a54c5300           call 0x982c48
// 0044dfa3  8bae18010000         mov ebp, dword ptr [esi + 0x118]
// 0044dfa9  8d9e18010000         lea ebx, [esi + 0x118]
// 0044dfaf  33ff                 xor edi, edi
// 0044dfb1  3be8                 cmp ebp, eax
// 0044dfb3  7420                 je 0x44dfd5
// 0044dfb5  893b                 mov dword ptr [ebx], edi
// 0044dfb7  3bc7                 cmp eax, edi
// 0044dfb9  740d                 je 0x44dfc8
// 0044dfbb  8b08                 mov ecx, dword ptr [eax]
// 0044dfbd  8b11                 mov edx, dword ptr [ecx]
// 0044dfbf  53                   push ebx
// 0044dfc0  68f42bb500           push 0xb52bf4
// 0044dfc5  50                   push eax
// 0044dfc6  ffd2                 call edx
// 0044dfc8  3bef                 cmp ebp, edi
// 0044dfca  7409                 je 0x44dfd5
// 0044dfcc  8b4500               mov eax, dword ptr [ebp]
// 0044dfcf  8b4808               mov ecx, dword ptr [eax + 8]
// 0044dfd2  55                   push ebp
// 0044dfd3  ffd1                 call ecx
// 0044dfd5  8b03                 mov eax, dword ptr [ebx]
// 0044dfd7  3bc7                 cmp eax, edi
// 0044dfd9  0f842e010000         je 0x44e10d
// 0044dfdf  897c2414             mov dword ptr [esp + 0x14], edi
// 0044dfe3  8b10                 mov edx, dword ptr [eax]
// 0044dfe5  8b5220               mov edx, dword ptr [edx + 0x20]
// 0044dfe8  8d4c2414             lea ecx, [esp + 0x14]
// 0044dfec  51                   push ecx
// 0044dfed  50                   push eax
// 0044dfee  897c2458             mov dword ptr [esp + 0x58], edi
// 0044dff2  ffd2                 call edx
// 0044dff4  897c2410             mov dword ptr [esp + 0x10], edi
// 0044dff8  8d442428             lea eax, [esp + 0x28]
// 0044dffc  50                   push eax
// 0044dffd  ff15582bb200         call dword ptr [0xb22b58]
// 0044e003  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0044e007  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0044e00b  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 0044e00f  8b5c2430             mov ebx, dword ptr [esp + 0x30]
// 0044e013  894c2444             mov dword ptr [esp + 0x44], ecx
// 0044e017  33d2                 xor edx, edx
// 0044e019  68e800b500           push 0xb500e8
// 0044e01e  8d4c241c             lea ecx, [esp + 0x1c]
// 0044e022  c644245402           mov byte ptr [esp + 0x54], 2
// 0044e027  668954241c           mov word ptr [esp + 0x1c], dx
// 0044e02c  e89fd5fcff           call 0x41b5d0
// 0044e031  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0044e035  8b11                 mov edx, dword ptr [ecx]
// 0044e037  8d442410             lea eax, [esp + 0x10]
// 0044e03b  50                   push eax
// 0044e03c  83ec10               sub esp, 0x10
// 0044e03f  8bc4                 mov eax, esp
// 0044e041  8938                 mov dword ptr [eax], edi
// 0044e043  8b7c2458             mov edi, dword ptr [esp + 0x58]
// 0044e047  896804               mov dword ptr [eax + 4], ebp
// 0044e04a  895808               mov dword ptr [eax + 8], ebx
// 0044e04d  89780c               mov dword ptr [eax + 0xc], edi
// 0044e050  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0044e054  83ec10               sub esp, 0x10
// 0044e057  8bc4                 mov eax, esp
// 0044e059  8938                 mov dword ptr [eax], edi
// 0044e05b  8b7c2440             mov edi, dword ptr [esp + 0x40]
// 0044e05f  897804               mov dword ptr [eax + 4], edi
// 0044e062  8b7c2444             mov edi, dword ptr [esp + 0x44]
// 0044e066  897808               mov dword ptr [eax + 8], edi
// 0044e069  8b7c2448             mov edi, dword ptr [esp + 0x48]
// 0044e06d  51                   push ecx
// 0044e06e  8b4a2c               mov ecx, dword ptr [edx + 0x2c]
// 0044e071  c644247803           mov byte ptr [esp + 0x78], 3
// 0044e076  89780c               mov dword ptr [eax + 0xc], edi
// 0044e079  ffd1                 call ecx
// 0044e07b  8b3d2c2bb200         mov edi, dword ptr [0xb22b2c]
// 0044e081  8d542418             lea edx, [esp + 0x18]
// 0044e085  52                   push edx
// 0044e086  ffd7                 call edi
// 0044e088  8d442428             lea eax, [esp + 0x28]
// 0044e08c  50                   push eax
// 0044e08d  c644245401           mov byte ptr [esp + 0x54], 1
// 0044e092  ffd7                 call edi
// 0044e094  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0044e098  8d861c010000         lea eax, [esi + 0x11c]
// 0044e09e  8b30                 mov esi, dword ptr [eax]
// 0044e0a0  3bf1                 cmp esi, ecx
// 0044e0a2  742b                 je 0x44e0cf
// 0044e0a4  c70000000000         mov dword ptr [eax], 0
// 0044e0aa  85c9                 test ecx, ecx
// 0044e0ac  7411                 je 0x44e0bf
// 0044e0ae  8b11                 mov edx, dword ptr [ecx]
// 0044e0b0  50                   push eax
// 0044e0b1  8b02                 mov eax, dword ptr [edx]
// 0044e0b3  68bc30b500           push 0xb530bc
// 0044e0b8  51                   push ecx
// 0044e0b9  ffd0                 call eax
// 0044e0bb  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0044e0bf  85f6                 test esi, esi
// 0044e0c1  740c                 je 0x44e0cf
// 0044e0c3  8b0e                 mov ecx, dword ptr [esi]
// 0044e0c5  8b5108               mov edx, dword ptr [ecx + 8]
// 0044e0c8  56                   push esi
// 0044e0c9  ffd2                 call edx
// 0044e0cb  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0044e0cf  c644245000           mov byte ptr [esp + 0x50], 0
// 0044e0d4  85c9                 test ecx, ecx
// 0044e0d6  7408                 je 0x44e0e0
// 0044e0d8  8b01                 mov eax, dword ptr [ecx]
// 0044e0da  51                   push ecx
// 0044e0db  8b4808               mov ecx, dword ptr [eax + 8]
// 0044e0de  ffd1                 call ecx
// 0044e0e0  8b442414             mov eax, dword ptr [esp + 0x14]
// 0044e0e4  c7442450ffffffff     mov dword ptr [esp + 0x50], 0xffffffff
// 0044e0ec  85c0                 test eax, eax
// 0044e0ee  7435                 je 0x44e125
// 0044e0f0  8b10                 mov edx, dword ptr [eax]
// 0044e0f2  50                   push eax
// 0044e0f3  8b4208               mov eax, dword ptr [edx + 8]
// 0044e0f6  ffd0                 call eax
// 0044e0f8  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 0044e0fc  64890d00000000       mov dword ptr fs:[0], ecx
// 0044e103  5f                   pop edi
// 0044e104  5e                   pop esi
// 0044e105  5d                   pop ebp
// 0044e106  5b                   pop ebx
// 0044e107  83c444               add esp, 0x44
// 0044e10a  c20400               ret 4
// 0044e10d  8b861c010000         mov eax, dword ptr [esi + 0x11c]
// 0044e113  3bc7                 cmp eax, edi
// 0044e115  740e                 je 0x44e125
// 0044e117  89be1c010000         mov dword ptr [esi + 0x11c], edi
// 0044e11d  8b08                 mov ecx, dword ptr [eax]
// 0044e11f  8b5108               mov edx, dword ptr [ecx + 8]
// 0044e122  50                   push eax
// 0044e123  ffd2                 call edx
// 0044e125  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 0044e129  5f                   pop edi
// 0044e12a  5e                   pop esi
// 0044e12b  5d                   pop ebp
// 0044e12c  64890d00000000       mov dword ptr fs:[0], ecx
// 0044e133  5b                   pop ebx
// 0044e134  83c444               add esp, 0x44
// 0044e137  c20400               ret 4
// copied from an identical function in another client (function ?update@COutputView@ns_ROCX000015@@QAEXH@Z)

namespace ns_ROCX000015 {
// from server: 92% by colin
// roc 2008-06 004364b0  unit: COutputView  size: 442 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004364b0
//

// from server: 89% by king_originala
// roc 2008-06 004364b0  unit: COutputView  size: 442 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004364b0
//

struct Guid {
    unsigned long a;
    unsigned short b, c;
    unsigned char d[8];
};

extern const Guid objectId;
extern const Guid outputId;

struct VariantData {
    unsigned short type;
    unsigned short reserved1, reserved2, reserved3;
    unsigned long value1, value2;
};

extern "C" {
    __declspec(dllimport) void __stdcall VariantInit(VariantData *);
    __declspec(dllimport) long __stdcall VariantClear(VariantData *);
}

struct Variant : VariantData {
    Variant();
    Variant(const char *);
    ~Variant() { VariantClear(this); }
    void assign(const char *);
};

inline Variant::Variant() {
    VariantInit(this);
}

inline Variant::Variant(const char *text) {
    type = 0;
    assign(text);
}

struct Object;

struct ObjectTable {
    long (__stdcall *query)(Object *, const Guid &, Object **);
    unsigned long (__stdcall *retain)(Object *);
    unsigned long (__stdcall *release)(Object *);
    void *unused3;
    void *unused4;
    void *unused5;
    void *unused6;
    void *unused7;
    long (__stdcall *get)(Object *, Object **);
    void *unused9;
    void *unused10;
    long (__stdcall *create)(Object *, VariantData, VariantData, Object **);
};

struct Object {
    ObjectTable *table;
};

struct Pointer {
    Object *value;
    Pointer();
    ~Pointer();
};

inline Pointer::Pointer() : value(0) {
}

inline Pointer::~Pointer() {
    if (value)
        value->table->release(value);
}

struct COutputView {
    unsigned char padding[0x118];
    Object *object;
    Object *output;

    Object *getObject();
    void update(int);
};

void COutputView::update(int) {
    Object *next = getObject();
    Object *previous = object;

    if (previous != next) {
        object = 0;
        if (next)
            next->table->query(next, objectId, &object);
        if (previous)
            previous->table->release(previous);
    }

    if (object) {
        Pointer source;
        object->table->get(object, &source.value);

        Pointer result;
        {
            Variant argument;
            VariantData argumentValue = argument;
            Variant name("output");
            source.value->table->create(
                source.value, name, argumentValue, &result.value);
        }

        Object *old = output;
        if (old != result.value) {
            output = 0;
            if (result.value)
                result.value->table->query(
                    result.value, outputId, &output);
            if (old)
                old->table->release(old);
        }
    } else {
        Object *old = output;
        if (old) {
            output = 0;
            old->table->release(old);
        }
    }
}
}