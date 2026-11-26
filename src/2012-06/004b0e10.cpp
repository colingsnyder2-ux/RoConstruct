// from server: 100% by Xemicl
// roc 2012-06 004b0e10  unit: CWebToolbox  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004b0e10
//
// 004b0e10  6aff                 push -1
// 004b0e12  68584aaa00           push 0xaa4a58
// 004b0e17  64a100000000         mov eax, dword ptr fs:[0]
// 004b0e1d  50                   push eax
// 004b0e1e  64892500000000       mov dword ptr fs:[0], esp
// 004b0e25  51                   push ecx
// 004b0e26  56                   push esi
// 004b0e27  8bf1                 mov esi, ecx
// 004b0e29  89742404             mov dword ptr [esp + 4], esi
// 004b0e2d  c706e435b600         mov dword ptr [esi], 0xb635e4
// 004b0e33  8b86fc000000         mov eax, dword ptr [esi + 0xfc]
// 004b0e39  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004b0e41  85c0                 test eax, eax
// 004b0e43  7408                 je 0x4b0e4d
// 004b0e45  8b08                 mov ecx, dword ptr [eax]
// 004b0e47  8b5108               mov edx, dword ptr [ecx + 8]
// 004b0e4a  50                   push eax
// 004b0e4b  ffd2                 call edx
// 004b0e4d  8bce                 mov ecx, esi
// 004b0e4f  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 004b0e57  e81442ffff           call 0x4a5070
// 004b0e5c  f644241801           test byte ptr [esp + 0x18], 1
// 004b0e61  7409                 je 0x4b0e6c
// 004b0e63  56                   push esi
// 004b0e64  e8ab124d00           call 0x982114
// 004b0e69  83c404               add esp, 4
// 004b0e6c  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004b0e70  8bc6                 mov eax, esi
// 004b0e72  5e                   pop esi
// 004b0e73  64890d00000000       mov dword ptr fs:[0], ecx
// 004b0e7a  83c410               add esp, 0x10
// 004b0e7d  c20400               ret 4
// copied from an identical function in another client (function ??_GCWebToolbox@@UAEPAXI@Z)

void __cdecl operator delete(void*);

struct B_func_00465a80 {
    virtual ~B_func_00465a80();
};

struct S_func_00465a80 : B_func_00465a80 {
    ~S_func_00465a80();
};

struct Interface;

struct InterfaceTable {
    void* slot0;
    void* slot1;
    unsigned long (__stdcall *release)(Interface*);
};

struct Interface {
    InterfaceTable* table;
};

struct CWebToolbox : S_func_00465a80 {
    char padding[248];
    Interface* object;
    virtual ~CWebToolbox();
    void* destroy(unsigned int flags);
};

__forceinline CWebToolbox::~CWebToolbox()
{
    if (object)
        object->table->release(object);
}

void* CWebToolbox::destroy(unsigned int flags)
{
    this->CWebToolbox::~CWebToolbox();
    if (flags & 1)
        operator delete(this);
    return this;
}