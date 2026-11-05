// from server: 44% by atomic.potato
struct UploadVideoVerb
{
    struct Handler
    {
        virtual int Invoke();
    };

    char padding[0x64];
    Handler* handler;
    int Check();
};

int UploadVideoVerb::Check()
{
    Handler* h = handler;
    int result = 0;
    if (h != 0 && h->Invoke())
        result = 1;
    return result;
}
