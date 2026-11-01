// from server: 100% by coldek
// from server: 100% by king_originala
// roc 2008-06 00652270  unit: RBX::ScoreHud  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00652270
//
// 00652270  55                   push ebp
// 00652271  8bec                 mov ebp, esp
// 00652273  6aff                 push -1
// 00652275  6841b87d00           push 0x7db841
// 0065227a  64a100000000         mov eax, dword ptr fs:[0]
// 00652280  50                   push eax
// 00652281  64892500000000       mov dword ptr fs:[0], esp
// 00652288  83ec0c               sub esp, 0xc
// 0065228b  53                   push ebx
// 0065228c  56                   push esi
// 0065228d  57                   push edi
// 0065228e  8965f0               mov dword ptr [ebp - 0x10], esp
// 00652291  6a4c                 push 0x4c
// 00652293  e888e60400           call 0x6a0920
// 00652298  8bf0                 mov esi, eax
// 0065229a  83c404               add esp, 4
// 0065229d  8975ec               mov dword ptr [ebp - 0x14], esi
// 006522a0  c745fc00000000       mov dword ptr [ebp - 4], 0
// 006522a7  8975e8               mov dword ptr [ebp - 0x18], esi
// 006522aa  c645fc01             mov byte ptr [ebp - 4], 1
// 006522ae  85f6                 test esi, esi
// 006522b0  7427                 je 0x6522d9
// 006522b2  8b4508               mov eax, dword ptr [ebp + 8]
// 006522b5  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 006522b8  8b5510               mov edx, dword ptr [ebp + 0x10]
// 006522bb  8906                 mov dword ptr [esi], eax
// 006522bd  8b4514               mov eax, dword ptr [ebp + 0x14]
// 006522c0  894e04               mov dword ptr [esi + 4], ecx
// 006522c3  50                   push eax
// 006522c4  8d4e0c               lea ecx, [esi + 0xc]
// 006522c7  895608               mov dword ptr [esi + 8], edx
// 006522ca  e801f5ffff           call 0x6517d0
// 006522cf  8a4d18               mov cl, byte ptr [ebp + 0x18]
// 006522d2  884e48               mov byte ptr [esi + 0x48], cl
// 006522d5  c6464900             mov byte ptr [esi + 0x49], 0
// 006522d9  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 006522dc  5f                   pop edi
// 006522dd  8bc6                 mov eax, esi
// 006522df  5e                   pop esi
// 006522e0  64890d00000000       mov dword ptr fs:[0], ecx
// 006522e7  5b                   pop ebx
// 006522e8  8be5                 mov esp, ebp
// 006522ea  5d                   pop ebp
// 006522eb  c21400               ret 0x14

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

inline void* __cdecl operator new(unsigned int, void* p)
{
    return p;
}

inline void __cdecl operator delete(void*, void*)
{
}

struct Value {
    char data[60];
    Value(const void*);
};

struct Entry {
    int first;
    int second;
    int third;
    Value value;
    bool enabled;
    bool marked;

    Entry(int, int, int, const void*, bool);
};

inline Entry::Entry(int a, int b, int c, const void* p, bool flag)
    : first(a), second(b), third(c), value(p), enabled(flag), marked(false)
{
}

Entry* __stdcall createEntry(int a, int b, int c, const void* p, bool flag)
{
    void* storage = operator new(sizeof(Entry));
    try {
        new (storage) Entry(a, b, c, p, flag);
    }
    catch (...) {
        operator delete(storage);
        throw;
    }
    return static_cast<Entry*>(storage);
}
