// from server: 100% by colin
struct DataModel {
    void construct();
    DataModel();
};

DataModel::DataModel()
{
    construct();
    *(int*)((char*)this + 0x00) = 0x7a8e9c;
    *(int*)((char*)this + 0x04) = 0x7a8e94;
    *(int*)((char*)this + 0x10) = 0x7a8e8c;
    *(int*)((char*)this + 0x14) = 0x7a8e7c;
    *(int*)((char*)this + 0x2c) = 0x7a8e6c;
    *(int*)((char*)this + 0x44) = 0x7a8e5c;
    *(int*)((char*)this + 0x5c) = 0x7a8e4c;
    *(int*)((char*)this + 0x74) = 0x7a8e3c;
    *(int*)((char*)this + 0x8c) = 0x7a8e2c;
    *(int*)((char*)this + 0xe8) = 0x7a8e1c;
    *(int*)((char*)this + 0x100) = 0x7a8e0c;
    *(int*)((char*)this + 0x118) = 0x7a8dfc;
}
