// from server: 84% by atomic.potato
extern "C" void __stdcall EnterCriticalSection(void *);
extern "C" void __stdcall LeaveCriticalSection(void *);

struct S
{
    S *next;
    S *create();
    S *f(int);
};

S *S::f(int flag)
{
    S *self = this;
    if (flag & 1)
    {
        S *node = create();
        EnterCriticalSection(node);
        self->next = node->next;
        node->next = self;
        LeaveCriticalSection(node);
    }
    return self;
}
