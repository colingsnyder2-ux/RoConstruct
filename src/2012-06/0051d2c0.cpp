// from server: 100% by Xemicl
// roc 2012-06 0051d2c0  unit: Ogre::istreamDataStream  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0051d2c0
//
// 0051d2c0  56                   push esi
// 0051d2c1  57                   push edi
// 0051d2c2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0051d2c6  8b4708               mov eax, dword ptr [edi + 8]
// 0051d2c9  8bf1                 mov esi, ecx
// 0051d2cb  894608               mov dword ptr [esi + 8], eax
// 0051d2ce  c70600000000         mov dword ptr [esi], 0
// 0051d2d4  83f808               cmp eax, 8
// 0051d2d7  7706                 ja 0x51d2df
// 0051d2d9  8bc6                 mov eax, esi
// 0051d2db  8bcf                 mov ecx, edi
// 0051d2dd  eb0d                 jmp 0x51d2ec
// 0051d2df  50                   push eax
// 0051d2e0  e80b514600           call 0x9823f0
// 0051d2e5  8906                 mov dword ptr [esi], eax
// 0051d2e7  8b0f                 mov ecx, dword ptr [edi]
// 0051d2e9  83c404               add esp, 4
// 0051d2ec  8b5608               mov edx, dword ptr [esi + 8]
// 0051d2ef  52                   push edx
// 0051d2f0  51                   push ecx
// 0051d2f1  50                   push eax
// 0051d2f2  e865634600           call 0x98365c
// 0051d2f7  8b470c               mov eax, dword ptr [edi + 0xc]
// 0051d2fa  83c40c               add esp, 0xc
// 0051d2fd  89460c               mov dword ptr [esi + 0xc], eax
// 0051d300  5f                   pop edi
// 0051d301  8bc6                 mov eax, esi
// 0051d303  5e                   pop esi
// 0051d304  c20400               ret 4
// copied from an identical function in another client (function ??0Functor@@QAE@ABU0@@Z)

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