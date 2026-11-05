// from server: 75% by colin
extern "C" float __stdcall sqrtf_helper(float);
extern "C" void __stdcall sub_49FD90();
extern "C" void __stdcall sub_4A5EE0();

struct Replicator {
    void sub_49FD90(int, int, float*);
    void sub_4A5EE0(float);
    void func_004a6dc0(float a, float b, float c);
};

void Replicator::func_004a6dc0(float a, float b, float c)
{
    float lenSq = a * a + b * b + c * c;
    float len = sqrtf_helper(lenSq);
    float tmp = len;
    sub_49FD90(0x20, 1, &tmp);
    if (len != 0.0f) {
        sub_4A5EE0(a / len);
        sub_4A5EE0(b / len);
        sub_4A5EE0(c / len);
    }
}
