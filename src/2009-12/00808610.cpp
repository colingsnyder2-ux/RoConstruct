// from server: 94% by atomic.potato
extern "C" int __cdecl memcpy_s(void*, unsigned int, const void*, unsigned int);

struct CXTPCommandBar
{
};

void __cdecl f(void* destination, const void* source, unsigned int size)
{
    memcpy_s(destination, size, source, size);
}
