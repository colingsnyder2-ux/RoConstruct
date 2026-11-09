// from server: 100% by atomic.potato
typedef int DWORD;

DWORD g_value;

struct S
{
    void __stdcall SetManualJointToStrong();
};

void __stdcall S::SetManualJointToStrong()
{
    g_value = 1;
}
