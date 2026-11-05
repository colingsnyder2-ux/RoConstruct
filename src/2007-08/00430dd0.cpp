// from server: 71% by EspClaude
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
    char storage[0x184];
};

struct Interface1 {
    virtual void method();
    char storage[0xAC];
};

struct Interface2 {
    virtual void method();
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
