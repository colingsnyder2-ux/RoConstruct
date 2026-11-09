// from server: 62% by Intel
struct VAnimationTrackState {
    char _pad[0x2c];
    int field_2c;

    void __stdcall sub_8FBB70(int a1, float a2, float a3, float a4, float a5);
};

extern "C" void __stdcall sub_8FB570(float, float, float, float);
extern "C" void __stdcall sub_8F86D0(float, float, float, float, int);

void __stdcall VAnimationTrackState::sub_8FBB70(int a1, float a2, float a3, float a4, float a5) {
    float v1 = a5;
    int v2 = a1;
    float v3 = a4;
    float v4 = a3;
    float v5 = a2;
    sub_8FB570(v5, v4, v3, v1);
    int v6 = v2 ? v2 + 0x1c : 0;
    float v7 = a5;
    float v8 = a4;
    float v9 = a3;
    float v10 = a2;
    sub_8F86D0(v10, v9, v8, v7, v6);
}
