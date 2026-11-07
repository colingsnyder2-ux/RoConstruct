// from server: 100% by Intel
// from server: 98% by EspClaude
// roc 2007-08 004373b0  unit: COutputView  size: 435 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004373b0
//
// 004373b0  6aff                 push -1
// 004373b2  68c0e37300           push 0x73e3c0
// 004373b7  64a100000000         mov eax, dword ptr fs:[0]
// 004373bd  50                   push eax
// 004373be  83ec38               sub esp, 0x38
// 004373c1  53                   push ebx
// 004373c2  55                   push ebp
// 004373c3  56                   push esi
// 004373c4  57                   push edi
// 004373c5  a188518b00           mov eax, dword ptr [0x8b5188]
// 004373ca  33c4                 xor eax, esp
// 004373cc  50                   push eax
// 004373cd  8d44244c             lea eax, [esp + 0x4c]
// 004373d1  64a300000000         mov dword ptr fs:[0], eax
// 004373d7  8bf1                 mov esi, ecx
// 004373d9  e80c911f00           call 0x6304ea
// 004373de  8bae08010000         mov ebp, dword ptr [esi + 0x108]
// 004373e4  8d9e08010000         lea ebx, [esi + 0x108]
// 004373ea  33ff                 xor edi, edi
// 004373ec  3be8                 cmp ebp, eax
// 004373ee  7420                 je 0x437410
// 004373f0  3bc7                 cmp eax, edi
// 004373f2  893b                 mov dword ptr [ebx], edi
// 004373f4  740d                 je 0x437403
// 004373f6  8b08                 mov ecx, dword ptr [eax]
// 004373f8  8b11                 mov edx, dword ptr [ecx]
// 004373fa  53                   push ebx
// 004373fb  6820707800           push 0x787020
// 00437400  50                   push eax
// 00437401  ffd2                 call edx
// 00437403  3bef                 cmp ebp, edi
// 00437405  7409                 je 0x437410
// 00437407  8b4500               mov eax, dword ptr [ebp]
// 0043740a  8b4808               mov ecx, dword ptr [eax + 8]
// 0043740d  55                   push ebp
// 0043740e  ffd1                 call ecx
// 00437410  8b03                 mov eax, dword ptr [ebx]
// 00437412  3bc7                 cmp eax, edi
// 00437414  0f841b010000         je 0x437535
// 0043741a  897c2418             mov dword ptr [esp + 0x18], edi
// 0043741e  8b10                 mov edx, dword ptr [eax]
// 00437420  8b5220               mov edx, dword ptr [edx + 0x20]
// 00437423  8d4c2418             lea ecx, [esp + 0x18]
// 00437427  51                   push ecx
// 00437428  50                   push eax
// 00437429  897c245c             mov dword ptr [esp + 0x5c], edi
// 0043742d  ffd2                 call edx
// 0043742f  897c2414             mov dword ptr [esp + 0x14], edi
// 00437433  8d44242c             lea eax, [esp + 0x2c]
// 00437437  50                   push eax
// 00437438  ff1500ea7700         call dword ptr [0x77ea00]
// 0043743e  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 00437442  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00437446  8b6c2430             mov ebp, dword ptr [esp + 0x30]
// 0043744a  8b5c2434             mov ebx, dword ptr [esp + 0x34]
// 0043744e  894c2448             mov dword ptr [esp + 0x48], ecx
// 00437452  68f0cd7800           push 0x78cdf0
// 00437457  8d4c2420             lea ecx, [esp + 0x20]
// 0043745b  c644245802           mov byte ptr [esp + 0x58], 2
// 00437460  66c74424200000       mov word ptr [esp + 0x20], 0
// 00437467  e814a4fdff           call 0x411880
// 0043746c  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00437470  8b11                 mov edx, dword ptr [ecx]
// 00437472  8d442414             lea eax, [esp + 0x14]
// 00437476  50                   push eax
// 00437477  83ec10               sub esp, 0x10
// 0043747a  8bc4                 mov eax, esp
// 0043747c  8938                 mov dword ptr [eax], edi
// 0043747e  8b7c245c             mov edi, dword ptr [esp + 0x5c]
// 00437482  896804               mov dword ptr [eax + 4], ebp
// 00437485  895808               mov dword ptr [eax + 8], ebx
// 00437488  89780c               mov dword ptr [eax + 0xc], edi
// 0043748b  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0043748f  83ec10               sub esp, 0x10
// 00437492  8bc4                 mov eax, esp
// 00437494  8938                 mov dword ptr [eax], edi
// 00437496  8b7c2444             mov edi, dword ptr [esp + 0x44]
// 0043749a  897804               mov dword ptr [eax + 4], edi
// 0043749d  8b7c2448             mov edi, dword ptr [esp + 0x48]
// 004374a1  897808               mov dword ptr [eax + 8], edi
// 004374a4  8b7c244c             mov edi, dword ptr [esp + 0x4c]
// 004374a8  51                   push ecx
// 004374a9  8b4a2c               mov ecx, dword ptr [edx + 0x2c]
// 004374ac  c644247c03           mov byte ptr [esp + 0x7c], 3
// 004374b1  89780c               mov dword ptr [eax + 0xc], edi
// 004374b4  ffd1                 call ecx
// 004374b6  8b3dd8e97700         mov edi, dword ptr [0x77e9d8]
// 004374bc  8d54241c             lea edx, [esp + 0x1c]
// 004374c0  52                   push edx
// 004374c1  ffd7                 call edi
// 004374c3  8d44242c             lea eax, [esp + 0x2c]
// 004374c7  50                   push eax
// 004374c8  c644245801           mov byte ptr [esp + 0x58], 1
// 004374cd  ffd7                 call edi
// 004374cf  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004374d3  8d860c010000         lea eax, [esi + 0x10c]
// 004374d9  8b30                 mov esi, dword ptr [eax]
// 004374db  3bf1                 cmp esi, ecx
// 004374dd  742b                 je 0x43750a
// 004374df  85c9                 test ecx, ecx
// 004374e1  c70000000000         mov dword ptr [eax], 0
// 004374e7  7411                 je 0x4374fa
// 004374e9  8b11                 mov edx, dword ptr [ecx]
// 004374eb  50                   push eax
// 004374ec  8b02                 mov eax, dword ptr [edx]
// 004374ee  6880cd7800           push 0x78cd80
// 004374f3  51                   push ecx
// 004374f4  ffd0                 call eax
// 004374f6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004374fa  85f6                 test esi, esi
// 004374fc  740c                 je 0x43750a
// 004374fe  8b0e                 mov ecx, dword ptr [esi]
// 00437500  8b5108               mov edx, dword ptr [ecx + 8]
// 00437503  56                   push esi
// 00437504  ffd2                 call edx
// 00437506  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0043750a  85c9                 test ecx, ecx
// 0043750c  c644245400           mov byte ptr [esp + 0x54], 0
// 00437511  7408                 je 0x43751b
// 00437513  8b01                 mov eax, dword ptr [ecx]
// 00437515  51                   push ecx
// 00437516  8b4808               mov ecx, dword ptr [eax + 8]
// 00437519  ffd1                 call ecx
// 0043751b  8b442418             mov eax, dword ptr [esp + 0x18]
// 0043751f  85c0                 test eax, eax
// 00437521  c7442454ffffffff     mov dword ptr [esp + 0x54], 0xffffffff
// 00437529  7422                 je 0x43754d
// 0043752b  8b10                 mov edx, dword ptr [eax]
// 0043752d  50                   push eax
// 0043752e  8b4208               mov eax, dword ptr [edx + 8]
// 00437531  ffd0                 call eax
// 00437533  eb18                 jmp 0x43754d
// 00437535  8b860c010000         mov eax, dword ptr [esi + 0x10c]
// 0043753b  3bc7                 cmp eax, edi
// 0043753d  740e                 je 0x43754d
// 0043753f  89be0c010000         mov dword ptr [esi + 0x10c], edi
// 00437545  8b08                 mov ecx, dword ptr [eax]
// 00437547  8b5108               mov edx, dword ptr [ecx + 8]
// 0043754a  50                   push eax
// 0043754b  ffd2                 call edx
// 0043754d  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00437551  64890d00000000       mov dword ptr fs:[0], ecx
// 00437558  59                   pop ecx
// 00437559  5f                   pop edi
// 0043755a  5e                   pop esi
// 0043755b  5d                   pop ebp
// 0043755c  5b                   pop ebx
// 0043755d  83c444               add esp, 0x44
// 00437560  c20400               ret 4

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
    unsigned char padding[0x108];
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
