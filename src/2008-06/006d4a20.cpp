// from server: 100% by tester
struct CXTPReportColumn {
    int GetWidth();
};

int CXTPReportColumn::GetWidth()
{
    if (*(int*)((char*)this + 0x68) == 0 && *(int*)((char*)this + 0xa8) == 0)
    {
        int n = *(int*)((char*)this + 0xa4);
        return n + this->GetWidth();
    }
    else
    {
        int n = *(int*)((char*)this + 0x8c);
        return n + this->GetWidth();
    }
}
