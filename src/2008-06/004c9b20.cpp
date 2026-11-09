// from server: 100% by colin
struct S
{
    void f(void*, void*);
};

void S::f(void* a, void* b)
{
    void** head = (void**)b;
    void* node;
    if (a)
    {
        node = (char*)a + 0x70;
    }
    else
    {
        node = 0;
    }
    *(void**)node = *head;
    *head = node;
}
