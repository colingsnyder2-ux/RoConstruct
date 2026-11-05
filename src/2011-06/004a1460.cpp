// from server: 78% by atomic.potato
struct CVideoStream
{
    int status;
    int pad[5];
    void *stream;

    int status_code();
};

int CVideoStream::status_code()
{
    if (stream == 0)
        return 0x80040209;

    struct VTable
    {
        void *pad[14];
        int (__thiscall *release)(void *);
    };

    return ((VTable *)(*(void **)stream))->release(stream);
}
