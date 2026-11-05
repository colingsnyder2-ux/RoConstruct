// from server: 68% by atomic.potato
extern "C" int* __cdecl sub_0053f380();

struct S
{
    int __cdecl f(int* value);
};

int S::f(int* value)
{
    int* source = sub_0053f380();
    value[0] = source[0];
    value[1] = source[1];
    value[2] = source[2];
    value[3] = source[3];
    return 0;
}
