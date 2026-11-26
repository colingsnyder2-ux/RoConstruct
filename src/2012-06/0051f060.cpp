// from server: 100% by Xemicl
// roc 2012-06 0051f060  unit: RBX::Network::P8Player::?$GetSetImpl  size: 237 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0051f060
//
// 0051f060  6aff                 push -1
// 0051f062  6878b0aa00           push 0xaab078
// 0051f067  64a100000000         mov eax, dword ptr fs:[0]
// 0051f06d  50                   push eax
// 0051f06e  64892500000000       mov dword ptr fs:[0], esp
// 0051f075  51                   push ecx
// 0051f076  56                   push esi
// 0051f077  57                   push edi
// 0051f078  8bf9                 mov edi, ecx
// 0051f07a  8d44241c             lea eax, [esp + 0x1c]
// 0051f07e  50                   push eax
// 0051f07f  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0051f087  e8a41e3600           call 0x880f30
// 0051f08c  83c404               add esp, 4
// 0051f08f  84c0                 test al, al
// 0051f091  0f8589000000         jne 0x51f120
// 0051f097  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 0051f09b  88442408             mov byte ptr [esp + 8], al
// 0051f09f  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0051f0a3  8b442424             mov eax, dword ptr [esp + 0x24]
// 0051f0a7  51                   push ecx
// 0051f0a8  52                   push edx
// 0051f0a9  83ec10               sub esp, 0x10
// 0051f0ac  8bf4                 mov esi, esp
// 0051f0ae  89642444             mov dword ptr [esp + 0x44], esp
// 0051f0b2  894608               mov dword ptr [esi + 8], eax
// 0051f0b5  c70600000000         mov dword ptr [esi], 0
// 0051f0bb  83f808               cmp eax, 8
// 0051f0be  7708                 ja 0x51f0c8
// 0051f0c0  8bc6                 mov eax, esi
// 0051f0c2  8d4c2434             lea ecx, [esp + 0x34]
// 0051f0c6  eb0f                 jmp 0x51f0d7
// 0051f0c8  50                   push eax
// 0051f0c9  e822334600           call 0x9823f0
// 0051f0ce  8906                 mov dword ptr [esi], eax
// 0051f0d0  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0051f0d4  83c404               add esp, 4
// 0051f0d7  8b5608               mov edx, dword ptr [esi + 8]
// 0051f0da  52                   push edx
// 0051f0db  51                   push ecx
// 0051f0dc  50                   push eax
// 0051f0dd  e87a454600           call 0x98365c
// 0051f0e2  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 0051f0e6  83c40c               add esp, 0xc
// 0051f0e9  8bcf                 mov ecx, edi
// 0051f0eb  89460c               mov dword ptr [esi + 0xc], eax
// 0051f0ee  e85de8ffff           call 0x51d950
// 0051f0f3  837c242408           cmp dword ptr [esp + 0x24], 8
// 0051f0f8  7611                 jbe 0x51f10b
// 0051f0fa  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0051f0fe  85c0                 test eax, eax
// 0051f100  7409                 je 0x51f10b
// 0051f102  50                   push eax
// 0051f103  e8b2324600           call 0x9823ba
// 0051f108  83c404               add esp, 4
// 0051f10b  b001                 mov al, 1
// 0051f10d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0051f111  64890d00000000       mov dword ptr fs:[0], ecx
// 0051f118  5f                   pop edi
// 0051f119  5e                   pop esi
// 0051f11a  83c410               add esp, 0x10
// 0051f11d  c21800               ret 0x18
// 0051f120  837c242408           cmp dword ptr [esp + 0x24], 8
// 0051f125  7611                 jbe 0x51f138
// 0051f127  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0051f12b  85c0                 test eax, eax
// 0051f12d  7409                 je 0x51f138
// 0051f12f  50                   push eax
// 0051f130  e885324600           call 0x9823ba
// 0051f135  83c404               add esp, 4
// 0051f138  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0051f13c  5f                   pop edi
// 0051f13d  32c0                 xor al, al
// 0051f13f  64890d00000000       mov dword ptr fs:[0], ecx
// 0051f146  5e                   pop esi
// 0051f147  83c410               add esp, 0x10
// 0051f14a  c21800               ret 0x18
// copied from an identical function in another client (function ?assign_to@basic_vtable0@@QAE_NUFunctor@@AATfunction_buffer@@Ufunction_obj_tag@@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string.h>
#include <new>

struct Functor {
    union { char buf[8]; char* ptr; };
    unsigned int size;
    int extra;
    const char* data() const { return size > 8 ? ptr : buf; }
    __forceinline Functor(const Functor& o) : size(o.size)
    {
        ptr = 0;
        char* d;
        const char* src;
        if (size <= 8) {
            d = buf;
            src = o.buf;
        } else {
            d = ptr = (char*)operator new(size);
            src = o.ptr;
        }
        memcpy(d, src, size);
        extra = o.extra;
    }
    ~Functor()
    {
        if (size > 8 && ptr)
            operator delete(ptr);
    }
};

struct true_ {};
struct function_obj_tag {};
union function_buffer { void* obj_ptr; double align; char data[16]; };

inline bool has_empty_target(...) { return false; }

struct basic_vtable0 {
    void assign_functor(Functor f, function_buffer& functor, true_);
    bool assign_to(Functor f, function_buffer& functor, function_obj_tag);
};

bool basic_vtable0::assign_to(Functor f, function_buffer& functor, function_obj_tag)
{
    if (!has_empty_target(&f)) {
        assign_functor(f, functor, true_());
        return true;
    } else {
        return false;
    }
}