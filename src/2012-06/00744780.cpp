// from server: 100% by tajop
struct bad_lexical_cast_base {
    virtual void what_fn() const;
    int data[4];
};

struct exception_base {
    virtual void get_diag() const;
    int data[4];
};

struct error_info_injector : bad_lexical_cast_base, exception_base {
    error_info_injector(error_info_injector const& x);
};

struct clone_base {
    virtual void clone() const;
};

struct clone_impl : error_info_injector, clone_base {
    clone_impl(clone_impl const& x);
    virtual void clone() const;
};

clone_impl::clone_impl(clone_impl const& x) : error_info_injector(x), clone_base() {
}
