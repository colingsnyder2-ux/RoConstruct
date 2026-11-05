// from server: 100% by atomic.potato
extern "C" double __cdecl sub_78a830(int, int);
extern "C" void __cdecl sub_788d60(int, double);

double g_9eaf38;

int sub_79c990(int value)
{
    double x = sub_78a830(value, 1);
    x *= g_9eaf38;
    sub_788d60(value, x);
    return 1;
}
