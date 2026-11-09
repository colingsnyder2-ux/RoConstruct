// from server: 26% by atomic.potato
struct CleanStage {
    int* field_2C;

    void method_0075EC30();
};

extern "C" void __cdecl sub_746780(void*);

void CleanStage::method_0075EC30() {
    int* eax = this->field_2C;
    int* esi = *(int**)(eax + 0x34);
    if (esi) {
        if (*(char*)(esi + 8) == 0) {
            float xmm1 = *(float*)(esi + 0x80);
            *(float*)(esi + 0x84) = 0.0f;
            *(float*)(esi + 0x88) = xmm1;
            *(float*)(esi + 0x8C) = 0.0f;
            *(float*)(esi + 0x90) = 0.0f;
            *(float*)(esi + 0x94) = 0.0f;
            *(float*)(esi + 0x98) = 0.0f;
        } else {
            sub_746780(esi);
        }
    }
}
