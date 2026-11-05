// from server: 100% by colin
struct CRobloxReportView
{
    char pad[0x74];
    char base[0x238];
    void* field_2ac;
    void* get();
};

void* CRobloxReportView::get()
{
    void* p = field_2ac;
    if (!p)
        p = base;
    return p;
}
