// from server: 97% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00403040  unit: ATL::CRegObject  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00403040
//
// 00403040  51                   push ecx
// 00403041  8b8994000000         mov ecx, dword ptr [ecx + 0x94]
// 00403047  33d2                 xor edx, edx
// 00403049  891424               mov dword ptr [esp], edx
// 0040304c  3bca                 cmp ecx, edx
// 0040304e  7412                 je 0x403062
// 00403050  56                   push esi
// 00403051  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00403055  56                   push esi
// 00403056  e8e5780600           call 0x46a940
// 0040305b  8bc6                 mov eax, esi
// 0040305d  5e                   pop esi
// 0040305e  59                   pop ecx
// 0040305f  c20400               ret 4
// 00403062  8b442408             mov eax, dword ptr [esp + 8]
// 00403066  8910                 mov dword ptr [eax], edx
// 00403068  895004               mov dword ptr [eax + 4], edx
// 0040306b  59                   pop ecx
// 0040306c  c20400               ret 4

struct Result {
    unsigned int first;
    unsigned int second;
};

struct Source {
    void copy(Result* output);
};

struct S {
    unsigned char padding[0x94];
    Source* source;
    Result* f(Result* output);
};

Result* S::f(Result* output)
{
    volatile unsigned int state = 0;
    if (source) {
        source->copy(output);
        return output;
    }
    output->first = 0;
    output->second = 0;
    return output;
}
