// from server: 100% by Xemicl
// from server: 100% by tajop
// roc 2012-06 00623360  unit: RBX::WedgeBuilder  size: 192 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00623360
//
// 00623360  55                   push ebp
// 00623361  8bec                 mov ebp, esp
// 00623363  6aff                 push -1
// 00623365  684040ab00           push 0xab4040
// 0062336a  64a100000000         mov eax, dword ptr fs:[0]
// 00623370  50                   push eax
// 00623371  64892500000000       mov dword ptr fs:[0], esp
// 00623378  83ec08               sub esp, 8
// 0062337b  53                   push ebx
// 0062337c  8b5d08               mov ebx, dword ptr [ebp + 8]
// 0062337f  56                   push esi
// 00623380  8bf1                 mov esi, ecx
// 00623382  8b4b08               mov ecx, dword ptr [ebx + 8]
// 00623385  2b4b04               sub ecx, dword ptr [ebx + 4]
// 00623388  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0062338d  f7e9                 imul ecx
// 0062338f  57                   push edi
// 00623390  d1fa                 sar edx, 1
// 00623392  8bfa                 mov edi, edx
// 00623394  b800000000           mov eax, 0
// 00623399  c1ef1f               shr edi, 0x1f
// 0062339c  03fa                 add edi, edx
// 0062339e  8965f0               mov dword ptr [ebp - 0x10], esp
// 006233a1  8975ec               mov dword ptr [ebp - 0x14], esi
// 006233a4  894604               mov dword ptr [esi + 4], eax
// 006233a7  894608               mov dword ptr [esi + 8], eax
// 006233aa  89460c               mov dword ptr [esi + 0xc], eax
// 006233ad  744b                 je 0x6233fa
// 006233af  81ff55555515         cmp edi, 0x15555555
// 006233b5  7605                 jbe 0x6233bc
// 006233b7  e8c4f30700           call 0x6a2780
// 006233bc  50                   push eax
// 006233bd  57                   push edi
// 006233be  e8bd5ce5ff           call 0x479080
// 006233c3  8d0c7f               lea ecx, [edi + edi*2]
// 006233c6  8d1488               lea edx, [eax + ecx*4]
// 006233c9  89560c               mov dword ptr [esi + 0xc], edx
// 006233cc  c6450800             mov byte ptr [ebp + 8], 0
// 006233d0  8b5508               mov edx, dword ptr [ebp + 8]
// 006233d3  52                   push edx
// 006233d4  8b5508               mov edx, dword ptr [ebp + 8]
// 006233d7  52                   push edx
// 006233d8  56                   push esi
// 006233d9  894604               mov dword ptr [esi + 4], eax
// 006233dc  894608               mov dword ptr [esi + 8], eax
// 006233df  8b4b08               mov ecx, dword ptr [ebx + 8]
// 006233e2  8b5b04               mov ebx, dword ptr [ebx + 4]
// 006233e5  50                   push eax
// 006233e6  51                   push ecx
// 006233e7  53                   push ebx
// 006233e8  c745fc00000000       mov dword ptr [ebp - 4], 0
// 006233ef  e8bc15feff           call 0x6049b0
// 006233f4  83c420               add esp, 0x20
// 006233f7  894608               mov dword ptr [esi + 8], eax
// 006233fa  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 006233fd  5f                   pop edi
// 006233fe  8bc6                 mov eax, esi
// 00623400  5e                   pop esi
// 00623401  64890d00000000       mov dword ptr fs:[0], ecx
// 00623408  5b                   pop ebx
// 00623409  8be5                 mov esp, ebp
// 0062340b  5d                   pop ebp
// 0062340c  c20400               ret 4
// 0062340f  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 00623412  e89913eeff           call 0x5047b0
// 00623417  6a00                 push 0
// 00623419  6a00                 push 0
// 0062341b  e824fd3500           call 0x983144

typedef unsigned int size_t_;

struct Elem { int a, b, c; };
struct Alloc {};
struct Tag {};

Elem* allocateElems(size_t_ count, Elem* hint);
Elem* uninitCopy(Elem* first, Elem* last, Elem* dest, Alloc& al, Tag cat, Tag checked);
__declspec(noreturn) void throwTooLong();

inline Tag ptrCat(Elem*&, Elem*&)
{
    Tag cat;
    return cat;
}

inline Elem* uncheckedCopy(Elem* first, Elem* last, Elem* dest, Alloc& al)
{
    return uninitCopy(first, last, dest, al, ptrCat(first, dest), Tag());
}

struct S {
    Alloc al;
    Elem* first;
    Elem* last;
    Elem* end;
    S(const S& other);
    void tidy();
};

S::S(const S& other)
{
    size_t_ count = other.last - other.first;
    first = 0;
    last = 0;
    end = 0;
    if (count != 0) {
        if (count > 0x15555555)
            throwTooLong();
        first = allocateElems(count, (Elem*)0);
        last = first;
        end = first + count;
        try {
            last = uncheckedCopy(other.first, other.last, first, al);
        } catch (...) {
            tidy();
            throw;
        }
    }
}
