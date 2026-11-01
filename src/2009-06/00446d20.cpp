// from server: 94% by EspClaude
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
    char padding[0x110];
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
