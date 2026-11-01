// from server: 100% by colin
extern "C" void* (__stdcall *SelectObject)(void*, void*);

struct CXTPBufferDC
{
    void* vtable;
    void* field_4;
    void* field_8;

    CXTPBufferDC* construct(void* a, void* b);
};

CXTPBufferDC* CXTPBufferDC::construct(void* a, void* b)
{
    this->vtable = (void*)0x7ceae0;
    void* p = a;
    if (p != 0)
        p = *(void**)((char*)p + 4);
    this->field_4 = p;
    void* q = b;
    if (q == 0)
    {
        this->field_8 = SelectObject(p, q);
        return this;
    }
    q = *(void**)((char*)q + 4);
    this->field_8 = SelectObject(p, q);
    return this;
}
