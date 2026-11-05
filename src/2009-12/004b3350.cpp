// from server: 53% by atomic.potato
extern "C" void __stdcall _invalid_parameter_noinfo();

struct Inner {
    char pad0[0xc];
    unsigned int field_c;
    unsigned int field_10;
};

struct Outer {
    Inner* ptr;
    unsigned int count;
};

struct Adapter {
    Outer* field_0;
    unsigned int field_4;
    Adapter* advance(unsigned int n);
};

Adapter* Adapter::advance(unsigned int n) {
    void (__stdcall *fn)() = _invalid_parameter_noinfo;
    Outer* o = this->field_0;
    Inner* inner;
    if (o == 0) {
        fn();
        o = this->field_0;
        if (o == 0) {
            inner = 0;
        } else {
            inner = o->ptr;
        }
    } else {
        inner = o->ptr;
    }
    unsigned int off = n * 0x24;
    unsigned int pos = this->field_4 + off;
    if (pos > inner->field_10 || pos < inner->field_c) {
        fn();
    }
    this->field_4 += off;
    return this;
}
