// from server: 100% by atomic.potato
struct CXTPReportRecordItemNumber
{
    double m_dValue;
    int Compare(int a, int b);
};

extern "C" void* __cdecl sub_00662370(int);
extern "C" void* __cdecl sub_00630202(void*);

int CXTPReportRecordItemNumber::Compare(int a, int b)
{
    void* p = sub_00662370(b);
    void* q = sub_00630202(p);
    if (q == 0)
        return 0;
    if (*(double*)((char*)this + 0x80) == *(double*)((char*)q + 0x80))
        return 0;
    if (*(double*)((char*)this + 0x80) > *(double*)((char*)q + 0x80))
        return 1;
    return -1;
}
