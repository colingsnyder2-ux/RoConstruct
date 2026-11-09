// from server: 100% by EspClaude
// roc 2009-06 0046d880  unit: CWebToolbox  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0046d880
//
// 0046d880  6aff                 push -1
// 0046d882  6848d38400           push 0x84d348
// 0046d887  64a100000000         mov eax, dword ptr fs:[0]
// 0046d88d  50                   push eax
// 0046d88e  64892500000000       mov dword ptr fs:[0], esp
// 0046d895  51                   push ecx
// 0046d896  56                   push esi
// 0046d897  8bf1                 mov esi, ecx
// 0046d899  89742404             mov dword ptr [esp + 4], esi
// 0046d89d  c7064cd18b00         mov dword ptr [esi], 0x8bd14c
// 0046d8a3  8b86fc000000         mov eax, dword ptr [esi + 0xfc]
// 0046d8a9  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0046d8b1  85c0                 test eax, eax
// 0046d8b3  7408                 je 0x46d8bd
// 0046d8b5  8b08                 mov ecx, dword ptr [eax]
// 0046d8b7  8b5108               mov edx, dword ptr [ecx + 8]
// 0046d8ba  50                   push eax
// 0046d8bb  ffd2                 call edx
// 0046d8bd  8bce                 mov ecx, esi
// 0046d8bf  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0046d8c7  e8f48fffff           call 0x4668c0
// 0046d8cc  f644241801           test byte ptr [esp + 0x18], 1
// 0046d8d1  7409                 je 0x46d8dc
// 0046d8d3  56                   push esi
// 0046d8d4  e859b12a00           call 0x718a32
// 0046d8d9  83c404               add esp, 4
// 0046d8dc  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0046d8e0  8bc6                 mov eax, esi
// 0046d8e2  5e                   pop esi
// 0046d8e3  64890d00000000       mov dword ptr fs:[0], ecx
// 0046d8ea  83c410               add esp, 0x10
// 0046d8ed  c20400               ret 4
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