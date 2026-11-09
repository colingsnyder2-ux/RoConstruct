// from server: 100% by coldek
// from server: 100% by king_originala
// roc 2008-06 00587640  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00587640
//
// 00587640  55                   push ebp
// 00587641  8bec                 mov ebp, esp
// 00587643  6aff                 push -1
// 00587645  6821147d00           push 0x7d1421
// 0058764a  64a100000000         mov eax, dword ptr fs:[0]
// 00587650  50                   push eax
// 00587651  64892500000000       mov dword ptr fs:[0], esp
// 00587658  83ec0c               sub esp, 0xc
// 0058765b  53                   push ebx
// 0058765c  56                   push esi
// 0058765d  57                   push edi
// 0058765e  8965f0               mov dword ptr [ebp - 0x10], esp
// 00587661  6a1c                 push 0x1c
// 00587663  e8b8921100           call 0x6a0920
// 00587668  8bf0                 mov esi, eax
// 0058766a  83c404               add esp, 4
// 0058766d  8975ec               mov dword ptr [ebp - 0x14], esi
// 00587670  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00587677  8975e8               mov dword ptr [ebp - 0x18], esi
// 0058767a  c645fc01             mov byte ptr [ebp - 4], 1
// 0058767e  85f6                 test esi, esi
// 00587680  741b                 je 0x58769d
// 00587682  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00587685  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 00587688  8b5510               mov edx, dword ptr [ebp + 0x10]
// 0058768b  50                   push eax
// 0058768c  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0058768f  51                   push ecx
// 00587690  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00587693  52                   push edx
// 00587694  50                   push eax
// 00587695  51                   push ecx
// 00587696  8bce                 mov ecx, esi
// 00587698  e823fdffff           call 0x5873c0
// 0058769d  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005876a0  5f                   pop edi
// 005876a1  8bc6                 mov eax, esi
// 005876a3  5e                   pop esi
// 005876a4  64890d00000000       mov dword ptr fs:[0], ecx
// 005876ab  5b                   pop ebx
// 005876ac  8be5                 mov esp, ebp
// 005876ae  5d                   pop ebp
// 005876af  c21400               ret 0x14

typedef unsigned int size_t;

void * __cdecl operator new(size_t);
void __cdecl operator delete(void *);

inline void * __cdecl operator new(size_t, void *p)
{
    return p;
}

inline void __cdecl operator delete(void *, void *)
{
}

struct Object {
    virtual void first() = 0;
    virtual void second() = 0;
    virtual Object *clone() = 0;
};

struct Source {
    int first;
    int second;
    Object *object;
};

struct S {
    int first;
    unsigned char remaining[24];

    S(int, int, int, int, int);
};

S * __stdcall create(int a, int b, int c, int d, int e)
{
    S *p = static_cast<S *>(operator new(sizeof(S)));
    try {
        new (p) S(a, b, c, d, e);
        return p;
    }
    catch (...) {
        operator delete(p);
        throw;
    }
}
