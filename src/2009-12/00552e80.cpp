// from server: 47% by atomic.potato
struct S
{
};

void f(S* unused, void* dst, const void* src)
{
    *(int*)dst = *(const int*)src;
    *(unsigned short*)((char*)dst + 4) =
        *(const unsigned short*)((const char*)src + 4);
}
