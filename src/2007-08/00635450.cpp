// from server: 100% by colin
struct MyXTPCommandBars
{
    void sub_00635450(int);
};

struct Inner
{
    int *sub_006353a0(int);
};

void MyXTPCommandBars::sub_00635450(int arg)
{
    int result = (*(int (__thiscall **)(void *, int))(*(int *)this + 0x5c))(this, arg);
    if (result != 0)
    {
        Inner *p = (Inner *)(*(int *)((char *)this + 0x74) + 0xa8);
        int *r = p->sub_006353a0(arg);
        *r = 1;
        *(int *)(*(int *)((char *)this + 0x74) + 0x4c) = 1;
    }
}
