// from server: 100% by atomic.potato
extern "C" int __stdcall sub_832480(int, int);

struct CRobloxTreeCtrl
{
    int f(int);
};

int CRobloxTreeCtrl::f(int value)
{
    return sub_832480(value, 16) & 16;
}
