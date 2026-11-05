// from server: 28% by Intel
extern "C" int __stdcall sub_5a2800(int, int, int, int, int, int);
extern "C" int __stdcall WSAGetLastError();
extern "C" void __stdcall sub_b23e38();

struct ClientReplicator {
};

int __cdecl sendPacket(int a1, int a2, int a3, int a4)
{
    int* globalPtr = (int*)0xe25740;
    int vtable = *globalPtr;
    if (vtable)
    {
        int (__stdcall *func)(int, int, int, int) = (int (__stdcall*)(int, int, int, int))*(int*)(vtable + 4);
        func(a4, a3, a2, a1);
        return func(a4, a3, a2, a1) != -1;
    }

    if (a1 == -1)
    {
        int err = WSAGetLastError();
        if (!err)
            return 0;
    }

    if (*(short*)(0) == 0)
    {
        int result = sub_5a2800(a1, a2, a3, a4, 0, 0);
        if (result != -1)
            return 0;
    }

    sub_b23e38();
    return 0;
}
