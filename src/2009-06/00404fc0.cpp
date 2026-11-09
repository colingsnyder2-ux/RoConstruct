// from server: 100% by why2
struct CComClassFactory {
    int field0;
    int field4;
    int field8;
    int fieldC;
    void* field10;
    void Release();
};

void CComClassFactory::Release()
{
    void* p = field10;
    if (p != 0)
    {
        void** vtbl = *(void***)p;
        void (__stdcall *fn)(void*) = (void (__stdcall *)(void*))vtbl[2];
        fn(p);
    }
}
