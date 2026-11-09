// roc 2012-06 006d8260  unit: boost::io::Vtoo_many_args::U?$error_info_injector::?$clone_impl  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006d8260
//
// 006d8260  8b442404             mov eax, dword ptr [esp + 4]
// 006d8264  56                   push esi
// 006d8265  8b30                 mov esi, dword ptr [eax]
// 006d8267  83ec20               sub esp, 0x20
// 006d826a  8bc4                 mov eax, esp
// 006d826c  c70000000000         mov dword ptr [eax], 0
// 006d8272  8b4e08               mov ecx, dword ptr [esi + 8]
// 006d8275  89642428             mov dword ptr [esp + 0x28], esp
// 006d8279  85c9                 test ecx, ecx
// 006d827b  7416                 je 0x6d8293
// 006d827d  8908                 mov dword ptr [eax], ecx
// 006d827f  8b4e08               mov ecx, dword ptr [esi + 8]
// 006d8282  83c008               add eax, 8
// 006d8285  6a00                 push 0
// 006d8287  50                   push eax
// 006d8288  8b01                 mov eax, dword ptr [ecx]
// 006d828a  8d5610               lea edx, [esi + 0x10]
// 006d828d  52                   push edx
// 006d828e  ffd0                 call eax
// 006d8290  83c40c               add esp, 0xc
// 006d8293  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 006d8297  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 006d829b  8b06                 mov eax, dword ptr [esi]
// 006d829d  51                   push ecx
// 006d829e  52                   push edx
// 006d829f  ffd0                 call eax
// 006d82a1  83c428               add esp, 0x28
// 006d82a4  5e                   pop esi
// 006d82a5  c3                   ret 
// copied from an identical function in another client (function ?reconstruct@@YAXPAPAUObject@@PAX1@Z)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
typedef void (__cdecl *Manager)(const void *, void *, int);

struct Function {
    Manager *manager;
    union Storage {
        double alignment[3];
        char bytes[24];
    } storage;

    Function(const Function &);
    ~Function();
};

inline Function::Function(const Function &other) : manager(0)
{
    if (other.manager) {
        manager = other.manager;
        (*other.manager)(&other.storage, &storage, 0);
    }
}

typedef void (__cdecl *Invoke)(void *, void *, Function);

struct Object {
    Invoke invoke;
    unsigned int padding;
    Function function;
};

void __cdecl reconstruct(Object **object, void *a, void *b)
{
    Object *p = *object;
    p->invoke(a, b, p->function);
}