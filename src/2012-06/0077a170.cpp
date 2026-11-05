// from server: 100% by tajop
struct Pad { int a[8]; };
struct Esft { int w; };
struct T : Pad, Esft { };
typedef void (*Deleter)(T*);

struct shared_count {
    int* pi;
    shared_count(T* p, Deleter d);
    ~shared_count();
};

void sp_enable_shared_from_this(shared_count const* pn, Esft const* e, T const* p);

struct shared_ptr_T {
    T* px;
    shared_count pn;
    shared_ptr_T(T* p, Deleter d);
};

shared_ptr_T::shared_ptr_T(T* p, Deleter d) : px(p), pn(p, d) {
    sp_enable_shared_from_this(&pn, p, p);
}
