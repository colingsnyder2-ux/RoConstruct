// from server: 50% by colin
struct CRenderSettings;

struct GetSetImpl {
    void* ptr;
    GetSetImpl(int a, int b);
};

extern "C" void* __cdecl operator_new(unsigned int size);

GetSetImpl::GetSetImpl(int a, int b)
{
    ptr = 0;
    void* p = operator_new(0x14);
    if (p) {
        *(int*)((char*)p + 4) = 1;
        *(int*)((char*)p + 8) = 1;
        *(void**)p = (void*)0x79ae08;
        *(int*)((char*)p + 0xc) = a;
        ptr = p;
    }
}
