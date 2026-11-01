// from server: 100% by colin
// from server: 95% by king_originala
// roc 2008-06 00432970  unit: RBX::VHat::?$FactoryProduct::Creator  size: 179 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00432970
//
// 00432970  6aff                 push -1
// 00432972  68d8fd7b00           push 0x7bfdd8
// 00432977  64a100000000         mov eax, dword ptr fs:[0]
// 0043297d  50                   push eax
// 0043297e  64892500000000       mov dword ptr fs:[0], esp
// 00432985  83ec24               sub esp, 0x24
// 00432988  53                   push ebx
// 00432989  56                   push esi
// 0043298a  8bf1                 mov esi, ecx
// 0043298c  57                   push edi
// 0043298d  8d5e2c               lea ebx, [esi + 0x2c]
// 00432990  53                   push ebx
// 00432991  895c2410             mov dword ptr [esp + 0x10], ebx
// 00432995  ff15d4228000         call dword ptr [0x8022d4]
// 0043299b  c644241001           mov byte ptr [esp + 0x10], 1
// 004329a0  8b4604               mov eax, dword ptr [esi + 4]
// 004329a3  8b3db02d8000         mov edi, dword ptr [0x802db0]
// 004329a9  6a01                 push 1
// 004329ab  6865040000           push 0x465
// 004329b0  6865040000           push 0x465
// 004329b5  50                   push eax
// 004329b6  8d442424             lea eax, [esp + 0x24]
// 004329ba  50                   push eax
// 004329bb  c744244c00000000     mov dword ptr [esp + 0x4c], 0
// 004329c3  ffd7                 call edi
// 004329c5  85c0                 test eax, eax
// 004329c7  7433                 je 0x4329fc
// 004329c9  8da42400000000       lea esp, [esp]
// 004329d0  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004329d4  85c9                 test ecx, ecx
// 004329d6  7409                 je 0x4329e1
// 004329d8  8b11                 mov edx, dword ptr [ecx]
// 004329da  8b4204               mov eax, dword ptr [edx + 4]
// 004329dd  6a01                 push 1
// 004329df  ffd0                 call eax
// 004329e1  8b4604               mov eax, dword ptr [esi + 4]
// 004329e4  6a01                 push 1
// 004329e6  6865040000           push 0x465
// 004329eb  6865040000           push 0x465
// 004329f0  50                   push eax
// 004329f1  8d4c2424             lea ecx, [esp + 0x24]
// 004329f5  51                   push ecx
// 004329f6  ffd7                 call edi
// 004329f8  85c0                 test eax, eax
// 004329fa  75d4                 jne 0x4329d0
// 004329fc  8b54244c             mov edx, dword ptr [esp + 0x4c]
// 00432a00  53                   push ebx
// 00432a01  c70200000000         mov dword ptr [edx], 0
// 00432a07  ff15f4218000         call dword ptr [0x8021f4]
// 00432a0d  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 00432a11  5f                   pop edi
// 00432a12  5e                   pop esi
// 00432a13  33c0                 xor eax, eax
// 00432a15  5b                   pop ebx
// 00432a16  64890d00000000       mov dword ptr fs:[0], ecx
// 00432a1d  83c430               add esp, 0x30
// 00432a20  c21000               ret 0x10

struct CriticalSection {
    unsigned char data[24];
};

struct Payload {
    virtual void unused();
    virtual ~Payload();
};

struct Message {
    void* window;
    unsigned int message;
    unsigned int wParam;
    Payload* lParam;
    unsigned long time;
    long x;
    long y;
};

extern "C" {
    __declspec(dllimport) void __stdcall EnterCriticalSection(CriticalSection*);
    __declspec(dllimport) void __stdcall LeaveCriticalSection(CriticalSection*);
    __declspec(dllimport) int __stdcall PeekMessageA(
        Message*, void*, unsigned int, unsigned int, unsigned int);
}

struct Lock {
    CriticalSection* section;
    bool owned;

    Lock(CriticalSection*);
    ~Lock();
    void unlock();
};

inline Lock::Lock(CriticalSection* p) : section(p) {
    EnterCriticalSection(section);
    owned = true;
}

inline Lock::~Lock() {
    if (owned)
        LeaveCriticalSection(section);
}

inline void Lock::unlock() {
    LeaveCriticalSection(section);
    owned = false;
}

struct S {
    unsigned char reserved0[4];
    void* window;
    unsigned char reserved1[36];
    CriticalSection section;

    int f(unsigned int, unsigned int, unsigned int, int*);
};

int S::f(unsigned int, unsigned int, unsigned int, int* result) {
    Lock lock(&section);
    Message message;

    for (;;) {
        void* w = window;
        if (!PeekMessageA(&message, w, 0x465, 0x465, 1))
            break;
        delete message.lParam;
    }

    *result = 0;
    lock.unlock();
    return 0;
}
