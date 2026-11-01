// from server: 100% by colin
struct VCBrowserViewExternal_CProxy_IBrowserViewExternalEvents
{
    long __stdcall GetTypeInfoCount(unsigned int* pctinfo);
};

long __stdcall VCBrowserViewExternal_CProxy_IBrowserViewExternalEvents::GetTypeInfoCount(unsigned int* pctinfo)
{
    if (pctinfo == 0)
        return 0x80004003;
    *pctinfo = *(unsigned int*)0x78597c;
    *(unsigned int*)((char*)pctinfo + 4) = *(unsigned int*)0x785980;
    *(unsigned int*)((char*)pctinfo + 8) = *(unsigned int*)0x785984;
    *(unsigned int*)((char*)pctinfo + 12) = *(unsigned int*)0x785988;
    return 0;
}
