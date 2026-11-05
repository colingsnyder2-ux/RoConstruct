// from server: 100% by tajop
struct Deleter { void* fn; };

struct Pad { int pad[8]; };
struct EnableShared { int weak[2]; };
struct Product : Pad, EnableShared { };

struct shared_count {
    int* pi;
    shared_count(Product* p, Deleter d);
    ~shared_count();
};

void sp_enable_shared_from_this(const shared_count& pn, const EnableShared* pe, const Product* px);

struct shared_ptr_product {
    Product* px;
    shared_count pn;
    shared_ptr_product(Product* p, Deleter d);
};

shared_ptr_product::shared_ptr_product(Product* p, Deleter d)
    : px(p), pn(p, d)
{
    sp_enable_shared_from_this(pn, p, p);
}
