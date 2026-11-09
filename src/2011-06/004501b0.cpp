// from server: 100% by atomic.potato
struct CDataModelPropGrid
{
    void f();
    void sub1(int);
    void sub2();
    void sub3();
};

void CDataModelPropGrid::f()
{
    sub1(0);
    sub2();
    sub3();
}
