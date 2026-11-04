// from server: 68% by Intel
struct DxUserInput {
    int func(int a1, int a2);
};

extern "C" int __stdcall sub_59C3F0(int a1, int a2);

int DxUserInput::func(int a1, int a2)
{
    if (*(char *)((char *)this + 104))
    {
        sub_59C3F0(a2, a2);
        return a2;
    }
    else
    {
        *(int *)a1 = 0;
        return 0;
    }
}
