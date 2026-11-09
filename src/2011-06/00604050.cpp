// from server: 100% by atomic.potato
int g_SetManualJointToWeak = 0;

struct S
{
    void __stdcall SetManualJointToWeak();
};

void __stdcall S::SetManualJointToWeak()
{
    g_SetManualJointToWeak = 0;
}
