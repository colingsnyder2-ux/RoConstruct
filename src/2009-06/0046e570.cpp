// from server: 100% by EspClaude
// from server: 100% by Gemini
// roc 2008-06 0046b860  unit: VCWorkspace::?$CComObject  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0046b860
//
// 0046b860  64a100000000         mov eax, dword ptr fs:[0]
// 0046b866  6aff                 push -1
// 0046b868  68e8397c00           push 0x7c39e8
// 0046b86d  50                   push eax
// 0046b86e  64892500000000       mov dword ptr fs:[0], esp
// 0046b875  8b4924               mov ecx, dword ptr [ecx + 0x24]
// 0046b878  83ec4c               sub esp, 0x4c
// 0046b87b  85c9                 test ecx, ecx
// 0046b87d  7407                 je 0x46b886
// 0046b87f  e81c36fbff           call 0x41eea0
// 0046b884  eb02                 jmp 0x46b888
// 0046b886  33c0                 xor eax, eax
// 0046b888  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 0046b88c  51                   push ecx
// 0046b88d  50                   push eax
// 0046b88e  8d4c2408             lea ecx, [esp + 8]
// 0046b892  e8b9fcffff           call 0x46b550
// 0046b897  8b54245c             mov edx, dword ptr [esp + 0x5c]
// 0046b89b  52                   push edx
// 0046b89c  8d4c2404             lea ecx, [esp + 4]
// 0046b8a0  c744245801000000     mov dword ptr [esp + 0x58], 1
// 0046b8a8  e8632f1200           call 0x58e810
// 0046b8ad  8d0c24               lea ecx, [esp]
// 0046b8b0  c7442454ffffffff     mov dword ptr [esp + 0x54], 0xffffffff
// 0046b8b8  e823f9ffff           call 0x46b1e0
// 0046b8bd  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0046b8c1  33c0                 xor eax, eax
// 0046b8c3  64890d00000000       mov dword ptr fs:[0], ecx
// 0046b8ca  83c458               add esp, 0x58
// 0046b8cd  c20800               ret 8

// from server: 99% by king_originala
// roc 2008-06 0046b860  unit: VCWorkspace::?$CComObject  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0046b860

struct Dummy {
    ~Dummy();
    void g();
};

inline void swallow(bool b)
{
    if (b) {
        Dummy d;
        d.g();
    }
}

struct Context {
    void* get();
};

struct PointerVector {
    void* begin;
    void* end;
    void* capacity;

    void resize(unsigned int count);
};

struct Writer {
    PointerVector values;
    char storage[64];

    Writer(void* context, void* argument);
    ~Writer();
};

struct S {
    char padding[28];
    Context* context;

    int f(unsigned int count, void* argument);
};

int S::f(unsigned int count, void* argument)
{
    swallow(false);
    Writer writer(context ? context->get() : 0, argument);
    writer.values.resize(count);
    return 0;
}
