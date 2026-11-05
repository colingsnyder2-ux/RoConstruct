// from server: 100% by atomic.potato
struct S
{
};

void __cdecl f(unsigned char *p, unsigned int n)
{
    unsigned int i = 0;
    unsigned int half = n >> 1;

    if (half != 0)
    {
        do
        {
            unsigned char t = p[i];
            p[i] = p[n - i - 1];
            p[n - i - 1] = t;
            ++i;
        }
        while (i < half);
    }
}
