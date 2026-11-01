// from server: 100% by colin
struct CXTPCustomizeCommandsPage
{
    void m();
};

void CXTPCustomizeCommandsPage::m()
{
    if (--*(int*)((char*)this + 0x15c) == 0)
    {
        if (*(unsigned char*)((char*)this + 0xe4) & 2)
        {
            (*(void (__thiscall**)(void*, int, int))(*(int*)this + 0x19c))(this, 0, 1);
        }
    }
}
