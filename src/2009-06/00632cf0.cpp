// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005a8330  unit: RBX::Log  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005a8330
//
// 005a8330  56                   push esi
// 005a8331  57                   push edi
// 005a8332  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005a8336  85ff                 test edi, edi
// 005a8338  7404                 je 0x5a833e
// 005a833a  8b0f                 mov ecx, dword ptr [edi]
// 005a833c  eb02                 jmp 0x5a8340
// 005a833e  33c9                 xor ecx, ecx
// 005a8340  8b742410             mov esi, dword ptr [esp + 0x10]
// 005a8344  85f6                 test esi, esi
// 005a8346  7404                 je 0x5a834c
// 005a8348  8b06                 mov eax, dword ptr [esi]
// 005a834a  eb02                 jmp 0x5a834e
// 005a834c  33c0                 xor eax, eax
// 005a834e  50                   push eax
// 005a834f  51                   push ecx
// 005a8350  e84b77e7ff           call 0x41faa0
// 005a8355  83c408               add esp, 8
// 005a8358  83f8ff               cmp eax, -1
// 005a835b  7440                 je 0x5a839d
// 005a835d  85c0                 test eax, eax
// 005a835f  740d                 je 0x5a836e
// 005a8361  33c9                 xor ecx, ecx
// 005a8363  83f801               cmp eax, 1
// 005a8366  0f94c1               sete cl
// 005a8369  5f                   pop edi
// 005a836a  5e                   pop esi
// 005a836b  8bc1                 mov eax, ecx
// 005a836d  c3                   ret 
// 005a836e  85ff                 test edi, edi
// 005a8370  7405                 je 0x5a8377
// 005a8372  8b4f04               mov ecx, dword ptr [edi + 4]
// 005a8375  eb02                 jmp 0x5a8379
// 005a8377  33c9                 xor ecx, ecx
// 005a8379  85f6                 test esi, esi
// 005a837b  7405                 je 0x5a8382
// 005a837d  8b4604               mov eax, dword ptr [esi + 4]
// 005a8380  eb02                 jmp 0x5a8384
// 005a8382  33c0                 xor eax, eax
// 005a8384  3bc8                 cmp ecx, eax
// 005a8386  7e08                 jle 0x5a8390
// 005a8388  5f                   pop edi
// 005a8389  b801000000           mov eax, 1
// 005a838e  5e                   pop esi
// 005a838f  c3                   ret 
// 005a8390  33d2                 xor edx, edx
// 005a8392  3bc8                 cmp ecx, eax
// 005a8394  0f9dc2               setge dl
// 005a8397  5f                   pop edi
// 005a8398  5e                   pop esi
// 005a8399  4a                   dec edx
// 005a839a  8bc2                 mov eax, edx
// 005a839c  c3                   ret 
// 005a839d  5f                   pop edi
// 005a839e  83c8ff               or eax, 0xffffffff
// 005a83a1  5e                   pop esi
// 005a83a2  c3                   ret 

struct S
{
    int first;
    int second;
};

extern "C" int __cdecl compare(int, int);

int __cdecl f(const S* a, const S* b)
{
    int x = a ? a->first : 0;
    int y = b ? b->first : 0;

    switch (compare(x, y))
    {
    case -1:
        return -1;

    case 0:
        x = a ? a->second : 0;
        y = b ? b->second : 0;
        if (x > y)
            return 1;
        return x < y ? -1 : 0;

    case 1:
        return 1;

    default:
        return 0;
    }
}
