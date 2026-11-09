// from server: 52% by atomic.potato
extern "C" void __stdcall UpdateMotorValue(void*, unsigned int);

struct Motor6D {
    char pad[0xa8];
    void* field_a8;
    void setValue(float);
};

void Motor6D::setValue(float value) {
    float* field = (float*)((char*)field_a8 + 0xd0);
    if (value != *field) {
        *field = value;
        UpdateMotorValue(this, 0x00e50504);
    }
}
