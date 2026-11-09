// from server: 82% by atomic.potato
struct CVideoStream
{
    int pad[4];
    int value;
    int get(int *unused, int *out);
};

int CVideoStream::get(int *unused, int *out)
{
    if (out == 0)
        return -2147467259;

    *out = value;
    return 0;
}
