// from server: 77% by atomic.potato
struct Camera {
    char pad0[0x144];
    int field144;
    char pad1[0x150 - 0x148];
    void* field150;
    void set(int);
};

extern "C" void __stdcall sub_6db5e0(void*, int);
extern "C" void __stdcall sub_40c080(void*, const char*);

void Camera::set(int value) {
    if (field144 != value) {
        void* p = field150;
        field144 = value;
        if (p) {
            sub_6db5e0(p, value);
        }
        sub_40c080(this, (const char*)0xb93318);
    }
}
