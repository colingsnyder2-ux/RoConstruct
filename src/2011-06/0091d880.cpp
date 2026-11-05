// from server: 44% by atomic.potato
struct S_func_0091d880
{
    char pad0[60];
    void* m_p;
    void* f();
};

void* S_func_0091d880::f()
{
    struct Inner
    {
        char pad[28];
        void* m_value;
    };

    return static_cast<Inner*>(m_p)->m_value;
}
