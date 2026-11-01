// from server: 100% by coldek
// from server: 100% by colin
// roc 2008-06 0040fe50  unit: UIEnumConnections::V?$CComEnum::?$CComObject  size: 147 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0040fe50
//
// 0040fe50  55                   push ebp
// 0040fe51  8bec                 mov ebp, esp
// 0040fe53  6aff                 push -1
// 0040fe55  6820d57b00           push 0x7bd520
// 0040fe5a  64a100000000         mov eax, dword ptr fs:[0]
// 0040fe60  50                   push eax
// 0040fe61  64892500000000       mov dword ptr fs:[0], esp
// 0040fe68  83ec10               sub esp, 0x10
// 0040fe6b  8b4508               mov eax, dword ptr [ebp + 8]
// 0040fe6e  53                   push ebx
// 0040fe6f  56                   push esi
// 0040fe70  57                   push edi
// 0040fe71  33ff                 xor edi, edi
// 0040fe73  8965f0               mov dword ptr [ebp - 0x10], esp
// 0040fe76  3bc7                 cmp eax, edi
// 0040fe78  7518                 jne 0x40fe92
// 0040fe7a  b803400080           mov eax, 0x80004003
// 0040fe7f  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0040fe82  64890d00000000       mov dword ptr fs:[0], ecx
// 0040fe89  5f                   pop edi
// 0040fe8a  5e                   pop esi
// 0040fe8b  5b                   pop ebx
// 0040fe8c  8be5                 mov esp, ebp
// 0040fe8e  5d                   pop ebp
// 0040fe8f  c20400               ret 4
// 0040fe92  bb0e000780           mov ebx, 0x8007000e
// 0040fe97  6a1c                 push 0x1c
// 0040fe99  8938                 mov dword ptr [eax], edi
// 0040fe9b  895dec               mov dword ptr [ebp - 0x14], ebx
// 0040fe9e  897de8               mov dword ptr [ebp - 0x18], edi
// 0040fea1  897dfc               mov dword ptr [ebp - 4], edi
// 0040fea4  e8770a2900           call 0x6a0920
// 0040fea9  8bf0                 mov esi, eax
// 0040feab  83c404               add esp, 4
// 0040feae  3bf7                 cmp esi, edi
// 0040feb0  742d                 je 0x40fedf
// 0040feb2  897e04               mov dword ptr [esi + 4], edi
// 0040feb5  897e10               mov dword ptr [esi + 0x10], edi
// 0040feb8  897e0c               mov dword ptr [esi + 0xc], edi
// 0040febb  897e08               mov dword ptr [esi + 8], edi
// 0040febe  897e14               mov dword ptr [esi + 0x14], edi
// 0040fec1  897e18               mov dword ptr [esi + 0x18], edi
// 0040fec4  c70690d78000         mov dword ptr [esi], 0x80d790
// 0040feca  8b0d68c29600         mov ecx, dword ptr [0x96c268]
// 0040fed0  8b01                 mov eax, dword ptr [ecx]
// 0040fed2  8b5004               mov edx, dword ptr [eax + 4]
// 0040fed5  ffd2                 call edx
// 0040fed7  3bf7                 cmp esi, edi
// 0040fed9  741c                 je 0x40fef7
// 0040fedb  33db                 xor ebx, ebx
// 0040fedd  eb18                 jmp 0x40fef7
// 0040fedf  33f6                 xor esi, esi
// 0040fee1  ebf4                 jmp 0x40fed7

extern void* __cdecl operator new(unsigned int);
extern void* objectTable[];

struct Module;
struct ModuleTable {
    void (__thiscall* first)(Module*);
    void (__thiscall* lock)(Module*);
};
struct Module {
    ModuleTable* table;
};
extern Module* module;

struct Exception {
    long status;
    Exception(const Exception&);
    ~Exception();
    void Delete();
};

struct Object {
    void** table;
    long references;
    void* begin;
    void* end;
    void* current;
    void* owner;
    unsigned int flags;

    Object() throw();
    static long __stdcall Create(Object** result);
};

__forceinline Object::Object() throw()
{
    references = 0;
    current = 0;
    end = 0;
    begin = 0;
    owner = 0;
    flags = 0;
    table = objectTable;
    module->table->lock(module);
}

long __stdcall Object::Create(Object** result)
{
    if (!result)
        return (long)0x80004003;

    *result = 0;
    long status = (long)0x8007000e;
    Object* object = 0;

try {
        object = new Object;
    }
    catch (Exception* exception) {
        exception->Delete();
    }
    if (object)
        status = 0;

    *result = object;
    return status;
}
