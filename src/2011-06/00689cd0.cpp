// from server: 39% by atomic.potato
struct S
{
    static void f(void* begin, void* end, void* dest);
};

void S::f(void* begin, void* end, void* dest)
{
    char* source = (char*)begin;
    char* limit = (char*)end;
    char* output = (char*)dest;

    while (source != limit)
    {
        if (output != 0)
        {
            int i;
            for (i = 0; i != 32; i += 4)
                *(int*)(output + i) = *(int*)(source + i);
        }
        source += 32;
        output += 32;
    }
}
