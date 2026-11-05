// from server: 64% by atomic.potato
struct UploadVideoVerb
{
    struct Callback
    {
        virtual int Invoke() = 0;
        virtual int Next() = 0;
    };

    int unused[31];
    Callback *callback;
    int f();
};

int UploadVideoVerb::f()
{
    Callback *p = callback;
    if (p != 0 && p->Next())
        return 1;
    return 0;
}
