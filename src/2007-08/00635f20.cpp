// from server: 100% by colin
struct CPatchedControlComboBox
{
    void SetPacked(int);
};

void CPatchedControlComboBox::SetPacked(int a)
{
    *(int*)((char*)this + 0x17c) = a;
    if (a != 0)
    {
        if (*(int*)((char*)this + 0x178) == 0)
        {
            int* p = (int*)(*(int*(__thiscall**)(void*))(*(int*)this + 0x160))(this);
            *(int*)((char*)this + 0x178) = (int)p;
            *(int*)((char*)p + 0x5c) = (int)this;
        }
    }
    else
    {
        int* p = (int*)*(int*)((char*)this + 0x178);
        if (p != 0)
        {
            (*(void(__thiscall**)(void*, int))(*(int*)p + 4))(p, 1);
            *(int*)((char*)this + 0x178) = 0;
        }
    }
}
