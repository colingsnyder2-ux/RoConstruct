// from server: 68% by Intel
struct bad_lexical_cast {
    void* vftable;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    bad_lexical_cast();
};

extern "C" int __security_cookie;

bad_lexical_cast::bad_lexical_cast() {
    int cookie = __security_cookie ^ (int)&cookie;
    void* prev_seh = *(void**)0;
    int* security_cookie_ptr = (int*)0x8b5188;
    int saved_cookie = *security_cookie_ptr ^ (int)&cookie;

    struct Frame { void* prev; void* handler; int cookie; } frame = { prev_seh, (void*)0x74dd1e, saved_cookie };
    *(void**)0 = &frame;

    vftable = 0;
    field_4 = 0;
    field_8 = 0;
    field_C = 0;
    field_10 = 0;
    field_14 = 0;
    field_18 = 0;
    field_1C = 0;
    field_20 = 0;
    field_24 = 0;
    field_28 = 0;
    field_2C = 0;
    field_30 = 0;

    *(void**)0 = frame.prev;
}
