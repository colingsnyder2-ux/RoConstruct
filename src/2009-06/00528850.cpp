// from server: 93% by EspClaude
// from server: 100% by Espeon
// roc 2008-06 004db4f0  unit: RBX::ViewNew::ViewRbxGfx  size: 209 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004db4f0
//
// 004db4f0  6aff                 push -1
// 004db4f2  6828a17c00           push 0x7ca128
// 004db4f7  64a100000000         mov eax, dword ptr fs:[0]
// 004db4fd  50                   push eax
// 004db4fe  64892500000000       mov dword ptr fs:[0], esp
// 004db505  51                   push ecx
// 004db506  53                   push ebx
// 004db507  56                   push esi
// 004db508  8bf1                 mov esi, ecx
// 004db50a  57                   push edi
// 004db50b  8974240c             mov dword ptr [esp + 0xc], esi
// 004db50f  c706706c8200         mov dword ptr [esi], 0x826c70
// 004db515  8b4e04               mov ecx, dword ptr [esi + 4]
// 004db518  8b01                 mov eax, dword ptr [ecx]
// 004db51a  8b500c               mov edx, dword ptr [eax + 0xc]
// 004db51d  33db                 xor ebx, ebx
// 004db51f  895c2418             mov dword ptr [esp + 0x18], ebx
// 004db523  ffd2                 call edx
// 004db525  8b4e08               mov ecx, dword ptr [esi + 8]
// 004db528  3bcb                 cmp ecx, ebx
// 004db52a  7408                 je 0x4db534
// 004db52c  8b01                 mov eax, dword ptr [ecx]
// 004db52e  8b10                 mov edx, dword ptr [eax]
// 004db530  6a01                 push 1
// 004db532  ffd2                 call edx
// 004db534  895e08               mov dword ptr [esi + 8], ebx
// 004db537  8b7e10               mov edi, dword ptr [esi + 0x10]
// 004db53a  3bfb                 cmp edi, ebx
// 004db53c  7410                 je 0x4db54e
// 004db53e  8bcf                 mov ecx, edi
// 004db540  e81bbfffff           call 0x4d7460
// 004db545  57                   push edi
// 004db546  e82f511c00           call 0x6a067a
// 004db54b  83c404               add esp, 4
// 004db54e  895e10               mov dword ptr [esi + 0x10], ebx
// 004db551  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004db554  3bfb                 cmp edi, ebx
// 004db556  7416                 je 0x4db56e
// 004db558  8bcf                 mov ecx, edi
// 004db55a  c707d89c8100         mov dword ptr [edi], 0x819cd8
// 004db560  e81b11f8ff           call 0x45c680
// 004db565  57                   push edi
// 004db566  e80f511c00           call 0x6a067a
// 004db56b  83c404               add esp, 4
// 004db56e  895e0c               mov dword ptr [esi + 0xc], ebx
// 004db571  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 004db574  3bcb                 cmp ecx, ebx
// 004db576  7405                 je 0x4db57d
// 004db578  e8037efdff           call 0x4b3380
// 004db57d  e8aefbffff           call 0x4db130
// 004db582  e8b9faffff           call 0x4db040
// 004db587  e8c4f9ffff           call 0x4daf50
// 004db58c  e8dfa00000           call 0x4e5670
// 004db591  e87afdffff           call 0x4db310
// 004db596  e885fcffff           call 0x4db220
// 004db59b  e860feffff           call 0x4db400
// 004db5a0  8bce                 mov ecx, esi
// 004db5a2  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 004db5aa  e871d3ffff           call 0x4d8920
// 004db5af  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004db5b3  5f                   pop edi
// 004db5b4  5e                   pop esi
// 004db5b5  5b                   pop ebx
// 004db5b6  64890d00000000       mov dword ptr fs:[0], ecx
// 004db5bd  83c410               add esp, 0x10
// 004db5c0  c3                   ret 

#include <intrin.h>

void __cdecl operator delete(void*);

extern "C" void __cdecl cleanup_004db130();
extern "C" void __cdecl cleanup_004db040();
extern "C" void __cdecl cleanup_004daf50();
extern "C" void __cdecl cleanup_004e5670();
extern "C" void __cdecl cleanup_004db310();
extern "C" void __cdecl cleanup_004db220();
extern "C" void __cdecl cleanup_004db400();

struct Interface {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void release();
};

struct OwnedVirtual {
    virtual ~OwnedVirtual();
};

struct OwnedDirect {
    ~OwnedDirect();
};

struct ProductBase {
    virtual void slot0();
    ~ProductBase();
};

struct Product : ProductBase {
    virtual void slot0();
    ~Product() {}
};

struct Resource {
    void release();
};

struct ViewBase {
    virtual ~ViewBase();
};

struct View : ViewBase {
    Interface* interface_;
    OwnedVirtual* owned_;
    Product* product_;
    OwnedDirect* direct_;
    Resource* resource_;
    virtual ~View();
};

View::~View()
{
    interface_->release();

    delete owned_;
    owned_ = 0;
    _ReadWriteBarrier();

    delete direct_;
    direct_ = 0;
    _ReadWriteBarrier();

    delete product_;
    product_ = 0;
    _ReadWriteBarrier();

    if (resource_)
        resource_->release();

    cleanup_004db130();
    cleanup_004db040();
    cleanup_004daf50();
    cleanup_004e5670();
    cleanup_004db310();
    cleanup_004db220();
    cleanup_004db400();
}
