// from server: 100% by atomic.potato
extern "C" int __cdecl sub_4e64a0(int);

struct RefPropDescriptor
{
};

void __cdecl f(int value, int* result)
{
    *result += sub_4e64a0(value);
}
