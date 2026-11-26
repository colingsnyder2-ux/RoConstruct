// from server: 100% by Xemicl
// from server: 100% by tester
// roc 2012-06 0085cc00  unit: std::D::V?$allocator::V?$basic_gzip_compressor::?$stream_buffer  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0085cc00
//
// 0085cc00  0fb6442404           movzx eax, byte ptr [esp + 4]
// 0085cc05  8b919c000000         mov edx, dword ptr [ecx + 0x9c]
// 0085cc0b  f7d8                 neg eax
// 0085cc0d  1bc0                 sbb eax, eax
// 0085cc0f  83e004               and eax, 4
// 0085cc12  83e2fb               and edx, 0xfffffffb
// 0085cc15  0bc2                 or eax, edx
// 0085cc17  89819c000000         mov dword ptr [ecx + 0x9c], eax
// 0085cc1d  c20400               ret 4

struct S
{
    char padding[0xb0];
    unsigned int value;
    void set(unsigned char enabled);
};

void S::set(unsigned char enabled)
{
    value = (value & ~4u) | ((enabled ? 1u : 0u) ? 4u : 0u);
}
