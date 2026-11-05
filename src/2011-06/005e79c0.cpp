// from server: 100% by tester
struct RBX_DataModel {
    char pad[0xad4];
    void* field_214;
    double get() const;
};

double RBX_DataModel::get() const {
    char* p = (char*)field_214;
    return *(double*)(p + 0xa8);
}