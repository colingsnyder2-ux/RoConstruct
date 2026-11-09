// from server: 46% by atomic.potato
extern "C" void std_string_copy(void*, const void*);

struct S
{
    void* f(const void* value);
};

void* S::f(const void* value)
{
    void* result = (char*)this + 0xb50;
    std_string_copy(result, value);
    return (char*)this;
}
