// from server: 64% by Intel
struct bad_lexical_cast {
    void* field_0;
    void* field_4;
    void* field_8;
    void* field_C;
    void* field_10;
    void* field_14;
    void* field_18;
    void* field_1C;
    void* field_20;
    void* field_24;
    void* field_28;
    void* field_2C;
    void* field_30;
    
    bad_lexical_cast();
};

extern "C" void __cdecl __security_init_cookie(void);

bad_lexical_cast::bad_lexical_cast() {
    int cookie = *reinterpret_cast<int*>(0x8B5188);
    int* esp_value = &cookie + 2;
    cookie ^= reinterpret_cast<int>(esp_value);
    
    struct SEHFrame {
        SEHFrame* next;
        void* handler;
        int cookie;
        bad_lexical_cast* this_ptr;
    };
    
    SEHFrame frame;
    frame.next = *reinterpret_cast<SEHFrame**>(0);
    frame.handler = reinterpret_cast<void*>(0x74DD1E);
    frame.cookie = cookie;
    frame.this_ptr = this;
    
    *reinterpret_cast<SEHFrame**>(0) = &frame;
    
    field_0 = 0;
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
    
    *reinterpret_cast<SEHFrame**>(0) = frame.next;
}
