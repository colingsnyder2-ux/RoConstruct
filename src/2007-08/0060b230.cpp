// from server: 100% by colin
struct CXTCaptionButtonTheme {
    char pad[0x28];
    int value;

    int ReleaseValue();
};

int CXTCaptionButtonTheme::ReleaseValue() {
    int old = value;
    value = 0;
    return old;
}
