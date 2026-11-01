// from server: 100% by tester
struct RBX_ImageButton {
    static float* getColors();
};

float* RBX_ImageButton::getColors()
{
    static int initialized = 0;
    static float colors[3];
    if (!(initialized & 1))
    {
        initialized |= 1;
        colors[0] = *(float*)0x7c4280;
        colors[1] = *(float*)0x7c427c;
        colors[2] = *(float*)0x7c4278;
    }
    return colors;
}
