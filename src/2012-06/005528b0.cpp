// from server: 34% by atomic.potato
struct EventDesc;
typedef void (__thiscall *Handler)(void *);

struct EventDesc
{
    int f(void *arg);
};

int EventDesc::f(void *arg)
{
    Handler handler = *(Handler *)((char *)this + 0x2c);
    handler((char *)arg - 0x1c);
    return 0;
}
