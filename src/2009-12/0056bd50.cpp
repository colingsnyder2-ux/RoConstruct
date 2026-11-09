// from server: 90% by atomic.potato
extern "C" void __stdcall sub_00569990(int, int, int, int);

struct RakPeer
{
    void f(int, int);
};

void RakPeer::f(int a, int b)
{
    sub_00569990(a, b, 0, 0);
}
