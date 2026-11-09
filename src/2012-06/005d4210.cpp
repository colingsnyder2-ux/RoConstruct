// from server: 100% by tajop
struct Settings {
    bool check(void*);
};

struct S {
    void* field0;
    void* field1;
    void* field2;
    Settings* settings;
    void* get();
    void* Creator();
};

void* S::Creator()
{
    Settings* p = settings;
    void* q = get();
    if (p->check(q))
        return (char*)this - 0x1c;
    return 0;
}
