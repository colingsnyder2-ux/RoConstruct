// from server: 100% by colin
struct CXTPReportColumn
{
    void func_0065ed10();
};

void CXTPReportColumn::func_0065ed10()
{
    if (*(void**)((char*)this + 0x2c) != 0)
    {
        void* p = *(void**)((char*)this + 0x2c);
        (*(void (__thiscall**)(void*))(*(int*)p + 0x68))(p);
        *(int*)((char*)this + 0x2c) = 0;
    }
}
