// from server: 34% by atomic.potato
struct S
{
    void *field0;
    void *field1;
    void *head;
    void f();
};

extern "C" void __cdecl Function(void *);

void S::f()
{
    void *p = head;
    while (p != 0)
    {
        void *next = *((void **)p + 1);
        Function(p);
        p = next;
    }
}
