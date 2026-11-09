// from server: 50% by atomic.potato
struct EnumDesc {
    void f(const char*);
};

extern "C" const char* get_name(const char*);

void EnumDesc::f(const char* value)
{
    const char* name = get_name(value + 4);
    f(name);
}
