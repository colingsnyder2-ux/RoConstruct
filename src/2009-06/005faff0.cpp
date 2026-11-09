// from server: 100% by why2
struct RBX_DataModel {
    char pad[0x214];
    void* field_214;
    double get() const;
};

double RBX_DataModel::get() const {
    char* p = (char*)field_214;
    return *(double*)(p + 0xa0);
}
