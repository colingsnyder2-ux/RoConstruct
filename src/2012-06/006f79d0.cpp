// from server: 69% by atomic.potato
typedef unsigned int DWORD;

struct Native
{
    void construct_string(void*, const char*);
    void sub_006f7810(void*, void*);
};

struct ClearStarterpack
{
    ClearStarterpack* f(const char*);
};

ClearStarterpack* ClearStarterpack::f(const char* value)
{
    char local[28];
    ((Native*)0)->construct_string(local, value);
    ((Native*)0)->sub_006f7810(this, local);
    *(DWORD*)this = 0x00b9c6a0;
    return this;
}
