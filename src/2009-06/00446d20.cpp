// from server: 100% by EspClaude
// from server: 94% by EspClaude
// roc 2009-06 00446d20  unit: CBrowserDocManager  size: 170 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00446d20
//
// 00446d20  64a100000000         mov eax, dword ptr fs:[0]
// 00446d26  6aff                 push -1
// 00446d28  6838938500           push 0x859338
// 00446d2d  50                   push eax
// 00446d2e  64892500000000       mov dword ptr fs:[0], esp
// 00446d35  56                   push esi
// 00446d36  57                   push edi
// 00446d37  8bf1                 mov esi, ecx
// 00446d39  8b442418             mov eax, dword ptr [esp + 0x18]
// 00446d3d  8d4c241c             lea ecx, [esp + 0x1c]
// 00446d41  51                   push ecx
// 00446d42  8d4e58               lea ecx, [esi + 0x58]
// 00446d45  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00446d4d  894654               mov dword ptr [esi + 0x54], eax
// 00446d50  e8abb7fbff           call 0x402500
// 00446d55  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00446d59  8b3e                 mov edi, dword ptr [esi]
// 00446d5b  83c154               add ecx, 0x54
// 00446d5e  83c758               add edi, 0x58
// 00446d61  ff15bce48900         call dword ptr [0x89e4bc]
// 00446d67  8b17                 mov edx, dword ptr [edi]
// 00446d69  50                   push eax
// 00446d6a  8bce                 mov ecx, esi
// 00446d6c  ffd2                 call edx
// 00446d6e  6a00                 push 0
// 00446d70  6a01                 push 1
// 00446d72  6a00                 push 0
// 00446d74  8bce                 mov ecx, esi
// 00446d76  e841292d00           call 0x7196bc
// 00446d7b  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00446d7f  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 00446d87  85c0                 test eax, eax
// 00446d89  742c                 je 0x446db7
// 00446d8b  8bf0                 mov esi, eax
// 00446d8d  83c004               add eax, 4
// 00446d90  83c9ff               or ecx, 0xffffffff
// 00446d93  f00fc108             lock xadd dword ptr [eax], ecx
// 00446d97  751e                 jne 0x446db7
// 00446d99  8b16                 mov edx, dword ptr [esi]
// 00446d9b  8b4204               mov eax, dword ptr [edx + 4]
// 00446d9e  8bce                 mov ecx, esi
// 00446da0  ffd0                 call eax
// 00446da2  8d4e08               lea ecx, [esi + 8]
// 00446da5  83caff               or edx, 0xffffffff
// 00446da8  f00fc111             lock xadd dword ptr [ecx], edx
// 00446dac  7509                 jne 0x446db7
// 00446dae  8b06                 mov eax, dword ptr [esi]
// 00446db0  8b5008               mov edx, dword ptr [eax + 8]
// 00446db3  8bce                 mov ecx, esi
// 00446db5  ffd2                 call edx
// 00446db7  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00446dbb  5f                   pop edi
// 00446dbc  64890d00000000       mov dword ptr fs:[0], ecx
// 00446dc3  5e                   pop esi
// 00446dc4  83c40c               add esp, 0xc
// 00446dc7  c20800               ret 8

// from server: 100% by colin
// roc 2008-06 0044a9c0  unit: CRbxPlayDocTemplate  size: 173 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044a9c0
//
// 0044a9c0  64a100000000         mov eax, dword ptr fs:[0]
// 0044a9c6  6aff                 push -1
// 0044a9c8  6868617c00           push 0x7c6168
// 0044a9cd  50                   push eax
// 0044a9ce  64892500000000       mov dword ptr fs:[0], esp
// 0044a9d5  56                   push esi
// 0044a9d6  57                   push edi
// 0044a9d7  8bf1                 mov esi, ecx
// 0044a9d9  8b442418             mov eax, dword ptr [esp + 0x18]
// 0044a9dd  8d4c241c             lea ecx, [esp + 0x1c]
// 0044a9e1  51                   push ecx
// 0044a9e2  8d4e58               lea ecx, [esi + 0x58]
// 0044a9e5  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0044a9ed  894654               mov dword ptr [esi + 0x54], eax
// 0044a9f0  e8bb7bfbff           call 0x4025b0
// 0044a9f5  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0044a9f9  8b3e                 mov edi, dword ptr [esi]
// 0044a9fb  81c110010000         add ecx, 0x110
// 0044aa01  83c758               add edi, 0x58
// 0044aa04  ff1564248000         call dword ptr [0x802464]
// 0044aa0a  8b17                 mov edx, dword ptr [edi]
// 0044aa0c  50                   push eax
// 0044aa0d  8bce                 mov ecx, esi
// 0044aa0f  ffd2                 call edx
// 0044aa11  6a00                 push 0
// 0044aa13  6a01                 push 1
// 0044aa15  6a00                 push 0
// 0044aa17  8bce                 mov ecx, esi
// 0044aa19  e826682500           call 0x6a1244
// 0044aa1e  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0044aa22  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0044aa2a  85c0                 test eax, eax
// 0044aa2c  742c                 je 0x44aa5a
// 0044aa2e  8bf0                 mov esi, eax
// 0044aa30  83c004               add eax, 4
// 0044aa33  83c9ff               or ecx, 0xffffffff
// 0044aa36  f00fc108             lock xadd dword ptr [eax], ecx
// 0044aa3a  751e                 jne 0x44aa5a
// 0044aa3c  8b16                 mov edx, dword ptr [esi]
// 0044aa3e  8b4204               mov eax, dword ptr [edx + 4]
// 0044aa41  8bce                 mov ecx, esi
// 0044aa43  ffd0                 call eax
// 0044aa45  8d4e08               lea ecx, [esi + 8]
// 0044aa48  83caff               or edx, 0xffffffff
// 0044aa4b  f00fc111             lock xadd dword ptr [ecx], edx
// 0044aa4f  7509                 jne 0x44aa5a
// 0044aa51  8b06                 mov eax, dword ptr [esi]
// 0044aa53  8b5008               mov edx, dword ptr [eax + 8]
// 0044aa56  8bce                 mov ecx, esi
// 0044aa58  ffd2                 call edx
// 0044aa5a  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0044aa5e  5f                   pop edi
// 0044aa5f  64890d00000000       mov dword ptr fs:[0], ecx
// 0044aa66  5e                   pop esi
// 0044aa67  83c40c               add esp, 0xc
// 0044aa6a  c20800               ret 8

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)


struct String {
    char data[28];
};

extern const char* (__thiscall *string_c_str)(const String*);

struct RefCount {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Holder {
    RefCount* ptr;
    Holder& __thiscall assign(const Holder&);
    ~Holder();
};

Holder::~Holder()
{
    if (ptr) {
        RefCount* p = ptr;
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

struct Document {
    char padding[0x54];
    String name;
};

struct S;
typedef void (__thiscall *NameFunction)(S*, const char*);

struct Table {
    char padding[0x58];
    NameFunction setName;
};

struct S {
    Table* table;
    char padding[0x50];
    Document* document;
    Holder holder;

    void __thiscall update(int, int, int);
    void __thiscall f(Document* volatile, Holder);
};

void S::f(Document* volatile value, Holder reference)
{
    document = value;
    holder.assign(reference);
    NameFunction* slot = &table->setName;
    const char* name = string_c_str(&value->name);
    (*slot)(this, name);
    update(0, 1, 0);
}
