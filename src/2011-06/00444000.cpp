// from server: 27% by atomic.potato
extern "C" int __stdcall External(int);

struct S
{
    int f(int);
};

int S::f(int value)
{
    return External(value);
}
