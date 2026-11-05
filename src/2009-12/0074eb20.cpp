// from server: 33% by atomic.potato
struct VArcHandles_EventDesc
{
    char pad0[4];
    void* field4;
    int method(int, int, int, int, int, int, int, int, int, int);
};

extern "C" void __stdcall sub_5064C0(void*, int);
extern "C" void __stdcall sub_74E770(void*, int, int);

int VArcHandles_EventDesc::method(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
    int local0 = 0;
    int local1 = 0;
    int local2 = 0;
    int local3 = 0;
    int local4 = 0;
    int local5 = 0;
    int local6 = 0;
    int local7 = 0;
    int local8 = 0;
    int local9 = 0;

    local0 = 0;
    if (this->field4)
    {
        sub_5064C0((void*)0x71aad0, 1);
    }

    local1 = 0;
    if (a9)
    {
        local1 = a9;
        (*(void(__stdcall**)(int, int*, int*))a9)(0, &local1, &local1);
    }

    sub_74E770(this, a8, a7);

    local2 = 1;
    if (local1)
    {
        if (*(int*)local1)
        {
            (*(void(__stdcall**)(int, int*, int*))local1)(2, &local3, &local3);
        }
    }

    return a7;
}
