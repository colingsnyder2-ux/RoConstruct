// from server: 100% by colin
namespace ns_ROCX000000 {
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
}
