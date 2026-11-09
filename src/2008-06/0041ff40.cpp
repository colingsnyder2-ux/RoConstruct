// from server: 100% by colin
// from server: 91% by king_originala
// roc 2008-06 0041ff40  unit: CInsertObjectDialog  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0041ff40
//
// 0041ff40  6aff                 push -1
// 0041ff42  6869e77b00           push 0x7be769
// 0041ff47  64a100000000         mov eax, dword ptr fs:[0]
// 0041ff4d  50                   push eax
// 0041ff4e  64892500000000       mov dword ptr fs:[0], esp
// 0041ff55  51                   push ecx
// 0041ff56  56                   push esi
// 0041ff57  8bf1                 mov esi, ecx
// 0041ff59  57                   push edi
// 0041ff5a  89742408             mov dword ptr [esp + 8], esi
// 0041ff5e  c7068cf48000         mov dword ptr [esi], 0x80f48c
// 0041ff64  8d8ea8000000         lea ecx, [esi + 0xa8]
// 0041ff6a  c744241405000000     mov dword ptr [esp + 0x14], 5
// 0041ff72  e83d0f2800           call 0x6a0eb4
// 0041ff77  8d8ea0000000         lea ecx, [esi + 0xa0]
// 0041ff7d  c644241404           mov byte ptr [esp + 0x14], 4
// 0041ff82  e8a92fffff           call 0x412f30
// 0041ff87  8bbe9c000000         mov edi, dword ptr [esi + 0x9c]
// 0041ff8d  c644241403           mov byte ptr [esp + 0x14], 3
// 0041ff92  85ff                 test edi, edi
// 0041ff94  742a                 je 0x41ffc0
// 0041ff96  8d4704               lea eax, [edi + 4]
// 0041ff99  83c9ff               or ecx, 0xffffffff
// 0041ff9c  f00fc108             lock xadd dword ptr [eax], ecx
// 0041ffa0  751e                 jne 0x41ffc0
// 0041ffa2  8b17                 mov edx, dword ptr [edi]
// 0041ffa4  8b4204               mov eax, dword ptr [edx + 4]
// 0041ffa7  8bcf                 mov ecx, edi
// 0041ffa9  ffd0                 call eax
// 0041ffab  8d4f08               lea ecx, [edi + 8]
// 0041ffae  83caff               or edx, 0xffffffff
// 0041ffb1  f00fc111             lock xadd dword ptr [ecx], edx
// 0041ffb5  7509                 jne 0x41ffc0
// 0041ffb7  8b07                 mov eax, dword ptr [edi]
// 0041ffb9  8b5008               mov edx, dword ptr [eax + 8]
// 0041ffbc  8bcf                 mov ecx, edi
// 0041ffbe  ffd2                 call edx
// 0041ffc0  8d8e94000000         lea ecx, [esi + 0x94]
// 0041ffc6  ff15143f8000         call dword ptr [0x803f14]
// 0041ffcc  8d4e7c               lea ecx, [esi + 0x7c]
// 0041ffcf  c644241401           mov byte ptr [esp + 0x14], 1
// 0041ffd4  e807301800           call 0x5a2fe0
// 0041ffd9  8b7e78               mov edi, dword ptr [esi + 0x78]
// 0041ffdc  c644241400           mov byte ptr [esp + 0x14], 0
// 0041ffe1  85ff                 test edi, edi
// 0041ffe3  742a                 je 0x42000f
// 0041ffe5  8d4704               lea eax, [edi + 4]
// 0041ffe8  83c9ff               or ecx, 0xffffffff
// 0041ffeb  f00fc108             lock xadd dword ptr [eax], ecx
// 0041ffef  751e                 jne 0x42000f
// 0041fff1  8b17                 mov edx, dword ptr [edi]
// 0041fff3  8b4204               mov eax, dword ptr [edx + 4]
// 0041fff6  8bcf                 mov ecx, edi
// 0041fff8  ffd0                 call eax
// 0041fffa  8d4f08               lea ecx, [edi + 8]
// 0041fffd  83caff               or edx, 0xffffffff
// 00420000  f00fc111             lock xadd dword ptr [ecx], edx
// 00420004  7509                 jne 0x42000f
// 00420006  8b07                 mov eax, dword ptr [edi]
// 00420008  8b5008               mov edx, dword ptr [eax + 8]
// 0042000b  8bcf                 mov ecx, edi
// 0042000d  ffd2                 call edx
// 0042000f  8bce                 mov ecx, esi
// 00420011  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00420019  e8b40e2800           call 0x6a0ed2
// 0042001e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00420022  5f                   pop edi
// 00420023  5e                   pop esi
// 00420024  64890d00000000       mov dword ptr fs:[0], ecx
// 0042002b  83c410               add esp, 0x10
// 0042002e  c3                   ret 

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct ControlBlock {
    virtual ~ControlBlock();
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct SharedMember {
    void* object;
    ControlBlock* control;
    ~SharedMember();
};

inline SharedMember::~SharedMember()
{
    ControlBlock* p = control;
    if (p && _InterlockedDecrement(&p->strong) == 0) {
        p->dispose();
        if (_InterlockedDecrement(&p->weak) == 0)
            p->destroy();
    }
}

struct DialogBase {
    virtual ~DialogBase();
    char storage[0x70];
};

struct Member7C {
    char storage[0x18];
    ~Member7C();
};

struct Member94 {
    char storage[4];
    __declspec(dllimport) ~Member94() throw();
};

extern void (__thiscall *release94)(Member94*);

struct B_func_00412f30 {
    virtual ~B_func_00412f30();
};

struct S_func_00412f30 : B_func_00412f30 {
    char storage[4];
    ~S_func_00412f30();
};

struct MemberA8 {
    char storage[4];
    ~MemberA8();
};

struct CInsertObjectDialog : DialogBase {
    SharedMember first;
    Member7C member7C;
    Member94 member94;
    SharedMember second;
    S_func_00412f30 memberA0;
    MemberA8 memberA8;
    virtual ~CInsertObjectDialog();
};

CInsertObjectDialog::~CInsertObjectDialog()
{
}
