// from server: 38% by Intel
struct CVideoStreamFilter
{
    int __stdcall RemoveStream(int streamId);
};

extern "C" void __stdcall ReleaseStream(int streamId);

int __stdcall CVideoStreamFilter::RemoveStream(int streamId)
{
    int count = *(int *)((char *)this + 0x50);
    if (count <= 0)
        return 1;

    int *streams = *(int **)((char *)this + 0x54);
    int index = 0;
    while (index < count)
    {
        if (streams[index] == streamId)
            break;
        ++index;
    }

    if (index == count)
        return 1;

    if (count == 1)
    {
        ReleaseStream(streams[0]);
        *(int *)((char *)this + 0x50) = 0;
        *(int *)((char *)this + 0x54) = 0;
        return 0;
    }

    ++index;
    while (index < count)
    {
        streams[index - 1] = streams[index];
        ++index;
    }

    *(int *)((char *)this + 0x50) = count - 1;
    return 0;
}
