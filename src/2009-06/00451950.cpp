// from server: 100% by EspClaude
// from server: 88% by EspClaude
// roc 2009-06 00451950  unit: CRobloxDoc  size: 211 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00451950
//
// 00451950  6aff                 push -1
// 00451952  68d0168500           push 0x8516d0
// 00451957  64a100000000         mov eax, dword ptr fs:[0]
// 0045195d  50                   push eax
// 0045195e  64892500000000       mov dword ptr fs:[0], esp
// 00451965  83ec10               sub esp, 0x10
// 00451968  8b899c000000         mov ecx, dword ptr [ecx + 0x9c]
// 0045196e  56                   push esi
// 0045196f  8d44240c             lea eax, [esp + 0xc]
// 00451973  50                   push eax
// 00451974  e8b7311d00           call 0x624b30
// 00451979  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0045197d  6a01                 push 1
// 0045197f  83ec08               sub esp, 8
// 00451982  8bc4                 mov eax, esp
// 00451984  8908                 mov dword ptr [eax], ecx
// 00451986  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0045198a  895004               mov dword ptr [eax + 4], edx
// 0045198d  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00451991  c744242800000000     mov dword ptr [esp + 0x28], 0
// 00451999  89642414             mov dword ptr [esp + 0x14], esp
// 0045199d  85c0                 test eax, eax
// 0045199f  740c                 je 0x4519ad
// 004519a1  83c004               add eax, 4
// 004519a4  b901000000           mov ecx, 1
// 004519a9  f00fc108             lock xadd dword ptr [eax], ecx
// 004519ad  8d4c2410             lea ecx, [esp + 0x10]
// 004519b1  e85a211b00           call 0x603b10
// 004519b6  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004519ba  c644241c01           mov byte ptr [esp + 0x1c], 1
// 004519bf  e84c89ffff           call 0x44a310
// 004519c4  8bc8                 mov ecx, eax
// 004519c6  e855941c00           call 0x61ae20
// 004519cb  8d4c2404             lea ecx, [esp + 4]
// 004519cf  c644241c00           mov byte ptr [esp + 0x1c], 0
// 004519d4  e8c7db1a00           call 0x5ff5a0
// 004519d9  8b742410             mov esi, dword ptr [esp + 0x10]
// 004519dd  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 004519e5  85f6                 test esi, esi
// 004519e7  742a                 je 0x451a13
// 004519e9  8d5604               lea edx, [esi + 4]
// 004519ec  83c8ff               or eax, 0xffffffff
// 004519ef  f00fc102             lock xadd dword ptr [edx], eax
// 004519f3  751e                 jne 0x451a13
// 004519f5  8b16                 mov edx, dword ptr [esi]
// 004519f7  8b4204               mov eax, dword ptr [edx + 4]
// 004519fa  8bce                 mov ecx, esi
// 004519fc  ffd0                 call eax
// 004519fe  8d4e08               lea ecx, [esi + 8]
// 00451a01  83caff               or edx, 0xffffffff
// 00451a04  f00fc111             lock xadd dword ptr [ecx], edx
// 00451a08  7509                 jne 0x451a13
// 00451a0a  8b06                 mov eax, dword ptr [esi]
// 00451a0c  8b5008               mov edx, dword ptr [eax + 8]
// 00451a0f  8bce                 mov ecx, esi
// 00451a11  ffd2                 call edx
// 00451a13  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00451a17  64890d00000000       mov dword ptr fs:[0], ecx
// 00451a1e  5e                   pop esi
// 00451a1f  83c41c               add esp, 0x1c
// 00451a22  c3                   ret 

// from server: 100% by king_originala
// roc 2008-06 00453670  unit: CRobloxDoc  size: 209 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00453670
//
// 00453670  6aff                 push -1
// 00453672  68f01e7c00           push 0x7c1ef0
// 00453677  64a100000000         mov eax, dword ptr fs:[0]
// 0045367d  50                   push eax
// 0045367e  64892500000000       mov dword ptr fs:[0], esp
// 00453685  83ec18               sub esp, 0x18
// 00453688  8b8994000000         mov ecx, dword ptr [ecx + 0x94]
// 0045368e  56                   push esi
// 0045368f  8d442408             lea eax, [esp + 8]
// 00453693  50                   push eax
// 00453694  e8a7720100           call 0x46a940
// 00453699  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0045369d  83ec08               sub esp, 8
// 004536a0  8bc4                 mov eax, esp
// 004536a2  8908                 mov dword ptr [eax], ecx
// 004536a4  8b542414             mov edx, dword ptr [esp + 0x14]
// 004536a8  895004               mov dword ptr [eax + 4], edx
// 004536ab  8b442414             mov eax, dword ptr [esp + 0x14]
// 004536af  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 004536b7  8964240c             mov dword ptr [esp + 0xc], esp
// 004536bb  85c0                 test eax, eax
// 004536bd  740c                 je 0x4536cb
// 004536bf  83c004               add eax, 4
// 004536c2  b901000000           mov ecx, 1
// 004536c7  f00fc108             lock xadd dword ptr [eax], ecx
// 004536cb  8d4c2418             lea ecx, [esp + 0x18]
// 004536cf  e86ce4fbff           call 0x411b40
// 004536d4  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004536d8  c644242401           mov byte ptr [esp + 0x24], 1
// 004536dd  e81ef9ffff           call 0x453000
// 004536e2  8bc8                 mov ecx, eax
// 004536e4  e8476a1300           call 0x58a130
// 004536e9  8d4c2410             lea ecx, [esp + 0x10]
// 004536ed  c644242400           mov byte ptr [esp + 0x24], 0
// 004536f2  e8c93c1200           call 0x5773c0
// 004536f7  8b74240c             mov esi, dword ptr [esp + 0xc]
// 004536fb  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 00453703  85f6                 test esi, esi
// 00453705  742a                 je 0x453731
// 00453707  8d5604               lea edx, [esi + 4]
// 0045370a  83c8ff               or eax, 0xffffffff
// 0045370d  f00fc102             lock xadd dword ptr [edx], eax
// 00453711  751e                 jne 0x453731
// 00453713  8b16                 mov edx, dword ptr [esi]
// 00453715  8b4204               mov eax, dword ptr [edx + 4]
// 00453718  8bce                 mov ecx, esi
// 0045371a  ffd0                 call eax
// 0045371c  8d4e08               lea ecx, [esi + 8]
// 0045371f  83caff               or edx, 0xffffffff
// 00453722  f00fc111             lock xadd dword ptr [ecx], edx
// 00453726  7509                 jne 0x453731
// 00453728  8b06                 mov eax, dword ptr [esi]
// 0045372a  8b5008               mov edx, dword ptr [eax + 8]
// 0045372d  8bce                 mov ecx, esi
// 0045372f  ffd2                 call edx
// 00453731  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00453735  64890d00000000       mov dword ptr fs:[0], ecx
// 0045373c  5e                   pop esi
// 0045373d  83c424               add esp, 0x24
// 00453740  c3                   ret 

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

    void addRef();
    void release();
};

__forceinline void Control::addRef() {
    volatile long* count =
        reinterpret_cast<volatile long*>(reinterpret_cast<char*>(this) + 4);
    _InterlockedExchangeAdd(count, 1);
}

__forceinline void Control::release() {
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct Result {
    void invoke();
};

struct Object {
    Result* getResult();
};

struct Shared {
    Object* pointer;
    Control* control;

    Shared(const Shared& other);
    ~Shared();
};

__forceinline Shared::Shared(const Shared& other)
    : pointer(other.pointer), control(other.control) {
    if (control)
        control->addRef();
}

__forceinline Shared::~Shared() {
    if (control)
        control->release();
}

struct Source {
    Shared get();
};

struct Guard {
    unsigned char storage[4];
    Guard(Shared value, bool flag);
    ~Guard();
};

struct CRobloxDoc {
    unsigned char padding[0x9c];
    Source* source;
    void f();
};

void CRobloxDoc::f() {
    Shared value = source->get();
    Guard guard(value, true);
    value.pointer->getResult()->invoke();
}
