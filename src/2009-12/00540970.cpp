// from server: 64% by atomic.potato
extern "C" int __cdecl sub_004456d0(int);
extern "C" int __cdecl sub_005337e0(int, int, int*);

int sub_00540970(int a, int b, int c, int d)
{
    int value = sub_004456d0(b);
    int first = *(int*)value;
    return sub_005337e0(d, first, &a);
}
