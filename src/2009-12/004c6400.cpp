// from server: 78% by atomic.potato
extern "C" void __stdcall std_istream_read(void *, char *, int);

struct S
{
    char pad[0x24];
    void *stream;
    char *read(char *, int);
};

char *S::read(char *buffer, int count)
{
    std_istream_read(stream, buffer, count);
    return *(char **)((char *)stream + 4);
}
