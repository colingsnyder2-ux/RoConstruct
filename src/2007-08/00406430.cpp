// from server: 75% by Intel
struct IUnknown
{
    virtual void __stdcall AddRef() = 0;
};

extern "C" int __stdcall sub_4055f0(int* a1, int a2);

int __stdcall sub_406430(int a1, int a2, int a3, int* a4)
{
    if (!a4)
    {
        return 0x80004003;
    }

    if (!*reinterpret_cast<int*>(0x880df0))
    {
        sub_4055f0(reinterpret_cast<int*>(0x880de4), a2);
    }

    int v5 = *reinterpret_cast<int*>(0x880df0);
    *a4 = v5;

    if (v5)
    {
        (*reinterpret_cast<IUnknown**>(v5))->AddRef();
    }

    return 0;
}
