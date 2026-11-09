// from server: 51% by atomic.potato
extern "C" void construct_string(void *, const char *);

struct S
{
    int f(const char *);
};

int S::f(const char *value)
{
    char buffer[28];
    construct_string(buffer, "SelectionDown");
    *(void **)this = (void *)0x9cfe60;
    return (int)this;
}
