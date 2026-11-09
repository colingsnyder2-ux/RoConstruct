// from server: 100% by atomic.potato
struct CSHA1
{
    int a[11];
    int f(int);
};

extern "C" int __cdecl sub_5722d0(int, int, int);

int CSHA1::f(int value)
{
    return sub_5722d0(value, a[10], a[8]);
}
