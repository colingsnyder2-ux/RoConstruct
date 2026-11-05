// from server: 100% by atomic.potato
typedef unsigned long DWORD;

extern "C" DWORD __cdecl get_file_attributes(const char *);

struct S
{
    void f();
};

void S::f()
{
    get_file_attributes((const char *)((char *)this + 0x18c));
}
