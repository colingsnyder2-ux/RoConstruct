// from server: 63% by atomic.potato
struct P8GuiTextButton_GetImpl {
    char pad[8];
    int (__stdcall *fn)(void*, int);
    int offset;
    void GetImpl(float* out, int arg);
};

void P8GuiTextButton_GetImpl::GetImpl(float* out, int arg) {
    int adjusted;
    if (arg != 0) {
        adjusted = arg - 0x1c;
    } else {
        adjusted = 0;
    }
    float temp[2];
    int result = fn((char*)this + offset + adjusted, (int)temp);
    out[0] = temp[0];
    out[1] = temp[1];
}
