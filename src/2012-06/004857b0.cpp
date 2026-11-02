// from server: 100% by tajop
struct PadBase { char pad[0x20]; };
struct EnableShared { void* weak_px; void* weak_pn; };
struct Product : PadBase, EnableShared { };

typedef void (*Deleter)(Product*);

struct SharedCount {
    void* pi;
    SharedCount(Product* p, Deleter d);
    ~SharedCount();
};

void sp_enable_shared_from_this(const SharedCount* pn, const EnableShared* pe, const Product* px);

struct SharedPtr {
    Product* px;
    SharedCount pn;
    SharedPtr(Product* p, Deleter d);
};

SharedPtr::SharedPtr(Product* p, Deleter d) : px(p), pn(p, d) {
    sp_enable_shared_from_this(&pn, p, p);
}
