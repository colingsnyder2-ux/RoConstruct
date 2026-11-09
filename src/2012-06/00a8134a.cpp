// from server: 17% by atomic.potato
extern "C" int __cdecl cpuid_feature_edx_bit23();

struct seg_00a80000
{
    int f();
};

int seg_00a80000::f()
{
    return cpuid_feature_edx_bit23();
}
