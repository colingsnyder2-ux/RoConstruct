// from server: 100% by tester
struct CRobloxControlColorSelector
{
    char pad[0x174];
    int field_0x168;
    void setValue(int* value);
};

extern "C" void __stdcall sub_0063C050(int* value);

void CRobloxControlColorSelector::setValue(int* value)
{
    if (value == 0)
    {
        field_0x168 = -1;
    }
    sub_0063C050(value);
}
