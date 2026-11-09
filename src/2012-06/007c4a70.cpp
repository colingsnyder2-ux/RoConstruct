// from server: 54% by Intel
struct String {
    char _buf[28];
    String() {}
    String(const String&) {}
    ~String() {}
};

extern "C" void __stdcall String_ctor(String* thisptr);
extern "C" void __stdcall String_ctor_copy(String* thisptr, const String& src);
extern "C" void __stdcall String_dtor(String* thisptr);
extern "C" void __stdcall sub_7C4570(void* thisptr, const String* a2, String* a3);
extern "C" void __stdcall sub_B22654(String* thisptr, int zero);
extern "C" void __stdcall sub_B22644(void* thisptr, String* str);
extern "C" void __stdcall sub_B2263C(String* thisptr, int one);

struct PartInstance {
    void* GetSetImpl(String* a1, String* a2);
};

void* PartInstance::GetSetImpl(String* a1, String* a2) {
    struct SEHFrame {
        SEHFrame* next;
        void* handler;
    };
    SEHFrame frame;
    frame.next = *(SEHFrame**)0;
    frame.handler = (void*)0xACB6F2;
    *(SEHFrame**)0 = &frame;

    String local_str;
    int state = 0;
    sub_B22654(&local_str, 0);
    sub_7C4570(this, a1, &local_str);
    state = 1;
    sub_B22644(a2, &local_str);
    state = 0;
    sub_B2263C(&local_str, 1);

    *(SEHFrame**)0 = frame.next;
    return a2;
}
