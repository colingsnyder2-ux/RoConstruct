// from server: 100% by colin
namespace ns_ROCX00000f {
struct CXTPReportHyperlink {
    int GetSomething();
};

int CXTPReportHyperlink::GetSomething()
{
    typedef int (CXTPReportHyperlink::*PMF)();
    PMF p = *(PMF*)(*(int*)this + 0x48);
    return (this->*p)();
}
}
