// from server: 100% by atomic.potato
extern "C" int __stdcall sub_00847e90(int, int);

int __stdcall func_00849010(int value)
{
    return sub_00847e90(value, 16) & 16;
}
