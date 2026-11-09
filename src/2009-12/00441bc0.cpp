// from server: 49% by atomic.potato
struct CDataModelPropGrid
{
    void f();
};

extern "C" void func_004416c0(CDataModelPropGrid*, int);
extern "C" void func_00433d50(CDataModelPropGrid*);
extern "C" void func_007f431c(CDataModelPropGrid*);

void CDataModelPropGrid::f()
{
    func_004416c0(this, 0);
    func_00433d50(this);
    func_007f431c(this);
}
