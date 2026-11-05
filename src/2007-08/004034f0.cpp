// from server: 39% by colin
struct CRegObject {
    void Cleanup();
    int field0;
    int field4;
    int field8;
    int fieldC;
    unsigned char field14;
};

void CRegObject::Cleanup()
{
    if (field14 & 2)
    {
        int* p = (int*)field8;
        int* end = (int*)fieldC;
        while (p != end)
        {
            int obj = *p;
            if (obj != 0)
            {
                void** vtbl = *(void***)obj;
                void (*fn)(int) = (void (*)(int))vtbl[2];
                fn(obj);
            }
            p += 2;
        }
        extern void __cdecl operator_delete(void*);
        operator_delete((void*)field8);
    }
    int obj2 = field4;
    if (obj2 != 0)
    {
        void** vtbl = *(void***)obj2;
        void (*fn)(int) = (void (*)(int))vtbl[2];
        fn(obj2);
    }
}
