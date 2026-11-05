// from server: 100% by atomic.potato
extern "C" void __stdcall SetManualJointToInfinite(int);

void __stdcall SetManualJointToInfinite(int)
{
    *(int*)0x00c8e6e4 = 2;
}
