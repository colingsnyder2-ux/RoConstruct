// from server: 100% by colin
struct CXTPReportColumn;

struct CXTPReportColumn
{
    char pad[0x54];
    void* field_54;
    int func_0065e730();
};

extern "C" void* __fastcall sub_006d3460(void*);
extern "C" int __fastcall sub_0065ed30(void*);

int CXTPReportColumn::func_0065e730()
{
    void* p = sub_006d3460(field_54);
    int r = sub_0065ed30(p);
    return r == (int)this;
}
