// from server: 100% by atomic.potato
struct PointToPointBreakConnector_0079b240 {
    char pad0[8];
    void* m_first;
    void* m_second;
    void* f(int);
};

void* PointToPointBreakConnector_0079b240::f(int value)
{
    if (value == 0)
        return *(void**)((char*)m_first + 12);

    return *(void**)((char*)m_second + 12);
}
