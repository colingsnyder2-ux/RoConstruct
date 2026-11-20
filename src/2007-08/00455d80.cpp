// from server: 100% by Intel_Inside
// roc 2007-08 00455d80  unit: CRobloxReportView  size: 103 bytes
struct CRobloxReportView
{
    char storage[0x31c];
    CRobloxReportView();
};

CRobloxReportView* createReportView()
{
    return new CRobloxReportView;
}
