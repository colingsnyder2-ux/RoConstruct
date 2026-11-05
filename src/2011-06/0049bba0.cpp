// from server: 100% by Yeetserama
// roc 2011-06 0049bba0  unit: CWebToolbox  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0049bba0
//
// 0049bba0  6aff                 push -1
// 0049bba2  6808109d00           push 0x9d1008
// 0049bba7  64a100000000         mov eax, dword ptr fs:[0]
// 0049bbad  50                   push eax
// 0049bbae  64892500000000       mov dword ptr fs:[0], esp
// 0049bbb5  51                   push ecx
// 0049bbb6  56                   push esi
// 0049bbb7  8bf1                 mov esi, ecx
// 0049bbb9  89742404             mov dword ptr [esp + 4], esi
// 0049bbbd  c7069c5ea700         mov dword ptr [esi], 0xa75e9c
// 0049bbc3  8b86fc000000         mov eax, dword ptr [esi + 0xfc]
// 0049bbc9  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0049bbd1  85c0                 test eax, eax
// 0049bbd3  7408                 je 0x49bbdd
// 0049bbd5  8b08                 mov ecx, dword ptr [eax]
// 0049bbd7  8b5108               mov edx, dword ptr [ecx + 8]
// 0049bbda  50                   push eax
// 0049bbdb  ffd2                 call edx
// 0049bbdd  8bce                 mov ecx, esi
// 0049bbdf  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0049bbe7  e87462ffff           call 0x491e60
// 0049bbec  f644241801           test byte ptr [esp + 0x18], 1
// 0049bbf1  7409                 je 0x49bbfc
// 0049bbf3  56                   push esi
// 0049bbf4  e85fe43600           call 0x80a058
// 0049bbf9  83c404               add esp, 4
// 0049bbfc  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0049bc00  8bc6                 mov eax, esi
// 0049bc02  5e                   pop esi
// 0049bc03  64890d00000000       mov dword ptr fs:[0], ecx
// 0049bc0a  83c410               add esp, 0x10
// 0049bc0d  c20400               ret 4
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