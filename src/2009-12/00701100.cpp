// from server: 37% by atomic.potato
struct S
{
    void __cdecl f(S *p);
};

void S::f(S *p)
{
    if (p != 0)
    {
        struct V
        {
            void (**v)();
        };

        V *q = (V *)((char *)p + 0x20);
        void (**fn)() = q->v;
        fn[1]();
    }
    else
    {
        struct V
        {
            void (**v)();
        };

        V *q = (V *)0;
        void (**fn)() = q->v;
        fn[1]();
    }
}
