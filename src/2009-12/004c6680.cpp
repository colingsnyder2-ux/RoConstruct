// from server: 68% by atomic.potato
struct S
{
    int unused0;
    int unused1;
    int unused2;
    int unused3;
    int unused4;
    int unused5;
    int unused6;
    int unused7;
    int unused8;
    int unused9;
    int unused10;
    int unused11;
    int unused12;
    int unused13;
    int unused14;
    int unused15;
    int unused16;
    int unused17;
    int unused18;
    int unused19;
    int unused20;
    int unused21;
    int unused22;
    int unused23;
    void *stream;
    char active;
    int f();
};

int S::f()
{
    void **vtable;
    void **object;
    typedef void (*CloseFunction)(void *, int);
    CloseFunction close;

    if (stream && active)
    {
        vtable = *(void ***)stream;
        object = (void **)((char *)vtable + *(int *)((char *)vtable + 4));
        close = (CloseFunction)*(void **)*object;
        close(object, 1);
        stream = 0;
    }
    return 0;
}
