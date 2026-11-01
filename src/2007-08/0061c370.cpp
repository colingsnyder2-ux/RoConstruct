// from server: 100% by colin
struct RBX_ImageButton {
    static float* getColors();
};

float* RBX_ImageButton::getColors()
{
    static unsigned int initialized = 0;
    static float colors[3];
    if (!(initialized & 1)) {
        initialized |= 1;
        colors[0] = *(float*)0x7b5254;
        colors[1] = *(float*)0x7c4294;
        colors[2] = *(float*)0x7c4290;
    }
    return colors;
}
