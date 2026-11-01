// from server: 100% by colin
// from server: 98% by king_originala
// roc 2008-06 00465830  unit: CScriptEditor  size: 361 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00465830
//
// 00465830  6aff                 push -1
// 00465832  68cc337c00           push 0x7c33cc
// 00465837  64a100000000         mov eax, dword ptr fs:[0]
// 0046583d  50                   push eax
// 0046583e  64892500000000       mov dword ptr fs:[0], esp
// 00465845  83ec08               sub esp, 8
// 00465848  53                   push ebx
// 00465849  55                   push ebp
// 0046584a  56                   push esi
// 0046584b  8bf1                 mov esi, ecx
// 0046584d  8daef0000000         lea ebp, [esi + 0xf0]
// 00465853  8d9e14010000         lea ebx, [esi + 0x114]
// 00465859  57                   push edi
// 0046585a  89742410             mov dword ptr [esp + 0x10], esi
// 0046585e  c706dcb38100         mov dword ptr [esi], 0x81b3dc
// 00465864  c786ec000000d0b38100 mov dword ptr [esi + 0xec], 0x81b3d0
// 0046586e  c74500bcb38100       mov dword ptr [ebp], 0x81b3bc
// 00465875  c703a8b38100         mov dword ptr [ebx], 0x81b3a8
// 0046587b  83ec08               sub esp, 8
// 0046587e  8bc4                 mov eax, esp
// 00465880  c70000000000         mov dword ptr [eax], 0
// 00465886  c744242806000000     mov dword ptr [esp + 0x28], 6
// 0046588e  8964241c             mov dword ptr [esp + 0x1c], esp
// 00465892  c7400400000000       mov dword ptr [eax + 4], 0
// 00465899  e8c2f9ffff           call 0x465260
// 0046589e  8d8e58010000         lea ecx, [esi + 0x158]
// 004658a4  c644242005           mov byte ptr [esp + 0x20], 5
// 004658a9  c70128b28100         mov dword ptr [ecx], 0x81b228
// 004658af  e8ecb8faff           call 0x4111a0
// 004658b4  8bbe50010000         mov edi, dword ptr [esi + 0x150]
// 004658ba  c644242004           mov byte ptr [esp + 0x20], 4
// 004658bf  85ff                 test edi, edi
// 004658c1  742a                 je 0x4658ed
// 004658c3  8d4704               lea eax, [edi + 4]
// 004658c6  83c9ff               or ecx, 0xffffffff
// 004658c9  f00fc108             lock xadd dword ptr [eax], ecx
// 004658cd  751e                 jne 0x4658ed
// 004658cf  8b17                 mov edx, dword ptr [edi]
// 004658d1  8b4204               mov eax, dword ptr [edx + 4]
// 004658d4  8bcf                 mov ecx, edi
// 004658d6  ffd0                 call eax
// 004658d8  8d4f08               lea ecx, [edi + 8]
// 004658db  83caff               or edx, 0xffffffff
// 004658de  f00fc111             lock xadd dword ptr [ecx], edx
// 004658e2  7509                 jne 0x4658ed
// 004658e4  8b07                 mov eax, dword ptr [edi]
// 004658e6  8b5008               mov edx, dword ptr [eax + 8]
// 004658e9  8bcf                 mov ecx, edi
// 004658eb  ffd2                 call edx
// 004658ed  8bbe48010000         mov edi, dword ptr [esi + 0x148]
// 004658f3  c644242003           mov byte ptr [esp + 0x20], 3
// 004658f8  85ff                 test edi, edi
// 004658fa  742a                 je 0x465926
// 004658fc  8d4704               lea eax, [edi + 4]
// 004658ff  83c9ff               or ecx, 0xffffffff
// 00465902  f00fc108             lock xadd dword ptr [eax], ecx
// 00465906  751e                 jne 0x465926
// 00465908  8b17                 mov edx, dword ptr [edi]
// 0046590a  8b4204               mov eax, dword ptr [edx + 4]
// 0046590d  8bcf                 mov ecx, edi
// 0046590f  ffd0                 call eax
// 00465911  8d4f08               lea ecx, [edi + 8]
// 00465914  83caff               or edx, 0xffffffff
// 00465917  f00fc111             lock xadd dword ptr [ecx], edx
// 0046591b  7509                 jne 0x465926
// 0046591d  8b07                 mov eax, dword ptr [edi]
// 0046591f  8b5008               mov edx, dword ptr [eax + 8]
// 00465922  8bcf                 mov ecx, edi
// 00465924  ffd2                 call edx
// 00465926  8bbe3c010000         mov edi, dword ptr [esi + 0x13c]
// 0046592c  c644242002           mov byte ptr [esp + 0x20], 2
// 00465931  85ff                 test edi, edi
// 00465933  742a                 je 0x46595f
// 00465935  8d4704               lea eax, [edi + 4]
// 00465938  83c9ff               or ecx, 0xffffffff
// 0046593b  f00fc108             lock xadd dword ptr [eax], ecx
// 0046593f  751e                 jne 0x46595f
// 00465941  8b17                 mov edx, dword ptr [edi]
// 00465943  8b4204               mov eax, dword ptr [edx + 4]
// 00465946  8bcf                 mov ecx, edi
// 00465948  ffd0                 call eax
// 0046594a  8d4f08               lea ecx, [edi + 8]
// 0046594d  83caff               or edx, 0xffffffff
// 00465950  f00fc111             lock xadd dword ptr [ecx], edx
// 00465954  7509                 jne 0x46595f
// 00465956  8b07                 mov eax, dword ptr [edi]
// 00465958  8b5008               mov edx, dword ptr [eax + 8]
// 0046595b  8bcf                 mov ecx, edi
// 0046595d  ffd2                 call edx
// 0046595f  8bcb                 mov ecx, ebx
// 00465961  c644242001           mov byte ptr [esp + 0x20], 1
// 00465966  e895f5ffff           call 0x464f00
// 0046596b  8bcd                 mov ecx, ebp
// 0046596d  c644242000           mov byte ptr [esp + 0x20], 0
// 00465972  e8a9f4ffff           call 0x464e20
// 00465977  8bce                 mov ecx, esi
// 00465979  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 00465981  e84ac6ffff           call 0x461fd0
// 00465986  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0046598a  5f                   pop edi
// 0046598b  5e                   pop esi
// 0046598c  5d                   pop ebp
// 0046598d  64890d00000000       mov dword ptr fs:[0], ecx
// 00465994  5b                   pop ebx
// 00465995  83c414               add esp, 0x14
// 00465998  c3                   ret 

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct RefCount {
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Count {
    RefCount* pi;
    Count() : pi(0) {}
    Count(const Count& o) : pi(o.pi) { if (pi) _InterlockedExchangeAdd(&pi->strong, 1); }
    ~Count()
    {
        RefCount* p = pi;
        if (p && _InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
};

struct Shared {
    void* object;
    Count count;
    Shared() : object(0) {}
};

struct Base {
    virtual ~Base();
    char storage[0xe8];
};

struct Interface {
    virtual void method() = 0;
};

struct BaseF0 {
    virtual ~BaseF0();
    char storage[0x20];
};

struct Base114 {
    virtual ~Base114();
    char storage[0x20];
};

struct Tail {
    virtual ~Tail();
    void cleanup();
};

__forceinline Tail::~Tail()
{
    cleanup();
}

struct CScriptEditor : Base, Interface, BaseF0, Base114 {
    Shared first;
    unsigned long gap140;
    Shared second;
    Shared third;
    unsigned long gap154;
    Tail tail;

    virtual void method();
    void reset(Shared);
    virtual ~CScriptEditor();
};

CScriptEditor::~CScriptEditor()
{
    reset(Shared());
}
