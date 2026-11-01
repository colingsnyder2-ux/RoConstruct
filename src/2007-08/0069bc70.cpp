// from server: 100% by colin
struct CXTPPropertyGridView;

extern "C" CXTPPropertyGridView* __stdcall sub_69BC20(int);

struct CXTPPropertyGridView
{
    char pad[0x9c];
    int field_0x9c;
    void sub_6983C0();
    void sub_698420();
};

void __stdcall sub_69BC70(int a)
{
    CXTPPropertyGridView* p = sub_69BC20(a);
    if (p != 0)
    {
        if (p->field_0x9c != 0)
        {
            p->sub_6983C0();
        }
        else
        {
            p->sub_698420();
        }
    }
}
