// from server: 71% by atomic.potato
struct S {
    char pad0[4];
    void* field4;
    char* field8;
    void* field10;
    char* field14;
    void set(char* arg1, char* arg2);
};

extern "C" void __fastcall sub_411F60(char* p);

void S::set(char* arg1, char* arg2) {
    char* p = arg1 ? arg1 - 0x1c : 0;
    char* dst = field8 + (int)p;
    char c = *arg2;
    if (*dst != c) {
        *dst = c;
        void (*fn)(void*, char*) = (void (*)(void*, char*))field10;
        if (fn) {
            fn(field4, field14 + (int)p);
        }
        sub_411F60((char*)field4);
    }
}
