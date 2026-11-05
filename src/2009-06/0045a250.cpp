// from server: 100% by tester
struct CRobloxWnd {
    char pad[0xf0];
    char flag98;
    int sub_458070(int);
};

extern "C" int __stdcall sub_63023e();

int CRobloxWnd::sub_458070(int arg)
{
    if (flag98 != 0)
    {
        sub_63023e();
    }
    else
    {
        return 1;
    }
}
