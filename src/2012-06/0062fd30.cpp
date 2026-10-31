// from server: 44% by Intel
// roc 2012-06 0062fd30  unit: G3D::BinaryInput  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062fd30
//
// 0062fd30  8b542414             mov edx, dword ptr [esp + 0x14]
// 0062fd34  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0062fd38  8b442404             mov eax, dword ptr [esp + 4]
// 0062fd3c  56                   push esi
// 0062fd3d  8d4900               lea ecx, [ecx]
// 0062fd40  3b442410             cmp eax, dword ptr [esp + 0x10]
// 0062fd44  7506                 jne 0x62fd4c
// 0062fd46  3b4c2414             cmp ecx, dword ptr [esp + 0x14]
// 0062fd4a  7437                 je 0x62fd83
// 0062fd4c  be01000000           mov esi, 1
// 0062fd51  d3e6                 shl esi, cl
// 0062fd53  803a00               cmp byte ptr [edx], 0
// 0062fd56  7404                 je 0x62fd5c
// 0062fd58  0930                 or dword ptr [eax], esi
// 0062fd5a  eb04                 jmp 0x62fd60
// 0062fd5c  f7d6                 not esi
// 0062fd5e  2130                 and dword ptr [eax], esi
// 0062fd60  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0062fd64  8b442408             mov eax, dword ptr [esp + 8]
// 0062fd68  83f91f               cmp ecx, 0x1f
// 0062fd6b  7307                 jae 0x62fd74
// 0062fd6d  41                   inc ecx
// 0062fd6e  894c240c             mov dword ptr [esp + 0xc], ecx
// 0062fd72  ebcc                 jmp 0x62fd40
// 0062fd74  33c9                 xor ecx, ecx
// 0062fd79  83c004               add eax, 4
// 0062fd7d  894c240c             mov dword ptr [esp + 0xc], ecx
// 0062fd81  89442408             mov dword ptr [esp + 0x8], eax
// 0062fd85  ebbd                 jmp 0x62fd40
// 0062fd83  5e                   pop esi
// 0062fd84  c3                   ret

struct BinaryInput {
    void __cdecl readBits(void* dest, int bitCount, int bitOffset, unsigned char* src, int srcByteOffset);
};

void BinaryInput::readBits(void* dest, int bitCount, int bitOffset, unsigned char* src, int srcByteOffset) {
    unsigned int* destWords = static_cast<unsigned int*>(dest);
    unsigned int* endDestWords = destWords + bitCount;
    int currentBit = bitOffset;
    unsigned char* srcBytes = src + srcByteOffset;

    while (destWords != endDestWords || currentBit != 0) {
        unsigned int mask = 1u << currentBit;
        if (*srcBytes != 0) {
            *destWords |= mask;
        } else {
            *destWords &= ~mask;
        }

        ++currentBit;
        if (currentBit >= 32) {
            currentBit = 0;
            ++destWords;
        }
    }
}
