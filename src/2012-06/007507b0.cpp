// from server: 77% by tester
struct CXTSplitterWnd {
    static float* GetSomething();
};

float* CXTSplitterWnd::GetSomething() {
    static int initialized = 0;
    static float values[3];
    if (!(initialized & 1)) {
        initialized |= 1;
        values[0] = *(float*)0xb4c440;
        values[1] = *(float*)0xb5abe8;
        values[2] = *(float*)0xb4c440;
    }
    return values;
}
