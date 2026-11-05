// from server: 100% by atomic.potato
extern int g_00E02154;
extern int f_00975470(int);
extern int f_009756F0(int);

int f_00975750(int value)
{
    if (g_00E02154 <= 1)
        f_00975470(value);
    else
        f_009756F0(value);
    return value;
}
