// from server: 100% by EspClaude
// roc 2009-06 0042f9f0  unit: COutputView  size: 442 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0042f9f0
//
// 0042f9f0  6aff                 push -1
// 0042f9f2  64a100000000         mov eax, dword ptr fs:[0]
// 0042f9f8  6850f68400           push 0x84f650
// 0042f9fd  50                   push eax
// 0042f9fe  64892500000000       mov dword ptr fs:[0], esp
// 0042fa05  83ec38               sub esp, 0x38
// 0042fa08  53                   push ebx
// 0042fa09  55                   push ebp
// 0042fa0a  56                   push esi
// 0042fa0b  57                   push edi
// 0042fa0c  8bf1                 mov esi, ecx
// 0042fa0e  e87d9b2e00           call 0x719590
// 0042fa13  8bae18010000         mov ebp, dword ptr [esi + 0x118]
// 0042fa19  8d9e18010000         lea ebx, [esi + 0x118]
// 0042fa1f  33ff                 xor edi, edi
// 0042fa21  3be8                 cmp ebp, eax
// 0042fa23  7420                 je 0x42fa45
// 0042fa25  893b                 mov dword ptr [ebx], edi
// 0042fa27  3bc7                 cmp eax, edi
// 0042fa29  740d                 je 0x42fa38
// 0042fa2b  8b08                 mov ecx, dword ptr [eax]
// 0042fa2d  8b11                 mov edx, dword ptr [ecx]
// 0042fa2f  53                   push ebx
// 0042fa30  68dc308b00           push 0x8b30dc
// 0042fa35  50                   push eax
// 0042fa36  ffd2                 call edx
// 0042fa38  3bef                 cmp ebp, edi
// 0042fa3a  7409                 je 0x42fa45
// 0042fa3c  8b4500               mov eax, dword ptr [ebp]
// 0042fa3f  8b4808               mov ecx, dword ptr [eax + 8]
// 0042fa42  55                   push ebp
// 0042fa43  ffd1                 call ecx
// 0042fa45  8b03                 mov eax, dword ptr [ebx]
// 0042fa47  3bc7                 cmp eax, edi
// 0042fa49  0f842e010000         je 0x42fb7d
// 0042fa4f  897c2414             mov dword ptr [esp + 0x14], edi
// 0042fa53  8b10                 mov edx, dword ptr [eax]
// 0042fa55  8b5220               mov edx, dword ptr [edx + 0x20]
// 0042fa58  8d4c2414             lea ecx, [esp + 0x14]
// 0042fa5c  51                   push ecx
// 0042fa5d  50                   push eax
// 0042fa5e  897c2458             mov dword ptr [esp + 0x58], edi
// 0042fa62  ffd2                 call edx
// 0042fa64  897c2410             mov dword ptr [esp + 0x10], edi
// 0042fa68  8d442428             lea eax, [esp + 0x28]
// 0042fa6c  50                   push eax
// 0042fa6d  ff1510ea8900         call dword ptr [0x89ea10]
// 0042fa73  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0042fa77  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0042fa7b  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 0042fa7f  8b5c2430             mov ebx, dword ptr [esp + 0x30]
// 0042fa83  894c2444             mov dword ptr [esp + 0x44], ecx
// 0042fa87  33d2                 xor edx, edx
// 0042fa89  68b0128b00           push 0x8b12b0
// 0042fa8e  8d4c241c             lea ecx, [esp + 0x1c]
// 0042fa92  c644245402           mov byte ptr [esp + 0x54], 2
// 0042fa97  668954241c           mov word ptr [esp + 0x1c], dx
// 0042fa9c  e81f69feff           call 0x4163c0
// 0042faa1  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0042faa5  8b11                 mov edx, dword ptr [ecx]
// 0042faa7  8d442410             lea eax, [esp + 0x10]
// 0042faab  50                   push eax
// 0042faac  83ec10               sub esp, 0x10
// 0042faaf  8bc4                 mov eax, esp
// 0042fab1  8938                 mov dword ptr [eax], edi
// 0042fab3  8b7c2458             mov edi, dword ptr [esp + 0x58]
// 0042fab7  896804               mov dword ptr [eax + 4], ebp
// 0042faba  895808               mov dword ptr [eax + 8], ebx
// 0042fabd  89780c               mov dword ptr [eax + 0xc], edi
// 0042fac0  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0042fac4  83ec10               sub esp, 0x10
// 0042fac7  8bc4                 mov eax, esp
// 0042fac9  8938                 mov dword ptr [eax], edi
// 0042facb  8b7c2440             mov edi, dword ptr [esp + 0x40]
// 0042facf  897804               mov dword ptr [eax + 4], edi
// 0042fad2  8b7c2444             mov edi, dword ptr [esp + 0x44]
// 0042fad6  897808               mov dword ptr [eax + 8], edi
// 0042fad9  8b7c2448             mov edi, dword ptr [esp + 0x48]
// 0042fadd  51                   push ecx
// 0042fade  8b4a2c               mov ecx, dword ptr [edx + 0x2c]
// 0042fae1  c644247803           mov byte ptr [esp + 0x78], 3
// 0042fae6  89780c               mov dword ptr [eax + 0xc], edi
// 0042fae9  ffd1                 call ecx
// 0042faeb  8b3d28ea8900         mov edi, dword ptr [0x89ea28]
// 0042faf1  8d542418             lea edx, [esp + 0x18]
// 0042faf5  52                   push edx
// 0042faf6  ffd7                 call edi
// 0042faf8  8d442428             lea eax, [esp + 0x28]
// 0042fafc  50                   push eax
// 0042fafd  c644245401           mov byte ptr [esp + 0x54], 1
// 0042fb02  ffd7                 call edi
// 0042fb04  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0042fb08  8d861c010000         lea eax, [esi + 0x11c]
// 0042fb0e  8b30                 mov esi, dword ptr [eax]
// 0042fb10  3bf1                 cmp esi, ecx
// 0042fb12  742b                 je 0x42fb3f
// 0042fb14  c70000000000         mov dword ptr [eax], 0
// 0042fb1a  85c9                 test ecx, ecx
// 0042fb1c  7411                 je 0x42fb2f
// 0042fb1e  8b11                 mov edx, dword ptr [ecx]
// 0042fb20  50                   push eax
// 0042fb21  8b02                 mov eax, dword ptr [edx]
// 0042fb23  6818358b00           push 0x8b3518
// 0042fb28  51                   push ecx
// 0042fb29  ffd0                 call eax
// 0042fb2b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0042fb2f  85f6                 test esi, esi
// 0042fb31  740c                 je 0x42fb3f
// 0042fb33  8b0e                 mov ecx, dword ptr [esi]
// 0042fb35  8b5108               mov edx, dword ptr [ecx + 8]
// 0042fb38  56                   push esi
// 0042fb39  ffd2                 call edx
// 0042fb3b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0042fb3f  c644245000           mov byte ptr [esp + 0x50], 0
// 0042fb44  85c9                 test ecx, ecx
// 0042fb46  7408                 je 0x42fb50
// 0042fb48  8b01                 mov eax, dword ptr [ecx]
// 0042fb4a  51                   push ecx
// 0042fb4b  8b4808               mov ecx, dword ptr [eax + 8]
// 0042fb4e  ffd1                 call ecx
// 0042fb50  8b442414             mov eax, dword ptr [esp + 0x14]
// 0042fb54  c7442450ffffffff     mov dword ptr [esp + 0x50], 0xffffffff
// 0042fb5c  85c0                 test eax, eax
// 0042fb5e  7435                 je 0x42fb95
// 0042fb60  8b10                 mov edx, dword ptr [eax]
// 0042fb62  50                   push eax
// 0042fb63  8b4208               mov eax, dword ptr [edx + 8]
// 0042fb66  ffd0                 call eax
// 0042fb68  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 0042fb6c  64890d00000000       mov dword ptr fs:[0], ecx
// 0042fb73  5f                   pop edi
// 0042fb74  5e                   pop esi
// 0042fb75  5d                   pop ebp
// 0042fb76  5b                   pop ebx
// 0042fb77  83c444               add esp, 0x44
// 0042fb7a  c20400               ret 4
// 0042fb7d  8b861c010000         mov eax, dword ptr [esi + 0x11c]
// 0042fb83  3bc7                 cmp eax, edi
// 0042fb85  740e                 je 0x42fb95
// 0042fb87  89be1c010000         mov dword ptr [esi + 0x11c], edi
// 0042fb8d  8b08                 mov ecx, dword ptr [eax]
// 0042fb8f  8b5108               mov edx, dword ptr [ecx + 8]
// 0042fb92  50                   push eax
// 0042fb93  ffd2                 call edx
// 0042fb95  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 0042fb99  5f                   pop edi
// 0042fb9a  5e                   pop esi
// 0042fb9b  5d                   pop ebp
// 0042fb9c  64890d00000000       mov dword ptr fs:[0], ecx
// 0042fba3  5b                   pop ebx
// 0042fba4  83c444               add esp, 0x44
// 0042fba7  c20400               ret 4
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
