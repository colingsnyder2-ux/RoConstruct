// from server: 100% by Intel
int __stdcall f_006f3300();
int * const grid_flag = (int *)0xe52558;

int __stdcall f_006f3300()
{
    return *grid_flag == 1;
}
