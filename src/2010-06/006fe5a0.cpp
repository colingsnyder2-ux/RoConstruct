// from server: 71% by atomic.potato
struct EventDesc
{
    int (*callback)(EventDesc *, float, float);
    int offset;
    int count;
};

void func_006fe5a0(EventDesc *p, float a, float b)
{
    p->callback(p, a, b);
}
