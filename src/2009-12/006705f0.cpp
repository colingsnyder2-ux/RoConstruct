// from server: 95% by atomic.potato
struct DataModel
{
    int f();
};

extern "C" DataModel* __stdcall GetDataModel(DataModel*);

int DataModel::f()
{
    DataModel* p = GetDataModel((DataModel*)((char*)this - 0x108));
    if (!p)
        return 0;
    int* q = *(int**)((char*)p + 0x154);
    return (q[4] - q[3]) >> 3;
}
