// from server: 90% by atomic.potato
struct VCXTPReportRows_CXTPHeapObjectT {
    void RemoveRow(int);
    void AddRow(int);
};

extern "C" void __stdcall sub_82d240(void*, int);

void VCXTPReportRows_CXTPHeapObjectT::AddRow(int idx)
{
    if (idx == 0)
        return;
    sub_82d240((void*)idx, 0);
    int v = ((int (__thiscall*)(void*))((*(void***)idx)[0x6c / 4]))((void*)idx);
    if (v == -1)
        return;
    RemoveRow(v);
}
