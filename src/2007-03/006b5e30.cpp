// from server: 100% by tester
struct CXTPReportHyperlink {
    int GetSomething();
};

int CXTPReportHyperlink::GetSomething()
{
    typedef int (CXTPReportHyperlink::*PMF)();
    PMF p = *(PMF*)(*(int*)this + 0x7c);
    return (this->*p)();
}
