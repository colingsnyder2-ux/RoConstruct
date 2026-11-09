// from server: 21% by atomic.potato
extern "C" void * __stdcall G1_import_00B23688(const char *);

struct S
{
    void *f(const char *);
};

void *S::f(const char *name)
{
    void *value = G1_import_00B23688(name);
    return value;
}
