// from server: 100% by colin
struct CXTPReportColumn {
    int GetWidth();
};

int CXTPReportColumn::GetWidth()
{
    if (*(int*)((char*)this + 0x64) == 0 && *(int*)((char*)this + 0xa4) == 0)
    {
        int n = *(int*)((char*)this + 0xa0);
        return n + this->GetWidth();
    }
    else
    {
        int n = *(int*)((char*)this + 0x88);
        return n + this->GetWidth();
    }
}
