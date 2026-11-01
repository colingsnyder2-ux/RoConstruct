// from server: 100% by tester
struct CXTPReportGroupRow_Batch
{
    int Method(int);
};

int CXTPReportGroupRow_Batch::Method(int arg)
{
    volatile int pad = 0;
    (*(void (__thiscall **)(CXTPReportGroupRow_Batch *, int))(*(int *)this + 0xfc))(this, arg);
    return arg;
}
