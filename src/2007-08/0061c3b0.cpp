// from server: 100% by colin
// roc 2007-08 0061c3b0  unit: RBX::ImageButton  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0061c3b0

struct RBX_ImageButton_Statics {
    static float* getDefaults();
};

float* RBX_ImageButton_Statics::getDefaults()
{
    static unsigned int initialized = 0;
    static float values[3];
    if (!(initialized & 1)) {
        initialized |= 1;
        values[0] = 1.0f;
        values[1] = *(float*)0x7c4298;
        values[2] = *(float*)0x7ab980;
    }
    return values;
}
