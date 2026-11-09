// from server: 39% by atomic.potato
struct ServerReplicator
{
    unsigned int value0;
    unsigned int value4;
    unsigned int value8;
    void __stdcall f();
};

void __stdcall ServerReplicator::f()
{
    typedef void (__thiscall *Function)(unsigned int, unsigned int);
    Function function = *(Function *)(*(unsigned int *)this);
    function(value4, (unsigned int)&value8);
}
