// from server: 51% by atomic.potato
struct CRobloxControlColorSelector
{
    int m_value;
    void value(int value);
};

void CRobloxControlColorSelector::value(int value)
{
    if (!value)
        m_value = -1;
}
