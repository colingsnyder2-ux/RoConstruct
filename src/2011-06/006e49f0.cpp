// from server: 100% by atomic.potato
struct stream_buffer
{
    void f();
    void reset();
    unsigned char padding[0x58];
    unsigned char active;
};

void stream_buffer::f()
{
    if (active)
    {
        reset();
        active = 0;
    }
}
