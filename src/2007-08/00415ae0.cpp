// from server: 45% by colin
struct VCContent_CComContainedObject {
    void* m_pUnk;
    void* m_pVtbl;
    void Method(void* arg1, void* arg2, void* arg3, void* arg4, void* arg5, void* arg6, void* arg7, void* arg8);
};

extern "C" void* __stdcall sub_77E69C(void*);
extern "C" void __stdcall sub_77E6AC(void*);

void VCContent_CComContainedObject::Method(void* arg1, void* arg2, void* arg3, void* arg4, void* arg5, void* arg6, void* arg7, void* arg8)
{
    char buf[28];
    void* p;
    void* v;
    void* saved;

    sub_77E69C(&p);
    v = *(void**)arg1;
    ((void (__thiscall*)(void*, void*))m_pVtbl)((char*)m_pUnk + (int)v, arg2);
    sub_77E6AC(buf);
}
