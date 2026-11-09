// from server: 100% by why2
struct type_info {
    bool __thiscall operator==(const type_info&) const;
};

extern type_info type_info_0xa010a8;
extern bool (__thiscall *type_info_compare)(const type_info*, const type_info*);

struct FactoryProduct {
    int* field0;
    bool compare();
};

bool FactoryProduct::compare() {
    int* p = field0;
    return type_info_compare(&type_info_0xa010a8, (const type_info*)p[2]);
}
