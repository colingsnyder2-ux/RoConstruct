// from server: 100% by colin
struct VCApp_CComObject {
    int Assign(void* p, void* q);
};

int VCApp_CComObject::Assign(void* p, void* q)
{
    char* self;
    if (p != 0)
        self = (char*)p - 0x1c;
    else
        self = 0;

    if (*(void**)(self + 0x20) != q) {
        if (q != 0) {
            void** vt = *(void***)q;
            void (__stdcall *fn)(void*) = (void (__stdcall *)(void*))vt[1];
            fn(q);
        }
        void* old = *(void**)(self + 0x20);
        if (old != 0) {
            void** vt = *(void***)old;
            void (__stdcall *fn)(void*) = (void (__stdcall *)(void*))vt[2];
            fn(old);
        }
        *(void**)(self + 0x20) = q;
    }
    return 0;
}
