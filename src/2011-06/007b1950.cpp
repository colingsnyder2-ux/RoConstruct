// from server: 29% by atomic.potato
// roc 2011-06 007b1950  unit: RBX::CleanStage  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007b1950
//
// 007b1950  83790400             cmp dword ptr [ecx + 4], 0
// 007b1954  56                   push esi
// 007b1955  742c                 je 0x7b1983
// 007b1957  8b742408             mov esi, dword ptr [esp + 8]
// 007b195b  85f6                 test esi, esi
// 007b195d  7424                 je 0x7b1983
// 007b195f  8b4904               mov ecx, dword ptr [ecx + 4]
// 007b1962  8b01                 mov eax, dword ptr [ecx]
// 007b1964  8b5004               mov edx, dword ptr [eax + 4]
// 007b1967  57                   push edi
// 007b1968  ffd2                 call edx
// 007b196a  8bf8                 mov edi, eax
// 007b196c  8b06                 mov eax, dword ptr [esi]
// 007b196e  8b5004               mov edx, dword ptr [eax + 4]
// 007b1971  8bce                 mov ecx, esi
// 007b1973  ffd2                 call edx
// 007b1975  3bf8                 cmp edi, eax
// 007b1977  5f                   pop edi
// 007b1978  7c09                 jl 0x7b1983
// 007b197a  b801000000           mov eax, 1
// 007b197f  5e                   pop esi
// 007b1980  c20400               ret 4
// 007b1983  33c0                 xor eax, eax
// 007b1985  5e                   pop esi
// 007b1986  c20400               ret 4





struct CleanStage {
    int field0;
    void* field4;
    int compare(void* other);
};

int CleanStage::compare(void* other) {
    if (field4 == 0)
        return 0;
    if (other == 0)
        return 0;
    void** vtable1 = *(void***)field4;
    int (*get1)(void*) = (int (*)(void*))vtable1[1];
    int a = get1(field4);
    void** vtable2 = *(void***)other;
    int (*get2)(void*) = (int (*)(void*))vtable2[1];
    int b = get2(other);
    if (a < b)
        return 0;
    return 1;
}
