// from server: 100% by colin
struct VCXTPReportRecords_CXTPHeapObjectT {
    void f(void* p);
};

void VCXTPReportRecords_CXTPHeapObjectT::f(void* p)
{
    void** v = *(void***)p;
    ((void (__thiscall*)(void*))v[0x98 / 4])(p);
    void** w = *(void***)this;
    ((void (__thiscall*)(void*, void*))w[0x60 / 4])(this, p);
}
