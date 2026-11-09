// from server: 86% by atomic.potato
struct CVideoStream
{
    int Method(int, int);
};

int CVideoStream::Method(int unused, int value)
{
    if (value == 0)
        return (int)0x80004003;

    CVideoStream *object = (CVideoStream *)((char *)this - 0x0c);
    int result = object->Method(unused, value);

    if (result < 0)
        result = 1;

    return result;
}
