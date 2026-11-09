// from server: 55% by atomic.potato
struct VideoControl
{
    struct Interface
    {
        virtual bool query();
        virtual void pad1();
        virtual void pad2();
        virtual void pad3();
        virtual void pad4();
        virtual void pad5();
        virtual void pad6();
        virtual void pad7();
        virtual void execute();
    };

    char padding[268];
    Interface *interface_ptr;
    int f();
};

int VideoControl::f()
{
    Interface *p = interface_ptr;
    if (p->query())
        p->execute();
    return 0;
}
