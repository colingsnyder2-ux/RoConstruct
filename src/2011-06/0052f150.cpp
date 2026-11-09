// from server: 100% by atomic.potato
extern "C" void __cdecl Function_0080A304(int);

struct ProfiledRakPeer
{
    int value;
    unsigned char padding[4];
    unsigned int count;
    void f();
};

void ProfiledRakPeer::f()
{
    if (count > 0)
        Function_0080A304(value);
}
