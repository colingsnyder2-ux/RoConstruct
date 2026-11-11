// from server: 100% by EspClaude
// from server: 71% by EspClaude
// roc 2007-08 00430dd0  unit: VCMDIFrameWnd::?$CXTPCommandBarsSiteBase  size: 184 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00430dd0
//
// 00430dd0  6aff                 push -1
// 00430dd2  686fda7300           push 0x73da6f
// 00430dd7  64a100000000         mov eax, dword ptr fs:[0]
// 00430ddd  50                   push eax
// 00430dde  83ec08               sub esp, 8
// 00430de1  56                   push esi
// 00430de2  57                   push edi
// 00430de3  a188518b00           mov eax, dword ptr [0x8b5188]
// 00430de8  33c4                 xor eax, esp
// 00430dea  50                   push eax
// 00430deb  8d442414             lea eax, [esp + 0x14]
// 00430def  64a300000000         mov dword ptr fs:[0], eax
// 00430df5  8bf1                 mov esi, ecx
// 00430df7  89742410             mov dword ptr [esp + 0x10], esi
// 00430dfb  c7066caf7800         mov dword ptr [esi], 0x78af6c
// 00430e01  c7867c01000060af7800 mov dword ptr [esi + 0x17c], 0x78af60
// 00430e0b  c786d001000054af7800 mov dword ptr [esi + 0x1d0], 0x78af54
// 00430e15  6a00                 push 0
// 00430e17  c744242002000000     mov dword ptr [esp + 0x20], 2
// 00430e1f  e8cc110100           call 0x441ff0
// 00430e24  8bbed8010000         mov edi, dword ptr [esi + 0x1d8]
// 00430e2a  85ff                 test edi, edi
// 00430e2c  c644241c01           mov byte ptr [esp + 0x1c], 1
// 00430e31  742a                 je 0x430e5d
// 00430e33  8d4704               lea eax, [edi + 4]
// 00430e36  83c9ff               or ecx, 0xffffffff
// 00430e39  f00fc108             lock xadd dword ptr [eax], ecx
// 00430e3d  751e                 jne 0x430e5d
// 00430e3f  8b17                 mov edx, dword ptr [edi]
// 00430e41  8b4204               mov eax, dword ptr [edx + 4]
// 00430e44  8bcf                 mov ecx, edi
// 00430e46  ffd0                 call eax
// 00430e48  8d4f08               lea ecx, [edi + 8]
// 00430e4b  83caff               or edx, 0xffffffff
// 00430e4e  f00fc111             lock xadd dword ptr [ecx], edx
// 00430e52  7509                 jne 0x430e5d
// 00430e54  8b07                 mov eax, dword ptr [edi]
// 00430e56  8b5008               mov edx, dword ptr [eax + 8]
// 00430e59  8bcf                 mov ecx, edi
// 00430e5b  ffd2                 call edx
// 00430e5d  8bce                 mov ecx, esi
// 00430e5f  c786d001000038837800 mov dword ptr [esi + 0x1d0], 0x788338
// 00430e69  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 00430e71  e85a150100           call 0x4423d0
// 00430e76  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00430e7a  64890d00000000       mov dword ptr fs:[0], ecx
// 00430e81  59                   pop ecx
// 00430e82  5f                   pop edi
// 00430e83  5e                   pop esi
// 00430e84  83c414               add esp, 0x14
// 00430e87  c3                   ret 

// from server: 100% by king_originala
// roc 2008-06 00430700  unit: VCMDIFrameWnd::?$CXTPCommandBarsSiteBase  size: 160 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00430700
//
// 00430700  6aff                 push -1
// 00430702  6826fb7b00           push 0x7bfb26
// 00430707  64a100000000         mov eax, dword ptr fs:[0]
// 0043070d  50                   push eax
// 0043070e  64892500000000       mov dword ptr fs:[0], esp
// 00430715  51                   push ecx
// 00430716  56                   push esi
// 00430717  8bf1                 mov esi, ecx
// 00430719  57                   push edi
// 0043071a  89742408             mov dword ptr [esp + 8], esi
// 0043071e  c7066c108100         mov dword ptr [esi], 0x81106c
// 00430724  c7868801000060108100 mov dword ptr [esi + 0x188], 0x811060
// 0043072e  c7863802000054108100 mov dword ptr [esi + 0x238], 0x811054
// 00430738  6a00                 push 0
// 0043073a  c744241801000000     mov dword ptr [esp + 0x18], 1
// 00430742  e8091f0100           call 0x442650
// 00430747  8bbe40020000         mov edi, dword ptr [esi + 0x240]
// 0043074d  c644241400           mov byte ptr [esp + 0x14], 0
// 00430752  85ff                 test edi, edi
// 00430754  742a                 je 0x430780
// 00430756  8d4704               lea eax, [edi + 4]
// 00430759  83c9ff               or ecx, 0xffffffff
// 0043075c  f00fc108             lock xadd dword ptr [eax], ecx
// 00430760  751e                 jne 0x430780
// 00430762  8b17                 mov edx, dword ptr [edi]
// 00430764  8b4204               mov eax, dword ptr [edx + 4]
// 00430767  8bcf                 mov ecx, edi
// 00430769  ffd0                 call eax
// 0043076b  8d4f08               lea ecx, [edi + 8]
// 0043076e  83caff               or edx, 0xffffffff
// 00430771  f00fc111             lock xadd dword ptr [ecx], edx
// 00430775  7509                 jne 0x430780
// 00430777  8b07                 mov eax, dword ptr [edi]
// 00430779  8b5008               mov edx, dword ptr [eax + 8]
// 0043077c  8bcf                 mov ecx, edi
// 0043077e  ffd2                 call edx
// 00430780  8bce                 mov ecx, esi
// 00430782  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0043078a  e8a1220100           call 0x442a30
// 0043078f  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00430793  5f                   pop edi
// 00430794  5e                   pop esi
// 00430795  64890d00000000       mov dword ptr fs:[0], ecx
// 0043079c  83c410               add esp, 0x10
// 0043079f  c3                   ret 

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Shared {
    void* object;
    Control* control;
    ~Shared();
};

struct Base {
    virtual ~Base();
    char storage[0x17c - 4];
};

struct Interface1 {
    virtual void method();
    char storage[0x1d0 - 0x17c - 4];
};

struct Interface2 {
    virtual void method();
    virtual ~Interface2() {}
};

struct S : Base, Interface1, Interface2 {
    Shared shared;
    virtual ~S();
    void cleanup(int);
};

__forceinline Shared::~Shared()
{
    Control* p = control;
    if (p) {
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

S::~S()
{
    cleanup(0);
}
