// from server: 100% by colin
struct Inner {
    int method();
};

struct Mid {
    char pad0[0x24];
    Inner* inner;
};

struct CRobloxModule {
    char pad0[0x58];
    Mid* mid;
    int get();
};

int CRobloxModule::get()
{
    Mid* m = this->mid;
    return m->inner->method();
}
