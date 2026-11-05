// from server: 100% by colin
struct CXTCaptionButtonThemeOfficeXP {
    char pad[0x7c];
    int field7c;
    void setValue(int);
};

void CXTCaptionButtonThemeOfficeXP::setValue(int v)
{
    field7c = v;
    (*(void (__thiscall**)(void*))(*(int*)this + 4))(this);
}
