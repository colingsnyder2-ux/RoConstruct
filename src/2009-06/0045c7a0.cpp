// from server: 100% by EspClaude
// from server: 87% by EspClaude
// roc 2009-06 0045c7a0  unit: RBX::AdornG3D  size: 258 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0045c7a0
//
// 0045c7a0  6aff                 push -1
// 0045c7a2  6846248500           push 0x852446
// 0045c7a7  64a100000000         mov eax, dword ptr fs:[0]
// 0045c7ad  50                   push eax
// 0045c7ae  64892500000000       mov dword ptr fs:[0], esp
// 0045c7b5  83ec08               sub esp, 8
// 0045c7b8  56                   push esi
// 0045c7b9  57                   push edi
// 0045c7ba  6a54                 push 0x54
// 0045c7bc  8bf1                 mov esi, ecx
// 0045c7be  e875c22b00           call 0x718a38
// 0045c7c3  83c404               add esp, 4
// 0045c7c6  89442408             mov dword ptr [esp + 8], eax
// 0045c7ca  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0045c7d2  85c0                 test eax, eax
// 0045c7d4  7435                 je 0x45c80b
// 0045c7d6  8b8ecc000000         mov ecx, dword ptr [esi + 0xcc]
// 0045c7dc  83ec08               sub esp, 8
// 0045c7df  8bfc                 mov edi, esp
// 0045c7e1  890f                 mov dword ptr [edi], ecx
// 0045c7e3  8b96d0000000         mov edx, dword ptr [esi + 0xd0]
// 0045c7e9  89642414             mov dword ptr [esp + 0x14], esp
// 0045c7ed  895704               mov dword ptr [edi + 4], edx
// 0045c7f0  85d2                 test edx, edx
// 0045c7f2  740c                 je 0x45c800
// 0045c7f4  83c204               add edx, 4
// 0045c7f7  b901000000           mov ecx, 1
// 0045c7fc  f00fc10a             lock xadd dword ptr [edx], ecx
// 0045c800  8bc8                 mov ecx, eax
// 0045c802  e869cd0c00           call 0x529570
// 0045c807  8bf8                 mov edi, eax
// 0045c809  eb02                 jmp 0x45c80d
// 0045c80b  33ff                 xor edi, edi
// 0045c80d  8b8ef8000000         mov ecx, dword ptr [esi + 0xf8]
// 0045c813  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0045c81b  3bf9                 cmp edi, ecx
// 0045c81d  740c                 je 0x45c82b
// 0045c81f  85c9                 test ecx, ecx
// 0045c821  7408                 je 0x45c82b
// 0045c823  8b11                 mov edx, dword ptr [ecx]
// 0045c825  8b02                 mov eax, dword ptr [edx]
// 0045c827  6a01                 push 1
// 0045c829  ffd0                 call eax
// 0045c82b  6a20                 push 0x20
// 0045c82d  89bef8000000         mov dword ptr [esi + 0xf8], edi
// 0045c833  e800c22b00           call 0x718a38
// 0045c838  8bf8                 mov edi, eax
// 0045c83a  83c404               add esp, 4
// 0045c83d  897c240c             mov dword ptr [esp + 0xc], edi
// 0045c841  c744241801000000     mov dword ptr [esp + 0x18], 1
// 0045c849  85ff                 test edi, edi
// 0045c84b  741e                 je 0x45c86b
// 0045c84d  8b86f4000000         mov eax, dword ptr [esi + 0xf4]
// 0045c853  680000a000           push 0xa00000
// 0045c858  8d4f08               lea ecx, [edi + 8]
// 0045c85b  c70714a58b00         mov dword ptr [edi], 0x8ba514
// 0045c861  894704               mov dword ptr [edi + 4], eax
// 0045c864  e8b7900400           call 0x4a5920
// 0045c869  eb02                 jmp 0x45c86d
// 0045c86b  33ff                 xor edi, edi
// 0045c86d  8b8efc000000         mov ecx, dword ptr [esi + 0xfc]
// 0045c873  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0045c87b  3bf9                 cmp edi, ecx
// 0045c87d  740c                 je 0x45c88b
// 0045c87f  85c9                 test ecx, ecx
// 0045c881  7408                 je 0x45c88b
// 0045c883  8b11                 mov edx, dword ptr [ecx]
// 0045c885  8b02                 mov eax, dword ptr [edx]
// 0045c887  6a01                 push 1
// 0045c889  ffd0                 call eax
// 0045c88b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0045c88f  89befc000000         mov dword ptr [esi + 0xfc], edi
// 0045c895  5f                   pop edi
// 0045c896  64890d00000000       mov dword ptr fs:[0], ecx
// 0045c89d  5e                   pop esi
// 0045c89e  83c414               add esp, 0x14
// 0045c8a1  c3                   ret 

// from server: 100% by colin
// roc 2008-06 0045d850  unit: RBX::AdornG3D  size: 252 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0045d850
//
// 0045d850  6aff                 push -1
// 0045d852  68262b7c00           push 0x7c2b26
// 0045d857  64a100000000         mov eax, dword ptr fs:[0]
// 0045d85d  50                   push eax
// 0045d85e  64892500000000       mov dword ptr fs:[0], esp
// 0045d865  83ec08               sub esp, 8
// 0045d868  56                   push esi
// 0045d869  57                   push edi
// 0045d86a  6a6c                 push 0x6c
// 0045d86c  8bf1                 mov esi, ecx
// 0045d86e  e8ad302400           call 0x6a0920
// 0045d873  83c404               add esp, 4
// 0045d876  89442408             mov dword ptr [esp + 8], eax
// 0045d87a  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0045d882  85c0                 test eax, eax
// 0045d884  742f                 je 0x45d8b5
// 0045d886  8b4e70               mov ecx, dword ptr [esi + 0x70]
// 0045d889  83ec08               sub esp, 8
// 0045d88c  8bfc                 mov edi, esp
// 0045d88e  890f                 mov dword ptr [edi], ecx
// 0045d890  8b5674               mov edx, dword ptr [esi + 0x74]
// 0045d893  89642414             mov dword ptr [esp + 0x14], esp
// 0045d897  895704               mov dword ptr [edi + 4], edx
// 0045d89a  85d2                 test edx, edx
// 0045d89c  740c                 je 0x45d8aa
// 0045d89e  83c204               add edx, 4
// 0045d8a1  b901000000           mov ecx, 1
// 0045d8a6  f00fc10a             lock xadd dword ptr [edx], ecx
// 0045d8aa  8bc8                 mov ecx, eax
// 0045d8ac  e82fe30700           call 0x4dbbe0
// 0045d8b1  8bf8                 mov edi, eax
// 0045d8b3  eb02                 jmp 0x45d8b7
// 0045d8b5  33ff                 xor edi, edi
// 0045d8b7  8b8eb0000000         mov ecx, dword ptr [esi + 0xb0]
// 0045d8bd  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0045d8c5  3bf9                 cmp edi, ecx
// 0045d8c7  740c                 je 0x45d8d5
// 0045d8c9  85c9                 test ecx, ecx
// 0045d8cb  7408                 je 0x45d8d5
// 0045d8cd  8b11                 mov edx, dword ptr [ecx]
// 0045d8cf  8b02                 mov eax, dword ptr [edx]
// 0045d8d1  6a01                 push 1
// 0045d8d3  ffd0                 call eax
// 0045d8d5  6a20                 push 0x20
// 0045d8d7  89beb0000000         mov dword ptr [esi + 0xb0], edi
// 0045d8dd  e83e302400           call 0x6a0920
// 0045d8e2  8bf8                 mov edi, eax
// 0045d8e4  83c404               add esp, 4
// 0045d8e7  897c240c             mov dword ptr [esp + 0xc], edi
// 0045d8eb  c744241801000000     mov dword ptr [esp + 0x18], 1
// 0045d8f3  85ff                 test edi, edi
// 0045d8f5  741e                 je 0x45d915
// 0045d8f7  8b86ac000000         mov eax, dword ptr [esi + 0xac]
// 0045d8fd  680000a000           push 0xa00000
// 0045d902  8d4f08               lea ecx, [edi + 8]
// 0045d905  c707249d8100         mov dword ptr [edi], 0x819d24
// 0045d90b  894704               mov dword ptr [edi + 4], eax
// 0045d90e  e8ed0a0200           call 0x47e400
// 0045d913  eb02                 jmp 0x45d917
// 0045d915  33ff                 xor edi, edi
// 0045d917  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 0045d91d  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0045d925  3bf9                 cmp edi, ecx
// 0045d927  740c                 je 0x45d935
// 0045d929  85c9                 test ecx, ecx
// 0045d92b  7408                 je 0x45d935
// 0045d92d  8b11                 mov edx, dword ptr [ecx]
// 0045d92f  8b02                 mov eax, dword ptr [edx]
// 0045d931  6a01                 push 1
// 0045d933  ffd0                 call eax
// 0045d935  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0045d939  89beb4000000         mov dword ptr [esi + 0xb4], edi
// 0045d93f  5f                   pop edi
// 0045d940  64890d00000000       mov dword ptr fs:[0], ecx
// 0045d947  5e                   pop esi
// 0045d948  83c414               add esp, 0x14
// 0045d94b  c3                   ret 

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)


void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Control {
    long reserved;
    volatile long references;
};

struct Shared {
    void* object;
    Control* control;

    Shared(const Shared& other)
        : object(other.object), control(other.control)
    {
        if (control)
            _InterlockedIncrement(&control->references);
    }

    ~Shared();
};

struct Renderer {
    virtual ~Renderer();
    char storage[80];
    Renderer(Shared);
};

struct TextureArgs {
    char storage[24];
    TextureArgs(unsigned int);
};

struct TextureRenderer {
    virtual ~TextureRenderer();
    void* owner;
    TextureArgs args;

    TextureRenderer(void*);
};

inline TextureRenderer::TextureRenderer(void* value)
    : owner(value), args(0xa00000)
{
}

struct S {
    char padding0[0xcc];
    Shared shared;
    char padding1[0x20];
    void* owner;
    Renderer* renderer;
    TextureRenderer* textureRenderer;

    void f();
};

void S::f()
{
    Renderer* replacement = new Renderer(shared);
    if (replacement != renderer && renderer)
        delete renderer;
    renderer = replacement;

    TextureRenderer* textureReplacement = new TextureRenderer(owner);
    if (textureReplacement != textureRenderer && textureRenderer)
        delete textureRenderer;
    textureRenderer = textureReplacement;
}
