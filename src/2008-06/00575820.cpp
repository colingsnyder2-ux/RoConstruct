// from server: 100% by colin
struct DataModel {
    char pad0[0x20c];
    void* m_ptr;
    bool f();
};

bool DataModel::f()
{
    return *(int*)((char*)m_ptr + 0x1b4) == 1;
}
