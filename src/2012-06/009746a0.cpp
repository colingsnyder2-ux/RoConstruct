// from server: 91% by atomic.potato
extern "C" int __stdcall f_00a951e0(int, int, int, int);

void f_009746a0(int a1)
{
    int local[4];
    local[0] = 0;
    local[1] = 0;
    local[2] = 0;
    f_00a951e0(a1, 0x100, 0, (int)local);
    *(int*)local[2] = local[0];
}
