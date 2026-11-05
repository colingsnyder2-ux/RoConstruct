// from server: 100% by atomic.potato
extern "C" __declspec(dllimport) long __stdcall CoCreateInstance(void*, void*, unsigned long, void*, void**);

struct CRobloxModule {
    char pad[0x28];
    void* m_pUnknown;
    long CreateInstance(void** ppv);
};

long CRobloxModule::CreateInstance(void** ppv)
{
    if (ppv == 0)
        return (long)0x80004003;

    long hr = 0;
    if (m_pUnknown == 0)
    {
        hr = CoCreateInstance((void*)0x7c4e5c, 0, 1, (void*)0x79063c, &m_pUnknown);
        if (hr < 0)
            goto done;
    }

    *ppv = m_pUnknown;
    {
        void* p = m_pUnknown;
        void** vtbl = *(void***)p;
        void (__stdcall *fn)(void*) = (void (__stdcall *)(void*))vtbl[1];
        fn(p);
    }

done:
    return hr;
}
