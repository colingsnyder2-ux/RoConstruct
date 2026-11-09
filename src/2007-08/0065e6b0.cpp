// from server: 100% by colin
struct CXTPReportColumn
{
    char pad[0x54];
    void* field_54;
    int isSomething();
};

struct Helper
{
    int __thiscall getSomething();
};

extern int __fastcall sub_006d3460(void*);

int CXTPReportColumn::isSomething()
{
    void* p = field_54;
    if (p != 0)
    {
        if (sub_006d3460(p) != 0)
        {
            void* q = field_54;
            int r = sub_006d3460(q);
            if (*(int*)(r + 0x38) == (int)this)
                return 1;
        }
    }
    return 0;
}
