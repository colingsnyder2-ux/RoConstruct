// from server: 100% by Yeetserama
// roc 2010-06 0047c2a0  unit: CWebToolbox  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0047c2a0
//
// 0047c2a0  6aff                 push -1
// 0047c2a2  68b8509800           push 0x9850b8
// 0047c2a7  64a100000000         mov eax, dword ptr fs:[0]
// 0047c2ad  50                   push eax
// 0047c2ae  64892500000000       mov dword ptr fs:[0], esp
// 0047c2b5  51                   push ecx
// 0047c2b6  56                   push esi
// 0047c2b7  8bf1                 mov esi, ecx
// 0047c2b9  89742404             mov dword ptr [esp + 4], esi
// 0047c2bd  c706dc28a100         mov dword ptr [esi], 0xa128dc
// 0047c2c3  8b86fc000000         mov eax, dword ptr [esi + 0xfc]
// 0047c2c9  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0047c2d1  85c0                 test eax, eax
// 0047c2d3  7408                 je 0x47c2dd
// 0047c2d5  8b08                 mov ecx, dword ptr [eax]
// 0047c2d7  8b5108               mov edx, dword ptr [ecx + 8]
// 0047c2da  50                   push eax
// 0047c2db  ffd2                 call edx
// 0047c2dd  8bce                 mov ecx, esi
// 0047c2df  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0047c2e7  e8248effff           call 0x475110
// 0047c2ec  f644241801           test byte ptr [esp + 0x18], 1
// 0047c2f1  7409                 je 0x47c2fc
// 0047c2f3  56                   push esi
// 0047c2f4  e8a1b63200           call 0x7a799a
// 0047c2f9  83c404               add esp, 4
// 0047c2fc  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0047c300  8bc6                 mov eax, esi
// 0047c302  5e                   pop esi
// 0047c303  64890d00000000       mov dword ptr fs:[0], ecx
// 0047c30a  83c410               add esp, 0x10
// 0047c30d  c20400               ret 4
// copied from an identical function in another client (function ??_GCWebToolbox@@UAEPAXI@Z)

// from server: 100% by king_originala
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