// from server: 100% by tester
namespace ns_ROCX000065 {
extern int __cdecl fn_ROCX000065(int);

int fn_ROCX000065(int* p)
{
    if (p)
    {
        if (fn_ROCX000065(p[1]))
            return 1;
    }
    return 0;
}
}
