// from server: 100% by atomic.potato
struct Profiler
{
    void* pad[34];
    void* m_callback;
    int m_value;
    void f();
};

void Profiler::f()
{
    if (m_callback != 0)
        ((void (__thiscall *)(void*, int*, int))(*(void***)m_callback)[0])(m_callback, (int*)((char*)this + 0x90), m_value);
}
