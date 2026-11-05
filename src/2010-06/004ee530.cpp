// from server: 66% by atomic.potato
struct S
{
};

extern "C" int *__cdecl sub_004ed830(int *);

void __cdecl f(int *value)
{
    *value = *sub_004ed830(value);
}
