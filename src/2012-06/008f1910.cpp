// from server: 30% by Intel
struct KernelJoint
{
    int field_104;
    int field_124;
};

extern "C" int __stdcall GetIndex(void*);

int __cdecl func_008f1910(void* arg1, void* arg2, void* arg3)
{
    int eax = GetIndex(arg1);
    KernelJoint* esi = reinterpret_cast<KernelJoint*>(arg2);
    int ecx = esi->field_104;
    int edx = *reinterpret_cast<int*>(ecx);
    int (*func)(int, int) = reinterpret_cast<int (*)(int, int)>(*(int*)(edx + 0x40));
    int result1 = func(ecx, eax);

    esi = reinterpret_cast<KernelJoint*>(esi->field_124 + result1 * 4);

    ecx = *reinterpret_cast<int*>(arg3);
    edx = *reinterpret_cast<int*>(ecx);
    KernelJoint* edi = reinterpret_cast<KernelJoint*>(arg2);
    ecx = edi->field_104;
    edx = *reinterpret_cast<int*>(ecx);
    func = reinterpret_cast<int (*)(int, int)>(*(int*)(edx + 0x40));
    int result2 = func(ecx, *reinterpret_cast<int*>(arg3));

    if (reinterpret_cast<int>(esi) != 1)
        return 1;

    if (reinterpret_cast<int*>(edi->field_124 + result2 * 4) == reinterpret_cast<int*>(1))
        return 1;

    return 0;
}
