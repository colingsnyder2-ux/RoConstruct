// from server: 100% by Xemicl
// from server: 100% by atomic.potato
// roc 2012-06 00689a40  unit: RBX::Camera::W4CameraType::?$EnumDesc  size: 97 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00689a40
//
// 00689a40  53                   push ebx
// 00689a41  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 00689a45  56                   push esi
// 00689a46  57                   push edi
// 00689a47  8bf9                 mov edi, ecx
// 00689a49  8b7704               mov esi, dword ptr [edi + 4]
// 00689a4c  8b4f08               mov ecx, dword ptr [edi + 8]
// 00689a4f  2bce                 sub ecx, esi
// 00689a51  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00689a56  f7e9                 imul ecx
// 00689a58  c1fa04               sar edx, 4
// 00689a5b  8bc2                 mov eax, edx
// 00689a5d  c1e81f               shr eax, 0x1f
// 00689a60  03c2                 add eax, edx
// 00689a62  7504                 jne 0x689a68
// 00689a64  33f6                 xor esi, esi
// 00689a66  eb15                 jmp 0x689a7d
// 00689a68  8bcb                 mov ecx, ebx
// 00689a6a  2bce                 sub ecx, esi
// 00689a6c  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00689a71  f7e9                 imul ecx
// 00689a73  c1fa04               sar edx, 4
// 00689a76  8bf2                 mov esi, edx
// 00689a78  c1ee1f               shr esi, 0x1f
// 00689a7b  03f2                 add esi, edx
// 00689a7d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00689a81  51                   push ecx
// 00689a82  6a01                 push 1
// 00689a84  53                   push ebx
// 00689a85  8bcf                 mov ecx, edi
// 00689a87  e834fcffff           call 0x6896c0
// 00689a8c  8b442410             mov eax, dword ptr [esp + 0x10]
// 00689a90  8d1476               lea edx, [esi + esi*2]
// 00689a93  c1e205               shl edx, 5
// 00689a96  035704               add edx, dword ptr [edi + 4]
// 00689a99  5f                   pop edi
// 00689a9a  5e                   pop esi
// 00689a9b  8910                 mov dword ptr [eax], edx
// 00689a9d  5b                   pop ebx
// 00689a9e  c20c00               ret 0xc

struct Elem {
    char pad[96];
};

struct Container {
    char pad0[4];
    Elem* begin;
    Elem* end;
    int* f(int* out, Elem* pos, int b);
};

struct Caller {
    void sub_6896c0(Elem* pos, int a, int b);
};

int* Container::f(int* out, Elem* pos, int b) {
    Elem* first = begin;
    int count = (int)((char*)end - (char*)first) / 96;
    int idx;
    if (count == 0) {
        idx = 0;
    } else {
        idx = (int)((char*)pos - (char*)first) / 96;
    }
    ((Caller*)this)->sub_6896c0(pos, 1, b);
    *out = (int)(begin + idx);
    return out;
}
