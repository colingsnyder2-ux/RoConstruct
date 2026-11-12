// from server: 100% by EspClaude
// from server: 58% by colin
// roc 2007-08 004101a0  unit: CopyVerb  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004101a0
//
// 004101a0  55                   push ebp
// 004101a1  56                   push esi
// 004101a2  8b742410             mov esi, dword ptr [esp + 0x10]
// 004101a6  85f6                 test esi, esi
// 004101a8  8be9                 mov ebp, ecx
// 004101aa  7406                 je 0x4101b2
// 004101ac  3b742418             cmp esi, dword ptr [esp + 0x18]
// 004101b0  7406                 je 0x4101b8
// 004101b2  ff15d8e67700         call dword ptr [0x77e6d8]
// 004101b8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004101bc  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004101c0  3bc8                 cmp ecx, eax
// 004101c2  7438                 je 0x4101fc
// 004101c4  53                   push ebx
// 004101c5  57                   push edi
// 004101c6  51                   push ecx
// 004101c7  8b4d08               mov ecx, dword ptr [ebp + 8]
// 004101ca  51                   push ecx
// 004101cb  50                   push eax
// 004101cc  e8eff6ffff           call 0x40f8c0
// 004101d1  8b7d08               mov edi, dword ptr [ebp + 8]
// 004101d4  8bd8                 mov ebx, eax
// 004101d6  83c40c               add esp, 0xc
// 004101d9  3bdf                 cmp ebx, edi
// 004101db  8bf3                 mov esi, ebx
// 004101dd  7410                 je 0x4101ef
// 004101df  90                   nop 
// 004101e0  8bce                 mov ecx, esi
// 004101e2  ff15ace67700         call dword ptr [0x77e6ac]
// 004101e8  83c624               add esi, 0x24
// 004101eb  3bf7                 cmp esi, edi
// 004101ed  75f1                 jne 0x4101e0
// 004101ef  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004101f3  8b742418             mov esi, dword ptr [esp + 0x18]
// 004101f7  5f                   pop edi
// 004101f8  895d08               mov dword ptr [ebp + 8], ebx
// 004101fb  5b                   pop ebx
// 004101fc  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00410200  8930                 mov dword ptr [eax], esi
// 00410202  5e                   pop esi
// 00410203  894804               mov dword ptr [eax + 4], ecx
// 00410206  5d                   pop ebp

extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo();

struct Elem {
    int pad[9];
    __declspec(dllimport) ~Elem();
};

Elem* __cdecl copyElems(Elem* first, Elem* last, Elem* dest);

inline void destroyRange(Elem* q, Elem* e)
{
    for (; q != e; ++q)
        q->~Elem();
}

struct Iter {
    void* cont;
    Elem* ptr;
    bool operator==(const Iter& o) const
    {
        if (cont == 0 || cont != o.cont)
            _invalid_parameter_noinfo();
        return ptr == o.ptr;
    }
    bool operator!=(const Iter& o) const { return !(*this == o); }
};

struct ElemVector {
    void* alval;
    Elem* first;
    Elem* last;
    Iter erase(Iter a, Iter b);
};

Iter ElemVector::erase(Iter a, Iter b)
{
    if (a != b) {
        Elem* p = copyElems(b.ptr, last, a.ptr);
        destroyRange(p, last);
        last = p;
    }
    return a;
}
