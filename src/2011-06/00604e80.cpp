// from server: 100% by Yeetserama
// roc 2011-06 00604e80  unit: RBX::ClearBackpack  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00604e80
//
// 00604e80  6aff                 push -1
// 00604e82  68787f9e00           push 0x9e7f78
// 00604e87  64a100000000         mov eax, dword ptr fs:[0]
// 00604e8d  50                   push eax
// 00604e8e  64892500000000       mov dword ptr fs:[0], esp
// 00604e95  51                   push ecx
// 00604e96  56                   push esi
// 00604e97  57                   push edi
// 00604e98  8bf9                 mov edi, ecx
// 00604e9a  897c2408             mov dword ptr [esp + 8], edi
// 00604e9e  c707fc2fa900         mov dword ptr [edi], 0xa92ffc
// 00604ea4  8b7718               mov esi, dword ptr [edi + 0x18]
// 00604ea7  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00604eaf  85f6                 test esi, esi
// 00604eb1  742a                 je 0x604edd
// 00604eb3  8d4604               lea eax, [esi + 4]
// 00604eb6  83c9ff               or ecx, 0xffffffff
// 00604eb9  f00fc108             lock xadd dword ptr [eax], ecx
// 00604ebd  751e                 jne 0x604edd
// 00604ebf  8b16                 mov edx, dword ptr [esi]
// 00604ec1  8b4204               mov eax, dword ptr [edx + 4]
// 00604ec4  8bce                 mov ecx, esi
// 00604ec6  ffd0                 call eax
// 00604ec8  8d4e08               lea ecx, [esi + 8]
// 00604ecb  83caff               or edx, 0xffffffff
// 00604ece  f00fc111             lock xadd dword ptr [ecx], edx
// 00604ed2  7509                 jne 0x604edd
// 00604ed4  8b06                 mov eax, dword ptr [esi]
// 00604ed6  8b5008               mov edx, dword ptr [eax + 8]
// 00604ed9  8bce                 mov ecx, esi
// 00604edb  ffd2                 call edx
// 00604edd  8bcf                 mov ecx, edi
// 00604edf  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00604ee7  e874590000           call 0x60a860
// 00604eec  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00604ef0  5f                   pop edi
// 00604ef1  5e                   pop esi
// 00604ef2  64890d00000000       mov dword ptr fs:[0], ecx
// 00604ef9  83c410               add esp, 0x10
// 00604efc  c3                   ret 
// copied from an identical function in another client (function ??1ClearBackpack@ns_ROCX00000b@@UAE@XZ)

namespace ns_ROCX00000b {
// from server: 100% by king_originala
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
}
