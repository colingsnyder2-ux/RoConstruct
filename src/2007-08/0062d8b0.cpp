// from server: 100% by colin
struct Flying {
    char pad[0x28];
    float field28;
    Flying* construct(int);
};

extern float g_79f738;
extern float g_7c2b70;

extern "C" void __stdcall sub_626620(int, float, float);

Flying* Flying::construct(int a)
{
    float x = g_79f738;
    float y = g_7c2b70;
    sub_626620(a, y, x);
    this->field28 = 0.0f;
    *(int*)this = 0x7c4d04;
    *(int*)((char*)this + 8) = 0x7c4cfc;
    return this;
}
