// from server: 100% by colin
// roc 2007-08 00401c30  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00401c30

void __cdecl sub_401C30(unsigned short* dst, unsigned int count, const unsigned short* src);

void __cdecl sub_401C30(unsigned short* dst, unsigned int count, const unsigned short* src)
{
    if (count != 0) {
        unsigned int limit = count - 1;
        unsigned int i = 0;
        if (limit > 0) {
            do {
                unsigned short c = *src;
                if (c == 0)
                    break;
                *dst = c;
                dst++;
                if (*src == 0x27) {
                    i++;
                    if (i < limit) {
                        *dst = 0x27;
                        dst++;
                    }
                }
                i++;
                src++;
            } while (i < limit);
        }
        *dst = 0;
    }
}
