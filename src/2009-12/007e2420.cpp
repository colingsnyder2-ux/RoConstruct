// from server: 100% by atomic.potato
typedef void (__thiscall *StringDestructor)(void *);

extern StringDestructor g_string_destructor;

void __stdcall destroy_string(void *p)
{
    if (p)
    {
        g_string_destructor(p);
        delete static_cast<char *>(p);
    }
}
