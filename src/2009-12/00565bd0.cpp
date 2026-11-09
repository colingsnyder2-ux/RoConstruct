// from server: 55% by atomic.potato
struct RakPeer
{
    void f(const char *);
};

void RakPeer::f(const char *value)
{
    if (value != 0 && value[0] != 0)
    {
        RakPeer *p = (RakPeer *)((char *)this + 0xa40);
        p->f(value);
    }
}
