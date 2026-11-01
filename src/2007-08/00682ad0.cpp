// from server: 100% by colin
struct CXTPPropertyGrid
{
    char pad[0x14c];
    void* field_14c;
    void SetField(void* p);
};

extern "C" void __fastcall sub_6301e4(void* p);

void CXTPPropertyGrid::SetField(void* p)
{
    if (field_14c != 0)
    {
        sub_6301e4(field_14c);
    }
    field_14c = p;
}
