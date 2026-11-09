// from server: 100% by colin
struct CXTPPropertyGridItemBool {
    char pad0[0x110];
    int m_value;
    void SetValue(int value);
};

extern "C" void __stdcall sub_00697a10(int value);

void CXTPPropertyGridItemBool::SetValue(int value)
{
    m_value = value;
    int t = (value == 0) ? 5 : 0;
    sub_00697a10(t);
}
