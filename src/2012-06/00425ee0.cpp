// from server: 53% by Intel
extern "C" int __stdcall sub_425cf0(int, int, int, int, int);
extern "C" int __stdcall sub_425bc0(int, int, int, int, int);

int __stdcall sub_425ee0(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5)
{
    if (arg4 != 0)
        return 0;

    if (arg0 == 0x465)
    {
        int v = sub_425cf0(0x465, arg1, arg2, (int)&arg4, 1);
        *reinterpret_cast<int*>(arg3) = v;
        if (arg4 != 0)
            return 1;
        return 0;
    }

    if (arg0 == 0x466)
    {
        int v = sub_425bc0(0x466, arg1, arg2, (int)&arg4, 1);
        *reinterpret_cast<int*>(arg3) = v;
        if (arg4 != 0)
            return 1;
        return 0;
    }

    return 0;
}
