// from server: 91% by atomic.potato
extern "C" long __stdcall InterlockedIncrement(long *);

long g_009efd3c;
long g_0098b20c;

struct CNameItem
{
    long m_vftable;
    char m_pad[4];
    long m_value;
    long m_global;
    CNameItem();
};

CNameItem::CNameItem()
{
    InterlockedIncrement(&g_0098b20c);
    m_vftable = 0x9a2cc4;
    m_pad[1] = 1;
    m_value = 0;
    m_global = g_009efd3c;
}
