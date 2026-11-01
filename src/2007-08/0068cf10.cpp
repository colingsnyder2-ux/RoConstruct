// from server: 100% by colin
struct CXTPTabClientWnd
{
    int GetCount();
    int FindTab(int nTab);
    int FindTabIndex(int hWnd);
};

int CXTPTabClientWnd::FindTabIndex(int hWnd)
{
    int i = 0;
    if (this->GetCount() > 0)
    {
        do
        {
            if (this->FindTab(i) == hWnd)
                return i;
            i++;
        } while (i < this->GetCount());
    }
    return -1;
}
