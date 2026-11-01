// from server: 100% by king_originala
struct S
{
    void build(void* result, int a, int b, int c, int d);
};

void* __cdecl func_004936b0(void* result, S** object,
                          int a, int b, int c, int d)
{
    (*object)->build(result, a, b, c, d);
    return result;
}
