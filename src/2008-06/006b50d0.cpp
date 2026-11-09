// from server: 100% by atomic.potato
struct CXTPCommandBar {
    char pad[0x20];
    void* m_pData;
    int IsVisible();
};

extern "C" int __stdcall sub_7bbf98();

int CXTPCommandBar::IsVisible()
{
    if (m_pData != 0)
    {
        if ((sub_7bbf98() & 0x402000) != 0)
            return 1;
    }
    return 0;
}
