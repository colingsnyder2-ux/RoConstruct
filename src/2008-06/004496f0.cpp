// from server: 100% by atomic.potato
struct CRbxPlayDocTemplate
{
    void* pad[36];
    void* field_90;
    void method(void*);
};

extern "C" void __stdcall sub_006A11F6(void*);

void CRbxPlayDocTemplate::method(void* value)
{
    sub_006A11F6(value);
    if (value == field_90)
        field_90 = 0;
}
