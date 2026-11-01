// from server: 96% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005d8690  unit: RBX::VHumanoid::?$FactoryProduct  size: 162 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005d8690
//
// 005d8690  83ec08               sub esp, 8
// 005d8693  53                   push ebx
// 005d8694  8b1d90288000         mov ebx, dword ptr [0x802890]
// 005d869a  55                   push ebp
// 005d869b  56                   push esi
// 005d869c  8bf1                 mov esi, ecx
// 005d869e  8baefc010000         mov ebp, dword ptr [esi + 0x1fc]
// 005d86a4  57                   push edi
// 005d86a5  39aef8010000         cmp dword ptr [esi + 0x1f8], ebp
// 005d86ab  7602                 jbe 0x5d86af
// 005d86ad  ffd3                 call ebx
// 005d86af  8bbef8010000         mov edi, dword ptr [esi + 0x1f8]
// 005d86b5  8b86ec010000         mov eax, dword ptr [esi + 0x1ec]
// 005d86bb  89442410             mov dword ptr [esp + 0x10], eax
// 005d86bf  3bbefc010000         cmp edi, dword ptr [esi + 0x1fc]
// 005d86c5  7602                 jbe 0x5d86c9
// 005d86c7  ffd3                 call ebx
// 005d86c9  8bb6ec010000         mov esi, dword ptr [esi + 0x1ec]
// 005d86cf  90                   nop 
// 005d86d0  85f6                 test esi, esi
// 005d86d2  7406                 je 0x5d86da
// 005d86d4  3b742410             cmp esi, dword ptr [esp + 0x10]
// 005d86d8  7402                 je 0x5d86dc
// 005d86da  ffd3                 call ebx
// 005d86dc  3bfd                 cmp edi, ebp
// 005d86de  7448                 je 0x5d8728
// 005d86e0  85f6                 test esi, esi
// 005d86e2  753c                 jne 0x5d8720
// 005d86e4  ffd3                 call ebx
// 005d86e6  33c0                 xor eax, eax
// 005d86e8  3b7810               cmp edi, dword ptr [eax + 0x10]
// 005d86eb  7202                 jb 0x5d86ef
// 005d86ed  ffd3                 call ebx
// 005d86ef  8b0f                 mov ecx, dword ptr [edi]
// 005d86f1  6a00                 push 0
// 005d86f3  68e0349500           push 0x9534e0
// 005d86f8  6808699300           push 0x936908
// 005d86fd  6a00                 push 0
// 005d86ff  51                   push ecx
// 005d8700  e8c1900c00           call 0x6a17c6
// 005d8705  83c414               add esp, 0x14
// 005d8708  85c0                 test eax, eax
// 005d870a  751e                 jne 0x5d872a
// 005d870c  85f6                 test esi, esi
// 005d870e  7514                 jne 0x5d8724
// 005d8710  ffd3                 call ebx
// 005d8712  33c0                 xor eax, eax
// 005d8714  3b7810               cmp edi, dword ptr [eax + 0x10]
// 005d8717  7202                 jb 0x5d871b
// 005d8719  ffd3                 call ebx
// 005d871b  83c704               add edi, 4
// 005d871e  ebb0                 jmp 0x5d86d0
// 005d8720  8b06                 mov eax, dword ptr [esi]
// 005d8722  ebc4                 jmp 0x5d86e8
// 005d8724  8b06                 mov eax, dword ptr [esi]
// 005d8726  ebec                 jmp 0x5d8714
// 005d8728  33c0                 xor eax, eax
// 005d872a  5f                   pop edi
// 005d872b  5e                   pop esi
// 005d872c  5d                   pop ebp
// 005d872d  5b                   pop ebx
// 005d872e  83c408               add esp, 8
// 005d8731  c3                   ret 

extern "C" void* __cdecl __RTDynamicCast(
    void*, long, void*, void*, int);

struct Container {
    unsigned char padding[16];
    void** finish;
};

struct Proxy {
    Container* container;
};

struct Iterator {
    Proxy* proxy;
    void** position;
};

struct S {
    unsigned char padding0[0x1ec];
    Proxy* proxy;
    unsigned char padding1[8];
    void** first;
    void** last;

    void* f();
};

void* S::f()
{
    void (__cdecl *invalid)() =
        *reinterpret_cast<void (__cdecl **)()>(0x802890);

    Iterator finish;
    finish.position = last;
    if (first > finish.position)
        invalid();

    void** current = first;
    finish.proxy = proxy;
    if (current > last)
        invalid();

    Proxy* currentProxy = proxy;
    for (;;) {
        if (!currentProxy || currentProxy != finish.proxy)
            invalid();

        if (current == finish.position)
            return 0;

        if (!currentProxy)
            invalid();

        Container* container =
            currentProxy ? currentProxy->container : 0;
        if (current >= container->finish)
            invalid();

        void* result = __RTDynamicCast(
            *current, 0,
            reinterpret_cast<void*>(0x936908),
            reinterpret_cast<void*>(0x9534e0), 0);

        if (result)
            return result;

        if (!currentProxy)
            invalid();

        container = currentProxy ? currentProxy->container : 0;
        if (current >= container->finish)
            invalid();

        ++current;
    }
}
