// from server: 83% by atomic.potato
struct StringObject
{
    void *vtable;
    unsigned char data[24];
};

struct StringAssigner
{
    StringObject *assign(const StringObject *);
};

void copy_strings(StringObject *first, StringObject *last, StringObject *source)
{
    StringObject *p = first;
    if (p != last)
    {
        do
        {
            ((StringAssigner *)p)->assign(source);
            p = (StringObject *)((char *)p + 0x20);
            p[-1].data[0] = source->data[0];
        }
        while (p != last);
    }
}
