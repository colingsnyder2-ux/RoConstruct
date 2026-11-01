// from server: 100% by colin
struct MyXTPCommandBars
{
    char pad[0x84];
    int count;

    void* func_00631c90(int);
    void func_006a42c0();
    void* func_00632910(int);
    void func_00651550(int);
    void func_00632c00(int);
};

void MyXTPCommandBars::func_00632c00(int arg)
{
    void* p = func_00631c90(arg);
    ((MyXTPCommandBars*)p)->func_006a42c0();
    int n = count;
    for (int i = 0; i < n; ++i)
    {
        void* q = func_00632910(i);
        ((MyXTPCommandBars*)q)->func_00651550(arg);
    }
}
