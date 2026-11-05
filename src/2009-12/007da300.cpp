// from server: 100% by colin
namespace ns_ROCX000004 {
// from server: 100% by tester
int fn_ROCX000004_009639a0(void *p)
{
    if (!p)
        return 0;
    if (!*(void **)((char *)p + 4))
        return 1;
    return fn_ROCX000004_009639a0(*(void **)((char *)p + 4)) + 1;
}
}
