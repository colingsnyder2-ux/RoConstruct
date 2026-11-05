// from server: 36% by colin
struct RBX_VStandardOut_EventData
{
    void dtor();
};

void sub_437850(void*);
void sub_461C80(void*);

void RBX_VStandardOut_EventData::dtor()
{
    int* p;
    p = *(int**)((char*)this + 0x10c);
    if (p)
    {
        (*(void(__thiscall**)(int*))(*(int*)p + 8))(p);
    }
    p = *(int**)((char*)this + 0x108);
    if (p)
    {
        (*(void(__thiscall**)(int*))(*(int*)p + 8))(p);
    }
    sub_437850((char*)this + 0xf4);
    sub_461C80(this);
}
