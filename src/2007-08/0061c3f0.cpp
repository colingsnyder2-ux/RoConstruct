// from server: 100% by colin
struct RBX_ImageButton_Statics {
    static float* getDefaults();
};

float* RBX_ImageButton_Statics::getDefaults()
{
    static unsigned int initialized = 0;
    static float values[3];

    if ((initialized & 1) == 0) {
        initialized |= 1;
        values[0] = 1.0f;
        values[1] = *(float*)0x7c429c;
        values[2] = *(float*)0x7ab980;
    }

    return values;
}
