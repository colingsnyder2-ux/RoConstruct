// from server: 48% by atomic.potato
struct VCEvent_sp_counted_impl_p {
    char pad0[0xa8];
    char field_a8[0x10];
    char pad_b8[0x8];
    double field_c0;
    double field_c8;
    char pad_d0[0xc0];
    char field_190[0x10];

    void sub_9756f0(void*);
    void* sub_975560(void*, void*, void*);
    void sub_568d20(double);

    void f();
};

extern "C" {
    extern unsigned char byte_E580B3;
    extern void* ptr_E5809C;
    extern double dbl_B53EF8;
    extern void __stdcall sub_972290(unsigned char, const char*);
}

void VCEvent_sp_counted_impl_p::sub_9756f0(void*) {}

void* VCEvent_sp_counted_impl_p::sub_975560(void*, void*, void*) { return 0; }

void VCEvent_sp_counted_impl_p::sub_568d20(double) {}

void VCEvent_sp_counted_impl_p::f()
{
    char buf[0x30];
    sub_9756f0(buf);
    double z = 0.0;
    *(double*)(buf + 0x28) = z;
    *(double*)(buf + 0x30) = z;
    void* r = sub_975560(this->field_a8, buf + 0x10, buf + 0x1c);
    *(int*)(buf + 0x34) = *(int*)r;
    *(int*)(buf + 0x28) = *(int*)((char*)r + 4);
    *(int*)(buf + 0x2c) = *(int*)((char*)this + 0xb8);
    *(int*)(buf + 0x30) = *(int*)((char*)this + 0xbc);
    void* v = (*(void*(**)(void*, void*))((*(void***)this)[2]))(this, buf + 0x24);
    *(int*)((char*)this + 0xc0) = *(int*)v;
    *(int*)((char*)this + 0xc4) = *(int*)((char*)v + 4);
    *(int*)((char*)this + 0xc8) = *(int*)((char*)v + 8);
    *(int*)((char*)this + 0xcc) = *(int*)((char*)v + 0xc);
    if (byte_E580B3) {
        if (*(double*)((char*)this + 0xc0) <= dbl_B53EF8) {
            if (ptr_E5809C) {
                if (!((unsigned char(__stdcall*)(int, const char*, const char*))ptr_E5809C)(0xb8, "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\Base\\rbx\\TaskScheduler.Job.cpp", "currentError.error < std::numeric_limits<double>::max()")) {
                    sub_972290(byte_E580B3, "currentError.error < std::numeric_limits<double>::max()");
                }
            } else {
                sub_972290(byte_E580B3, "currentError.error < std::numeric_limits<double>::max()");
            }
        }
    }
    if (*(double*)((char*)this + 0xc0) > 0.0) {
        sub_568d20(*(double*)((char*)this + 0xc0));
    }
}
