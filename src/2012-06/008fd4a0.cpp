// from server: 35% by atomic.potato
struct S
{
    static void f(void* begin, void* end, void* destination);
};

void S::f(void* begin, void* end, void* destination)
{
    char* source = (char*)begin;
    char* target = (char*)destination;
    while (source != end)
    {
        if (target != 0)
        {
            int i;
            for (i = 0; i < 36; ++i)
                target[i] = source[i];
            target += 36;
        }
        source += 36;
    }
}
