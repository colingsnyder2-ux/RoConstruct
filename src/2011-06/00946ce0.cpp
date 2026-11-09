// from server: 40% by atomic.potato
struct S_func_00946ce0
{
    struct VTable
    {
        void (*reserved[6])();
    };

    VTable *field_80;
    void get();
};

void S_func_00946ce0::get()
{
    field_80->reserved[3]();
}
