// from server: 59% by colin
struct CSettingsDialog {
    char pad[0x58];
    float f58;
    float f5c;
    float f60;
    float f64;
    short* getSize(short* out);
};

extern "C" short __stdcall FloatToShort(float value);

short* CSettingsDialog::getSize(short* out) {
    out[0] = FloatToShort(f60 - f58);
    out[1] = FloatToShort(f64 - f5c);
    return out;
}
