// from server: 78% by Intel
extern "C" void __stdcall G1_func_00414500();

struct CRenderSettings_W4ShadowMode_EnumDesc
{
    void setValue(int value);
};

void CRenderSettings_W4ShadowMode_EnumDesc::setValue(int value)
{
    if (value != *(int*)((char*)this + 0x8C))
    {
        *(int*)((char*)this + 0x8C) = value;
        *(int*)(reinterpret_cast<char*>(this) + 0x144) = 0;
        G1_func_00414500();
    }
}
