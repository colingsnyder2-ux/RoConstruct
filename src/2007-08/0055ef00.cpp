// from server: 100% by EspClaude
// roc-flags: /O2 /GS- /EHsc /MD
// from server: 83% by EspClaude
// roc-cl: 50727
// from server: 100% by king_originala
// roc 2008-06 0057dfd0  unit: RBX::ClearBackpack  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0057dfd0
//
// 0057dfd0  6aff                 push -1
// 0057dfd2  68980f7d00           push 0x7d0f98
// 0057dfd7  64a100000000         mov eax, dword ptr fs:[0]
// 0057dfdd  50                   push eax
// 0057dfde  64892500000000       mov dword ptr fs:[0], esp
// 0057dfe5  51                   push ecx
// 0057dfe6  56                   push esi
// 0057dfe7  57                   push edi
// 0057dfe8  8bf9                 mov edi, ecx
// 0057dfea  897c2408             mov dword ptr [esp + 8], edi
// 0057dfee  c7074c078300         mov dword ptr [edi], 0x83074c
// 0057dff4  8b7718               mov esi, dword ptr [edi + 0x18]
// 0057dff7  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0057dfff  85f6                 test esi, esi
// 0057e001  742a                 je 0x57e02d
// 0057e003  8d4604               lea eax, [esi + 4]
// 0057e006  83c9ff               or ecx, 0xffffffff
// 0057e009  f00fc108             lock xadd dword ptr [eax], ecx
// 0057e00d  751e                 jne 0x57e02d
// 0057e00f  8b16                 mov edx, dword ptr [esi]
// 0057e011  8b4204               mov eax, dword ptr [edx + 4]
// 0057e014  8bce                 mov ecx, esi
// 0057e016  ffd0                 call eax
// 0057e018  8d4e08               lea ecx, [esi + 8]
// 0057e01b  83caff               or edx, 0xffffffff
// 0057e01e  f00fc111             lock xadd dword ptr [ecx], edx
// 0057e022  7509                 jne 0x57e02d
// 0057e024  8b06                 mov eax, dword ptr [esi]
// 0057e026  8b5008               mov edx, dword ptr [eax + 8]
// 0057e029  8bce                 mov ecx, esi
// 0057e02b  ffd2                 call edx
// 0057e02d  8bcf                 mov ecx, edi
// 0057e02f  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0057e037  e884520000           call 0x5832c0
// 0057e03c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0057e040  5f                   pop edi
// 0057e041  5e                   pop esi
// 0057e042  64890d00000000       mov dword ptr fs:[0], ecx
// 0057e049  83c410               add esp, 0x10
// 0057e04c  c3                   ret 

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual ~Control();
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Handle {
    void* object;
    Control* control;
    ~Handle();
};

inline Handle::~Handle()
{
    Control* p = control;
    if (p && _InterlockedDecrement(&p->strong) == 0) {
        p->dispose();
        if (_InterlockedDecrement(&p->weak) == 0)
            p->destroy();
    }
}

struct Base {
    virtual ~Base();
    char padding[16];
};

struct ClearBackpack : Base {
    Handle handle;
    virtual ~ClearBackpack();
};

ClearBackpack::~ClearBackpack()
{
}
