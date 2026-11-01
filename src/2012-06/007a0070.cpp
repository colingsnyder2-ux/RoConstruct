// from server: 40% by Intel
extern "C" float __stdcall func_006cbf60(float*, float*);

struct ButtonBindingWidget {
    void func_007a0070(float* a1, float* a2, float* a3);
};

void ButtonBindingWidget::func_007a0070(float* a1, float* a2, float* a3)
{
    float v1 = *reinterpret_cast<float*>(0xB6C29C);
    float v2 = v1;
    float v3 = v1;
    float v4 = func_006cbf60(&v2, &v3);
    *a1 = v4;
    *a2 = v4;
    *a3 = v4;
}
