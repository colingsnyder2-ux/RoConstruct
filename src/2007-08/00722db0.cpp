// from server: 36% by colin
struct CXTIconHandle {
    unsigned int hash(const char* data, int len) const;
};

unsigned int CXTIconHandle::hash(const char* data, int len) const {
    unsigned int h1 = (unsigned int)(unsigned short)((unsigned int)this & 0xffff);
    unsigned int h2 = (unsigned int)((unsigned int)this >> 16);

    if (len == 1) {
        h1 += (unsigned char)data[0];
        if (h1 >= 0xfff1) h1 -= 0xfff1;
        h2 += h1;
        if (h2 >= 0xfff1) h2 -= 0xfff1;
        return (h2 << 16) | h1;
    }

    if (data == 0) {
        return 1;
    }

    if (len < 0x10) {
        while (len) {
            h1 += (unsigned char)*data;
            data++;
            len--;
            h2 += h1;
        }
        if (h1 >= 0xfff1) h1 -= 0xfff1;
        {
            unsigned int q = (unsigned int)(((unsigned long long)h2 * 0x80078071ULL) >> 32);
            q >>= 15;
            h2 = h2 + (q * 15);
        }
        return (h2 << 16) | h1;
    }

    if (len >= 0x15b0) {
        unsigned int blocks = (unsigned int)(((unsigned long long)len * 0x5e6ea9afULL) >> 32);
        blocks >>= 11;
        while (blocks) {
            len -= 0x15b0;
            int n = 0x15b;
            while (n) {
                h1 += (unsigned char)data[0];
                h2 += h1;
                h1 += (unsigned char)data[1];
                h2 += h1;
                h1 += (unsigned char)data[2];
                h2 += h1;
                h1 += (unsigned char)data[3];
                h2 += h1;
                h1 += (unsigned char)data[4];
                h2 += h1;
                h1 += (unsigned char)data[5];
                h2 += h1;
                h1 += (unsigned char)data[6];
                h2 += h1;
                h1 += (unsigned char)data[7];
                h2 += h1;
                h1 += (unsigned char)data[8];
                h2 += h1;
                h1 += (unsigned char)data[9];
                h2 += h1;
                h1 += (unsigned char)data[10];
                h2 += h1;
                h1 += (unsigned char)data[11];
                h2 += h1;
                h1 += (unsigned char)data[12];
                h2 += h1;
                h1 += (unsigned char)data[13];
                h2 += h1;
                h1 += (unsigned char)data[14];
                h2 += h1;
                h1 += (unsigned char)data[15];
                h2 += h1;
                data += 16;
                n--;
            }
            {
                unsigned int q = (unsigned int)(((unsigned long long)h1 * 0x80078071ULL) >> 32);
                q >>= 15;
                h1 += q * 0xffff000f;
            }
            {
                unsigned int q = (unsigned int)(((unsigned long long)h2 * 0x80078071ULL) >> 32);
                q >>= 15;
                h2 += q * 0xffff000f;
            }
            blocks--;
        }
    }

    if (len == 0) {
        return (h2 << 16) | h1;
    }

    if (len >= 0x10) {
        unsigned int n = len >> 4;
        while (n) {
            h1 += (unsigned char)data[0];
            h2 += h1;
            h1 += (unsigned char)data[1];
            h2 += h1;
            h1 += (unsigned char)data[2];
            h2 += h1;
            h1 += (unsigned char)data[3];
            h2 += h1;
            h1 += (unsigned char)data[4];
            h2 += h1;
            h1 += (unsigned char)data[5];
            h2 += h1;
            h1 += (unsigned char)data[6];
            h2 += h1;
            h1 += (unsigned char)data[7];
            h2 += h1;
            h1 += (unsigned char)data[8];
            h2 += h1;
            h1 += (unsigned char)data[9];
            h2 += h1;
            h1 += (unsigned char)data[10];
            h2 += h1;
            h1 += (unsigned char)data[11];
            h2 += h1;
            h1 += (unsigned char)data[12];
            h2 += h1;
            h1 += (unsigned char)data[13];
            h2 += h1;
            h1 += (unsigned char)data[14];
            h2 += h1;
            h1 += (unsigned char)data[15];
            h2 += h1;
            len -= 16;
            data += 16;
            n--;
        }
    }

    while (len) {
        h1 += (unsigned char)*data;
        data++;
        len--;
        h2 += h1;
    }

    {
        unsigned int q = (unsigned int)(((unsigned long long)h1 * 0x80078071ULL) >> 32);
        q >>= 15;
        h1 += q * 0xffff000f;
    }
    {
        unsigned int q = (unsigned int)(((unsigned long long)h2 * 0x80078071ULL) >> 32);
        q >>= 15;
        h2 += q * 0xffff000f;
    }

    return (h2 << 16) | h1;
}
