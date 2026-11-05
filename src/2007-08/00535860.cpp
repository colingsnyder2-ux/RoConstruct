// from server: 100% by colin
struct type_info {
    bool operator==(const type_info&) const;
};

extern type_info G_type_info_00882d64;
extern bool (type_info::*G_eq_fn)(const type_info&) const;

struct S {
    void* field0;
    void* field4;
    void* field8;
    bool f();
};

bool S::f()
{
    S* p = *(S**)this;
    return (G_type_info_00882d64.*G_eq_fn)(*(type_info*)p->field8);
}
