// from server: 39% by colin
extern "C" __declspec(dllimport) unsigned long __stdcall TlsAlloc();

extern "C" void* __cdecl sub_62FEF6(unsigned int size);
extern "C" void __cdecl sub_62FC62(void* p);
extern "C" void __cdecl sub_40CC20();
extern "C" void __cdecl sub_725AC0();
extern "C" void __cdecl sub_725720();

extern unsigned char g_8b5188;
extern void* g_8c98f0;

struct thread_resource_error {
    void* field_0;
    void* field_4;
    void* field_8;
    void* field_c;
    void* field_10;
    void* field_14;
    int field_18;
    void* field_1c;
};

void sub_725DE0()
{
    thread_resource_error* p = (thread_resource_error*)sub_62FEF6(0x1c);
    if (p != 0) {
        sub_725AC0();
    }
    sub_40CC20();
    p->field_18 = (int)TlsAlloc();
    if (p->field_18 == -1) {
        if (p->field_c != 0) {
            sub_62FC62(p->field_c);
        }
        p->field_c = 0;
        p->field_10 = 0;
        p->field_14 = 0;
        sub_725720();
        sub_62FC62(p);
    } else {
        g_8c98f0 = p;
    }
}
