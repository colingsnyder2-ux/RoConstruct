// from server: 100% by Xemicl
// from server: 100% by tajop
// roc 2012-06 0081ef50  unit: RBX::Reflection::UTuple::$$A6A?AV?$shared_ptr::V?$function::?$sp_counted_impl_p  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0081ef50
//
// 0081ef50  6aff                 push -1
// 0081ef52  68f840ac00           push 0xac40f8
// 0081ef57  64a100000000         mov eax, dword ptr fs:[0]
// 0081ef5d  50                   push eax
// 0081ef5e  64892500000000       mov dword ptr fs:[0], esp
// 0081ef65  51                   push ecx
// 0081ef66  56                   push esi
// 0081ef67  8bf1                 mov esi, ecx
// 0081ef69  89742404             mov dword ptr [esp + 4], esi
// 0081ef6d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0081ef75  e866f9ffff           call 0x81e8e0
// 0081ef7a  8b36                 mov esi, dword ptr [esi]
// 0081ef7c  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0081ef84  85f6                 test esi, esi
// 0081ef86  743a                 je 0x81efc2
// 0081ef88  8d4605               lea eax, [esi + 5]
// 0081ef8b  85c0                 test eax, eax
// 0081ef8d  7405                 je 0x81ef94
// 0081ef8f  8d48fb               lea ecx, [eax - 5]
// 0081ef92  eb02                 jmp 0x81ef96
// 0081ef94  33c9                 xor ecx, ecx
// 0081ef96  8d71f8               lea esi, [ecx - 8]
// 0081ef99  8bc6                 mov eax, esi
// 0081ef9b  83caff               or edx, 0xffffffff
// 0081ef9e  f00fc110             lock xadd dword ptr [eax], edx
// 0081efa2  751e                 jne 0x81efc2
// 0081efa4  8b01                 mov eax, dword ptr [ecx]
// 0081efa6  8b10                 mov edx, dword ptr [eax]
// 0081efa8  6a00                 push 0
// 0081efaa  ffd2                 call edx
// 0081efac  8d4604               lea eax, [esi + 4]
// 0081efaf  83c9ff               or ecx, 0xffffffff
// 0081efb2  f00fc108             lock xadd dword ptr [eax], ecx
// 0081efb6  750a                 jne 0x81efc2
// 0081efb8  56                   push esi
// 0081efb9  ff15c829b200         call dword ptr [0xb229c8]
// 0081efbf  83c404               add esp, 4
// 0081efc2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0081efc6  5e                   pop esi
// 0081efc7  64890d00000000       mov dword ptr fs:[0], ecx
// 0081efce  83c410               add esp, 0x10
// 0081efd1  c3                   ret 

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

extern "C" void (__cdecl* imp_free)(void*);

struct Counts
{
    volatile long strong;
    volatile long weak;
};

struct Obj
{
    virtual ~Obj();
};

struct Ptr
{
    char* p;
    ~Ptr()
    {
        if (p)
        {
            char* a = p + 5;
            Obj* o = a ? (Obj*)(a - 5) : 0;
            Counts* c = (Counts*)((char*)o - 8);
            if (_InterlockedDecrement(&c->strong) == 0)
            {
                o->~Obj();
                if (_InterlockedDecrement(&c->weak) == 0)
                    imp_free(c);
            }
        }
    }
};

struct S
{
    Ptr m;
    void clear();
    ~S();
};

S::~S()
{
    clear();
}
