// from server: 100% by EspClaude
// from server: 88% by king_originala
// roc 2008-06 00436ab0  unit: COutputView  size: 141 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00436ab0
//
// 00436ab0  6aff                 push -1
// 00436ab2  6890017c00           push 0x7c0190
// 00436ab7  64a100000000         mov eax, dword ptr fs:[0]
// 00436abd  50                   push eax
// 00436abe  64892500000000       mov dword ptr fs:[0], esp
// 00436ac5  83ec08               sub esp, 8
// 00436ac8  56                   push esi
// 00436ac9  8bf1                 mov esi, ecx
// 00436acb  57                   push edi
// 00436acc  89742408             mov dword ptr [esp + 8], esi
// 00436ad0  8b861c010000         mov eax, dword ptr [esi + 0x11c]
// 00436ad6  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00436ade  85c0                 test eax, eax
// 00436ae0  7408                 je 0x436aea
// 00436ae2  8b08                 mov ecx, dword ptr [eax]
// 00436ae4  8b5108               mov edx, dword ptr [ecx + 8]
// 00436ae7  50                   push eax
// 00436ae8  ffd2                 call edx
// 00436aea  8b8618010000         mov eax, dword ptr [esi + 0x118]
// 00436af0  85c0                 test eax, eax
// 00436af2  7408                 je 0x436afc
// 00436af4  8b08                 mov ecx, dword ptr [eax]
// 00436af6  8b5108               mov edx, dword ptr [ecx + 8]
// 00436af9  50                   push eax
// 00436afa  ffd2                 call edx
// 00436afc  8dbef8000000         lea edi, [esi + 0xf8]
// 00436b02  897c240c             mov dword ptr [esp + 0xc], edi
// 00436b06  8bcf                 mov ecx, edi
// 00436b08  c644241801           mov byte ptr [esp + 0x18], 1
// 00436b0d  e84efcffff           call 0x436760
// 00436b12  8b3f                 mov edi, dword ptr [edi]
// 00436b14  57                   push edi
// 00436b15  e8609b2600           call 0x6a067a
// 00436b1a  83c404               add esp, 4
// 00436b1d  8bce                 mov ecx, esi
// 00436b1f  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 00436b27  e854ef0200           call 0x465a80
// 00436b2c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00436b30  5f                   pop edi
// 00436b31  5e                   pop esi
// 00436b32  64890d00000000       mov dword ptr fs:[0], ecx
// 00436b39  83c414               add esp, 0x14
// 00436b3c  c3                   ret 

void __cdecl operator delete(void*) throw();

struct B_func_00465a80 {
    virtual ~B_func_00465a80();
};

struct S_func_00465a80 : B_func_00465a80 {
    ~S_func_00465a80();
};

struct Interface;

struct InterfaceTable {
    void* slots[2];
    unsigned long (__stdcall *release)(Interface*);
};

struct Interface {
    InterfaceTable* table;
};

struct Ptr {
    Interface* p;
    ~Ptr() throw() { if (p) p->table->release(p); }
};

struct ListStorage {
    void* head;
    char padding[28];
    ~ListStorage() { void* p = head; operator delete(p); }
};

struct List : ListStorage {
    void clear();
    __forceinline ~List() { clear(); }
};

struct __declspec(novtable) COutputView : S_func_00465a80 {
    char padding[244];
    List list;
    Ptr first;
    Ptr second;

    ~COutputView();
};

COutputView::~COutputView()
{
}
