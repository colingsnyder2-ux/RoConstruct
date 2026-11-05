// from server: 66% by atomic.potato
typedef unsigned char byte;

extern "C" void __cdecl Target(void*);

struct S
{
    void* value;
    void* get();
};

byte g_flag;
void* g_value;

void* S::get()
{
    if (g_flag)
        return g_value;

    void* p = value;
    Target(static_cast<char*>(p) + 0x84);
    return 0;
}
