// from server: 70% by atomic.potato
struct DataModel
{
};

extern "C" DataModel* getDataModel(DataModel*);

extern "C" int __cdecl report(int, const char*, const char*, int, void*);

struct ServiceProvider
{
    DataModel* model;
    void unused();
};

void ServiceProvider::unused()
{
    DataModel* p = model;
    if (p)
        p = getDataModel(p);
    report(0, ".?AVInstance@RBX@@", ".?AVDataModel@RBX@@", 0, p);
}
