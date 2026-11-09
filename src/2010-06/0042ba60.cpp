// from server: 82% by atomic.potato
extern int g_00c00870;

struct CDataModelPropGrid
{
    void f();
};

void CDataModelPropGrid::f()
{
    if (!g_00c00870)
    {
        *((char *)this + 0x109) = 1;
    }
}
