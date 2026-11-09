// from server: 80% by atomic.potato
struct S
{
    int Get(void* value);
    void* field884;
    unsigned int field888;
};

int S::Get(void* value)
{
    unsigned int i;
    unsigned int count;
    char* p;

    count = field888;
    p = (char*)field884;
    for (i = 0; i < count; ++i)
    {
        if (*(void**)(*(char**)p + 4) == value)
            return i;
        p += 8;
    }

    return -1;
}
