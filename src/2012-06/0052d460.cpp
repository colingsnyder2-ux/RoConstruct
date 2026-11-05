// from server: 90% by atomic.potato
struct EventDesc
{
    int value;
    int name;
    EventDesc* f(void* arg);
};

extern "C" int G1_func_006c11a0();
extern "C" void G1_func_0052d3b0(int*, void*);

EventDesc* EventDesc::f(void* arg)
{
    value = G1_func_006c11a0();
    G1_func_0052d3b0(&name, arg);
    return this;
}
