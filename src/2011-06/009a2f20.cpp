// from server: 60% by atomic.potato
struct S
{
};

void __cdecl f(unsigned short* begin, unsigned short* end, unsigned short* out)
{
    if (begin != end)
    {
        do
        {
            if (out != 0)
                *out = *begin;
            begin += 1;
            out += 1;
        }
        while (begin != end);
    }
}
