// from server: 70% by atomic.potato
extern "C" void target_750da0(void*);

struct S
{
    int f();
    void* field_84;
};

extern "C" unsigned char global_00e31abe;

int S::f()
{
    if (global_00e31abe)
        return 0;

    void* value = *reinterpret_cast<void**>(
        reinterpret_cast<unsigned char*>(this) + 0x84);
    void* base = *static_cast<void**>(value);
    target_750da0(static_cast<char*>(base) + 0x84 +
                  reinterpret_cast<unsigned long>(this));
    return 0;
}
