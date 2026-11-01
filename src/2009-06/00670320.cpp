// from server: 75% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005e7d30  unit: RBX::Geometry  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005e7d30
//
// 005e7d30  8b442404             mov eax, dword ptr [esp + 4]
// 005e7d34  8b5020               mov edx, dword ptr [eax + 0x20]
// 005e7d37  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005e7d3b  3b5120               cmp edx, dword ptr [ecx + 0x20]
// 005e7d3e  56                   push esi
// 005e7d3f  57                   push edi
// 005e7d40  7d06                 jge 0x5e7d48
// 005e7d42  8bf0                 mov esi, eax
// 005e7d44  8bf9                 mov edi, ecx
// 005e7d46  eb0c                 jmp 0x5e7d54
// 005e7d48  8bf1                 mov esi, ecx
// 005e7d4a  3bc8                 cmp ecx, eax
// 005e7d4c  7504                 jne 0x5e7d52
// 005e7d4e  8bf9                 mov edi, ecx
// 005e7d50  eb02                 jmp 0x5e7d54
// 005e7d52  8bf8                 mov edi, eax
// 005e7d54  8b5620               mov edx, dword ptr [esi + 0x20]
// 005e7d57  33c0                 xor eax, eax
// 005e7d59  85d2                 test edx, edx
// 005e7d5b  7e0f                 jle 0x5e7d6c
// 005e7d5d  8b4e28               mov ecx, dword ptr [esi + 0x28]
// 005e7d60  3939                 cmp dword ptr [ecx], edi
// 005e7d62  740d                 je 0x5e7d71
// 005e7d64  40                   inc eax
// 005e7d65  83c104               add ecx, 4
// 005e7d68  3bc2                 cmp eax, edx
// 005e7d6a  7cf4                 jl 0x5e7d60
// 005e7d6c  5f                   pop edi
// 005e7d6d  33c0                 xor eax, eax
// 005e7d6f  5e                   pop esi
// 005e7d70  c3                   ret 
// 005e7d71  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 005e7d74  8b0481               mov eax, dword ptr [ecx + eax*4]
// 005e7d77  5f                   pop edi
// 005e7d78  5e                   pop esi
// 005e7d79  c3                   ret 

struct S {
    char padding[28];
    int* values;
    int count;
    int reserved;
    S** neighbors;
};

int __cdecl findConnection(S* a, S* b)
{
    S* smaller = a->count < b->count ? a : b;
    S* other = smaller == a ? b : a;

    for (int i = 0; i < smaller->count; ++i) {
        if (smaller->neighbors[i] == other)
            return smaller->values[i];
    }

    return 0;
}
