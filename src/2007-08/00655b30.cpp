// from server: 100% by colin
struct CXTPReportControl {
    char pad[0x200];
    void* field_200;
    void func();
};

void* __fastcall sub_6d2fa0(void*);
void __fastcall sub_6d3120(void*);

void CXTPReportControl::func() {
    void* p = field_200;
    if (p != 0) {
        void* q = *(void**)((char*)p + 0x48);
        if (q != 0) {
            if (sub_6d2fa0(q) == this) {
                sub_6d3120(*(void**)((char*)p + 0x48));
            }
        }
    }
}
