// from server: 100% by atomic.potato
extern "C" void __stdcall SetHandle(int value);

struct Handles
{
    char pad0[404];
    int m_handle;
    void f(int value);
};

void Handles::f(int value)
{
    if (m_handle != value)
    {
        m_handle = value;
        SetHandle(0xcd2f70);
    }
}
