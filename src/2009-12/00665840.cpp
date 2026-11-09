// from server: 88% by atomic.potato
extern "C" void __stdcall assign_string(void*, const char*);

struct DataModel {
    void f();
};

void DataModel::f()
{
    assign_string((char*)this + 0xacc, ">Authoring");
}
