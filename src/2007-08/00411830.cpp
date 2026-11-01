// from server: 100% by colin
struct type_info {
    bool operator==(const type_info&) const;
};

struct bad_any_cast {
    bool matches() const;
};

struct holder {
    void* vtable;
    void* pad;
    type_info* info;
};

extern type_info type_info_882860;

bool (type_info::*type_info_eq)(const type_info&) const;

bool bad_any_cast::matches() const {
    const holder* h = *reinterpret_cast<const holder* const*>(this);
    return (type_info_882860.*type_info_eq)(*h->info);
}
