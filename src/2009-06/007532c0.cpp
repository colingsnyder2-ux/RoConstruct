// from server: 100% by why2
struct VCXTPReportRows_CXTPHeapObjectT {
    void CallAtOffset0x8c();
};

void VCXTPReportRows_CXTPHeapObjectT::CallAtOffset0x8c() {
    typedef void (__thiscall *Fn)(void*, void*);
    Fn fn = *(Fn*)(*(char**)this + 0x8c);
    fn(this, (void*)0x752e10);
}
