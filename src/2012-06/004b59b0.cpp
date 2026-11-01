// from server: 95% by Intel
extern "C" void __stdcall CoTaskMemFree(void *pv);

struct VCWorkspace_CComObject
{
    void ReleaseResources();
};

void VCWorkspace_CComObject::ReleaseResources()
{
    if (*reinterpret_cast<int *>(reinterpret_cast<char *>(this) + 0x40) != 0)
    {
        void *ptr = *reinterpret_cast<void **>(reinterpret_cast<char *>(this) + 0x44);
        CoTaskMemFree(ptr);
        *reinterpret_cast<int *>(reinterpret_cast<char *>(this) + 0x40) = 0;
        *reinterpret_cast<void **>(reinterpret_cast<char *>(this) + 0x44) = 0;
    }

    void *obj = *reinterpret_cast<void **>(reinterpret_cast<char *>(this) + 0x3C);
    if (obj != 0)
    {
        void *vtable = *reinterpret_cast<void **>(obj);
        void (__stdcall *release)(void *) = *reinterpret_cast<void (__stdcall **)(void *)>(reinterpret_cast<char *>(vtable) + 8);
        release(obj);
        *reinterpret_cast<void **>(reinterpret_cast<char *>(this) + 0x3C) = 0;
    }
}
