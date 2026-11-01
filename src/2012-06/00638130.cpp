// from server: 62% by Intel





struct TokenException {
    char m_data[0x50];
    TokenException(const TokenException& other);
};

extern "C" void __stdcall std_string_ctor(void* this_ptr, const void* src);

TokenException::TokenException(const TokenException& other) {
    const char* src = other.m_data;
    char* dst = this->m_data;

    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
    dst[4] = src[4];
    dst[5] = src[5];
    dst[6] = src[6];
    dst[7] = src[7];
    dst[8] = src[8];
    dst[9] = src[9];
    dst[10] = src[10];

    std_string_ctor(dst + 0xC, src + 0xC);

    *(int*)(dst + 0x28) = *(int*)(src + 0x28);
    dst[0x2C] = src[0x2C];
    dst[0x2D] = src[0x2D];
    dst[0x2E] = src[0x2E];
    dst[0x2F] = src[0x2F];

    std_string_ctor(dst + 0x34, src + 0x34);

    *(int*)(dst + 0x30) = 0xB83B58;

    std_string_ctor(dst + 0x4C, src + 0x4C);

    *(int*)(dst + 0x48) = 0xB83B58;
}
