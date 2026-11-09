// from server: 32% by atomic.potato
extern "C" unsigned short* __stdcall func_0090400e(unsigned int* dst, const unsigned short* src, unsigned int count);

unsigned short* __stdcall func_0090400e(unsigned int* dst, const unsigned short* src, unsigned int count)
{
    unsigned int i = 0;
    if (count > 0)
    {
        do
        {
            unsigned short w = src[i];
            unsigned int c = w;
            unsigned int v;
            if ((c & 0xffff7c00) != 0)
            {
                unsigned int hi = c & 0xffff8000;
                unsigned int lo = (c >> 10) & 0x1f;
                unsigned int mid = c & 0x3ff;
                v = ((hi << 3) | mid) << 13;
                v |= (lo + 0x70) << 23;
            }
            else if ((c & 0x3ff) != 0)
            {
                unsigned int m = c & 0x3ff;
                int shift = -0xe;
                while ((0x400 & m) == 0)
                {
                    shift--;
                    m <<= 1;
                }
                unsigned int hi = (c & 0xffff8080) << 3;
                v = (hi | m) & 0xfffffbff;
                v = (v << 13) | ((unsigned int)(shift + 0x7f) << 23);
            }
            else
            {
                v = ((c & 0xffff8000) << 16);
            }
            dst[i] = v;
            i++;
        } while (i < count);
    }
    return (unsigned short*)dst;
}
