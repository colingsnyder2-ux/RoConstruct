// from server: 33% by atomic.potato
struct CRobloxModule
{
    void *f();
};

void *CRobloxModule::f()
{
    struct Inner
    {
        void *value[10];
    };

    Inner *a = (Inner *)((char *)this + 0x58);
    return ((Inner *)((char *)a->value[9] + 0x24))->value[0];
}
