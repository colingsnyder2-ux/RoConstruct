// from server: 43% by colin
struct Vector3Item {
    bool Init(const char* name);
};

extern "C" {
    void* __stdcall sub_77DD98();
    void __stdcall sub_77E698(void* dst, void* src);
    void __stdcall sub_77E6AC(void* p);
    bool __cdecl sub_58D190(void* a, void* b);
}

bool Vector3Item::Init(const char* name) {
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
    void* p = sub_77DD98();
    char buf[16];
    sub_77E698(buf, p);
    bool result = sub_58D190(buf, &x);
    sub_77E6AC(buf);
    return result;
}
