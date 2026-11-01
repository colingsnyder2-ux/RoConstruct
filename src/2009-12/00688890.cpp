// from server: 85% by atomic.potato
extern "C" int __cdecl sbumpc(void *);

struct S
{
    void *stream;
    unsigned char state;
    S();
};

S::S()
{
    if (stream != 0 && sbumpc(stream) != -1)
    {
        state = 0;
        return;
    }
    stream = 0;
    state = 1;
}
