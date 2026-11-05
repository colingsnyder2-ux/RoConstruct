// from server: 98% by EspClaude
// from server: 100% by colin
// roc 2008-06 004364b0  unit: COutputView  size: 442 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004364b0
//
// 004364b0  6aff                 push -1
// 004364b2  64a100000000         mov eax, dword ptr fs:[0]
// 004364b8  6870017c00           push 0x7c0170
// 004364bd  50                   push eax
// 004364be  64892500000000       mov dword ptr fs:[0], esp
// 004364c5  83ec38               sub esp, 0x38
// 004364c8  53                   push ebx
// 004364c9  55                   push ebp
// 004364ca  56                   push esi
// 004364cb  57                   push edi
// 004364cc  8bf1                 mov esi, ecx
// 004364ce  e8adaa2600           call 0x6a0f80
// 004364d3  8bae18010000         mov ebp, dword ptr [esi + 0x118]
// 004364d9  8d9e18010000         lea ebx, [esi + 0x118]
// 004364df  33ff                 xor edi, edi
// 004364e1  3be8                 cmp ebp, eax
// 004364e3  7420                 je 0x436505
// 004364e5  893b                 mov dword ptr [ebx], edi
// 004364e7  3bc7                 cmp eax, edi
// 004364e9  740d                 je 0x4364f8
// 004364eb  8b08                 mov ecx, dword ptr [eax]
// 004364ed  8b11                 mov edx, dword ptr [ecx]
// 004364ef  53                   push ebx
// 004364f0  686c058100           push 0x81056c
// 004364f5  50                   push eax
// 004364f6  ffd2                 call edx
// 004364f8  3bef                 cmp ebp, edi
// 004364fa  7409                 je 0x436505
// 004364fc  8b4500               mov eax, dword ptr [ebp]
// 004364ff  8b4808               mov ecx, dword ptr [eax + 8]
// 00436502  55                   push ebp
// 00436503  ffd1                 call ecx
// 00436505  8b03                 mov eax, dword ptr [ebx]
// 00436507  3bc7                 cmp eax, edi
// 00436509  0f842e010000         je 0x43663d
// 0043650f  897c2414             mov dword ptr [esp + 0x14], edi
// 00436513  8b10                 mov edx, dword ptr [eax]
// 00436515  8b5220               mov edx, dword ptr [edx + 0x20]
// 00436518  8d4c2414             lea ecx, [esp + 0x14]
// 0043651c  51                   push ecx
// 0043651d  50                   push eax
// 0043651e  897c2458             mov dword ptr [esp + 0x58], edi
// 00436522  ffd2                 call edx
// 00436524  897c2410             mov dword ptr [esp + 0x10], edi
// 00436528  8d442428             lea eax, [esp + 0x28]
// 0043652c  50                   push eax
// 0043652d  ff15f4288000         call dword ptr [0x8028f4]
// 00436533  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 00436537  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0043653b  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 0043653f  8b5c2430             mov ebx, dword ptr [esp + 0x30]
// 00436543  894c2444             mov dword ptr [esp + 0x44], ecx
// 00436547  33d2                 xor edx, edx
// 00436549  68fc2f8100           push 0x812ffc
// 0043654e  8d4c241c             lea ecx, [esp + 0x1c]
// 00436552  c644245402           mov byte ptr [esp + 0x54], 2
// 00436557  668954241c           mov word ptr [esp + 0x1c], dx
// 0043655c  e80ff8fdff           call 0x415d70
// 00436561  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00436565  8b11                 mov edx, dword ptr [ecx]
// 00436567  8d442410             lea eax, [esp + 0x10]
// 0043656b  50                   push eax
// 0043656c  83ec10               sub esp, 0x10
// 0043656f  8bc4                 mov eax, esp
// 00436571  8938                 mov dword ptr [eax], edi
// 00436573  8b7c2458             mov edi, dword ptr [esp + 0x58]
// 00436577  896804               mov dword ptr [eax + 4], ebp
// 0043657a  895808               mov dword ptr [eax + 8], ebx
// 0043657d  89780c               mov dword ptr [eax + 0xc], edi
// 00436580  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00436584  83ec10               sub esp, 0x10
// 00436587  8bc4                 mov eax, esp
// 00436589  8938                 mov dword ptr [eax], edi
// 0043658b  8b7c2440             mov edi, dword ptr [esp + 0x40]
// 0043658f  897804               mov dword ptr [eax + 4], edi
// 00436592  8b7c2444             mov edi, dword ptr [esp + 0x44]
// 00436596  897808               mov dword ptr [eax + 8], edi
// 00436599  8b7c2448             mov edi, dword ptr [esp + 0x48]
// 0043659d  51                   push ecx
// 0043659e  8b4a2c               mov ecx, dword ptr [edx + 0x2c]
// 004365a1  c644247803           mov byte ptr [esp + 0x78], 3
// 004365a6  89780c               mov dword ptr [eax + 0xc], edi
// 004365a9  ffd1                 call ecx
// 004365ab  8b3d1c298000         mov edi, dword ptr [0x80291c]
// 004365b1  8d542418             lea edx, [esp + 0x18]
// 004365b5  52                   push edx
// 004365b6  ffd7                 call edi
// 004365b8  8d442428             lea eax, [esp + 0x28]
// 004365bc  50                   push eax
// 004365bd  c644245401           mov byte ptr [esp + 0x54], 1
// 004365c2  ffd7                 call edi
// 004365c4  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004365c8  8d861c010000         lea eax, [esi + 0x11c]
// 004365ce  8b30                 mov esi, dword ptr [eax]
// 004365d0  3bf1                 cmp esi, ecx
// 004365d2  742b                 je 0x4365ff
// 004365d4  c70000000000         mov dword ptr [eax], 0
// 004365da  85c9                 test ecx, ecx
// 004365dc  7411                 je 0x4365ef
// 004365de  8b11                 mov edx, dword ptr [ecx]
// 004365e0  50                   push eax
// 004365e1  8b02                 mov eax, dword ptr [edx]
// 004365e3  68982f8100           push 0x812f98
// 004365e8  51                   push ecx
// 004365e9  ffd0                 call eax
// 004365eb  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004365ef  85f6                 test esi, esi
// 004365f1  740c                 je 0x4365ff
// 004365f3  8b0e                 mov ecx, dword ptr [esi]
// 004365f5  8b5108               mov edx, dword ptr [ecx + 8]
// 004365f8  56                   push esi
// 004365f9  ffd2                 call edx
// 004365fb  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004365ff  c644245000           mov byte ptr [esp + 0x50], 0
// 00436604  85c9                 test ecx, ecx
// 00436606  7408                 je 0x436610
// 00436608  8b01                 mov eax, dword ptr [ecx]
// 0043660a  51                   push ecx
// 0043660b  8b4808               mov ecx, dword ptr [eax + 8]
// 0043660e  ffd1                 call ecx
// 00436610  8b442414             mov eax, dword ptr [esp + 0x14]
// 00436614  c7442450ffffffff     mov dword ptr [esp + 0x50], 0xffffffff
// 0043661c  85c0                 test eax, eax
// 0043661e  7435                 je 0x436655
// 00436620  8b10                 mov edx, dword ptr [eax]
// 00436622  50                   push eax
// 00436623  8b4208               mov eax, dword ptr [edx + 8]
// 00436626  ffd0                 call eax
// 00436628  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 0043662c  64890d00000000       mov dword ptr fs:[0], ecx
// 00436633  5f                   pop edi
// 00436634  5e                   pop esi
// 00436635  5d                   pop ebp
// 00436636  5b                   pop ebx
// 00436637  83c444               add esp, 0x44
// 0043663a  c20400               ret 4
// 0043663d  8b861c010000         mov eax, dword ptr [esi + 0x11c]
// 00436643  3bc7                 cmp eax, edi
// 00436645  740e                 je 0x436655
// 00436647  89be1c010000         mov dword ptr [esi + 0x11c], edi
// 0043664d  8b08                 mov ecx, dword ptr [eax]
// 0043664f  8b5108               mov edx, dword ptr [ecx + 8]
// 00436652  50                   push eax
// 00436653  ffd2                 call edx
// 00436655  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 00436659  5f                   pop edi
// 0043665a  5e                   pop esi
// 0043665b  5d                   pop ebp
// 0043665c  64890d00000000       mov dword ptr fs:[0], ecx
// 00436663  5b                   pop ebx
// 00436664  83c444               add esp, 0x44
// 00436667  c20400               ret 4

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
