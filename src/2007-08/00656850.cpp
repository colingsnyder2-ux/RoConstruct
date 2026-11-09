// from server: 100% by colin
struct CXTPReportControl {
    char pad[0xd0];
    void* field_d0;
    int IsSomething();
};

extern "C" int __fastcall sub_6647D0(void* p);

int CXTPReportControl::IsSomething()
{
    void* p = field_d0;
    if (p != 0)
    {
        if (sub_6647D0(p) > 0)
            return 1;
    }
    return 0;
}
