// from server: 60% by atomic.potato
struct CDataModelPropGrid
{
    CDataModelPropGrid* __cdecl f(CDataModelPropGrid*, int);
};

CDataModelPropGrid* CDataModelPropGrid::f(CDataModelPropGrid* p, int)
{
    CDataModelPropGrid* q = this;
    q->f(p, 0);
    return p;
}
