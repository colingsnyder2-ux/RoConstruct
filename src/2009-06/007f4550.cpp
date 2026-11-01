// from server: 100% by tester
struct CXTPTabManagerItem {
    int f(int);
};

extern void __stdcall g_006fdbc0(int);

int CXTPTabManagerItem::f(int a)
{
    *(int*)((char*)this + 4) = 0;
    *(int*)this = 0;
    *(int*)((char*)this + 8) = a;
    g_006fdbc0(1);
    return (int)this;
}
