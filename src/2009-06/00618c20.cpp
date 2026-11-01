// from server: 100% by EspClaude
// from server: 92% by EspClaude
// roc 2009-06 00618c20  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 257 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00618c20
//
// 00618c20  51                   push ecx
// 00618c21  57                   push edi
// 00618c22  8bf9                 mov edi, ecx
// 00618c24  80bfc100000000       cmp byte ptr [edi + 0xc1], 0
// 00618c2b  7507                 jne 0x618c34
// 00618c2d  32c0                 xor al, al
// 00618c2f  5f                   pop edi
// 00618c30  59                   pop ecx
// 00618c31  c20800               ret 8
// 00618c34  837c241000           cmp dword ptr [esp + 0x10], 0
// 00618c39  53                   push ebx
// 00618c3a  55                   push ebp
// 00618c3b  8bafbc000000         mov ebp, dword ptr [edi + 0xbc]
// 00618c41  56                   push esi
// 00618c42  8bb7b8000000         mov esi, dword ptr [edi + 0xb8]
// 00618c48  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00618c50  7e51                 jle 0x618ca3
// 00618c52  8b87a8000000         mov eax, dword ptr [edi + 0xa8]
// 00618c58  8b18                 mov ebx, dword ptr [eax]
// 00618c5a  8b8794000000         mov eax, dword ptr [edi + 0x94]
// 00618c60  85f6                 test esi, esi
// 00618c62  7404                 je 0x618c68
// 00618c64  3bf0                 cmp esi, eax
// 00618c66  7406                 je 0x618c6e
// 00618c68  ff15ace98900         call dword ptr [0x89e9ac]
// 00618c6e  3beb                 cmp ebp, ebx
// 00618c70  7479                 je 0x618ceb
// 00618c72  85f6                 test esi, esi
// 00618c74  7506                 jne 0x618c7c
// 00618c76  ff15ace98900         call dword ptr [0x89e9ac]
// 00618c7c  8b6d04               mov ebp, dword ptr [ebp + 4]
// 00618c7f  85f6                 test esi, esi
// 00618c81  7404                 je 0x618c87
// 00618c83  8b06                 mov eax, dword ptr [esi]
// 00618c85  eb02                 jmp 0x618c89
// 00618c87  33c0                 xor eax, eax
// 00618c89  3b6814               cmp ebp, dword ptr [eax + 0x14]
// 00618c8c  7506                 jne 0x618c94
// 00618c8e  ff15ace98900         call dword ptr [0x89e9ac]
// 00618c94  8b442410             mov eax, dword ptr [esp + 0x10]
// 00618c98  40                   inc eax
// 00618c99  3b44241c             cmp eax, dword ptr [esp + 0x1c]
// 00618c9d  89442410             mov dword ptr [esp + 0x10], eax
// 00618ca1  7caf                 jl 0x618c52
// 00618ca3  8b9fa8000000         mov ebx, dword ptr [edi + 0xa8]
// 00618ca9  8b8794000000         mov eax, dword ptr [edi + 0x94]
// 00618caf  85f6                 test esi, esi
// 00618cb1  7404                 je 0x618cb7
// 00618cb3  3bf0                 cmp esi, eax
// 00618cb5  7406                 je 0x618cbd
// 00618cb7  ff15ace98900         call dword ptr [0x89e9ac]
// 00618cbd  3beb                 cmp ebp, ebx
// 00618cbf  742a                 je 0x618ceb
// 00618cc1  8b8fa8000000         mov ecx, dword ptr [edi + 0xa8]
// 00618cc7  8b19                 mov ebx, dword ptr [ecx]
// 00618cc9  8bbf94000000         mov edi, dword ptr [edi + 0x94]
// 00618ccf  85f6                 test esi, esi
// 00618cd1  7404                 je 0x618cd7
// 00618cd3  3bf7                 cmp esi, edi
// 00618cd5  740a                 je 0x618ce1
// 00618cd7  8b3dace98900         mov edi, dword ptr [0x89e9ac]
// 00618cdd  ffd7                 call edi
// 00618cdf  eb06                 jmp 0x618ce7
// 00618ce1  8b3dace98900         mov edi, dword ptr [0x89e9ac]
// 00618ce7  3beb                 cmp ebp, ebx
// 00618ce9  750a                 jne 0x618cf5
// 00618ceb  5e                   pop esi
// 00618cec  5d                   pop ebp
// 00618ced  5b                   pop ebx
// 00618cee  32c0                 xor al, al
// 00618cf0  5f                   pop edi
// 00618cf1  59                   pop ecx
// 00618cf2  c20800               ret 8
// 00618cf5  85f6                 test esi, esi
// 00618cf7  7524                 jne 0x618d1d
// 00618cf9  ffd7                 call edi
// 00618cfb  3b6e14               cmp ebp, dword ptr [esi + 0x14]
// 00618cfe  7502                 jne 0x618d02
// 00618d00  ffd7                 call edi
// 00618d02  8b5508               mov edx, dword ptr [ebp + 8]
// 00618d05  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00618d09  83c224               add edx, 0x24
// 00618d0c  52                   push edx
// 00618d0d  ff1564e48900         call dword ptr [0x89e464]
// 00618d13  5e                   pop esi
// 00618d14  5d                   pop ebp
// 00618d15  5b                   pop ebx
// 00618d16  b001                 mov al, 1
// 00618d18  5f                   pop edi
// 00618d19  59                   pop ecx
// 00618d1a  c20800               ret 8
// 00618d1d  8b36                 mov esi, dword ptr [esi]
// 00618d1f  ebda                 jmp 0x618cfb

// from server: 100% by Espeon
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo();

struct String {};
extern String &(__thiscall *string_assign)(String *, const String *);

struct Owner;
struct Proxy {
    Owner *owner;
};

struct Node {
    Node *previous;
    Node *next;
    char *value;
};

struct Owner {
    char padding[0x14];
    Node *head;
};

struct S {
    char padding0[0x94];
    Proxy * volatile owner;
    char padding1[0x10];
    Node *head;
    char padding2[0x0c];
    Proxy *iteratorOwner;
    Node *iteratorNode;
    char padding3;
    bool enabled;

    bool f(String *result, int count);
};

bool S::f(String *result, int count)
{
    if (!enabled)
        return false;

    Node *node = iteratorNode;
    Proxy *proxy = iteratorOwner;

    for (int i = 0; i < count; ++i) {
        Node *limit = head->previous;
        Proxy *expected = owner;
        if (!proxy || proxy != expected)
            _invalid_parameter_noinfo();

        if (node == limit)
            return false;

        if (!proxy)
            _invalid_parameter_noinfo();

        node = node->next;
        Owner *container = proxy ? proxy->owner : 0;
        if (node == container->head)
            _invalid_parameter_noinfo();
    }

    Node *limit = head;
    Proxy *expected = owner;
    if (!proxy || proxy != expected)
        _invalid_parameter_noinfo();

    if (node == limit)
        return false;

    limit = head->previous;
    expected = owner;
    if (!proxy || proxy != expected)
        _invalid_parameter_noinfo();

    if (node == limit)
        return false;

    if (!proxy)
        _invalid_parameter_noinfo();

    Owner *container = proxy ? proxy->owner : 0;
    if (node == container->head)
        _invalid_parameter_noinfo();

    string_assign(result, reinterpret_cast<const String *>(node->value + 0x24));
    return true;
}
