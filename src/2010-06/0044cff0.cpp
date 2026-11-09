// from server: 80% by atomic.potato
struct CRobloxApp {
    char pad[0xa4];
    void sub_00423c80(int, int);
    void func_0044cff0(int, int);
};

void CRobloxApp::func_0044cff0(int a, int b)
{
    (*(CRobloxApp*)((char*)this + 0xa4)).sub_00423c80(a, b);
}
