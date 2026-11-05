// from server: 100% by colin
extern "C" double (__cdecl* atof)(const char*);

struct CXTPReportRecordItemNumber
{
    char  gap0[0x80];
    double m_nValue;
    void SetValueDouble(const char* a, const char* b);
};

void CXTPReportRecordItemNumber::SetValueDouble(const char* a, const char* b)
{
    m_nValue = atof(b);
}
