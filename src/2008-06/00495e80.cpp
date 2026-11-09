// from server: 100% by tester





extern "C" int __cdecl sub_4898d0(int);
extern "C" bool __cdecl sub_4a40d0(int, int);

int sub_495e80(int a, int b)
{
    if (sub_4898d0(a))
    {
        if (!sub_4a40d0(a, b))
            return 1;
    }
    return 0;
}
