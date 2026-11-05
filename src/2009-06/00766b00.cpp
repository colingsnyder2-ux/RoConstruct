// from server: 100% by tester
struct CXTPCustomizeCommandsPage
{
    void m();
};

void CXTPCustomizeCommandsPage::m()
{
    if (--*(int*)((char*)this + 0x160) == 0)
    {
        if (*(unsigned char*)((char*)this + 0xe8) & 2)
        {
            (*(void (__thiscall**)(void*, int, int))(*(int*)this + 0x1ac))(this, 0, 1);
        }
    }
}
