// from server: 90% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    *(int *)this = 0x00BAFA8C;
    *((int *)this + 1) = 0x00BAFA80;
    *((int *)this + 6) = 0x00BAFA74;
    *((int *)this + 7) = 0x00BAFA68;
    return 0;
}
