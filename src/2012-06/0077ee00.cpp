// from server: 59% by atomic.potato
struct S
{
    int f(int);
};

extern "C" int __stdcall sub_76bfb0(int*);
extern "C" int __stdcall sub_76a190(S*, int*);

int S::f(int value)
{
    int first;
    int second = sub_76bfb0(&value + 1);
    first = *(int*)second;
    return sub_76a190(this, &first);
}
