// from server: 100% by atomic.potato
extern "C" bool __cdecl sub_7be050(int, int);

struct S
{
    int type;
    int pad;
    int first;
    int second;
    int f();
};

int S::f()
{
    if (type == 10 && sub_7be050(first, second))
        return 1;
    return 0;
}
