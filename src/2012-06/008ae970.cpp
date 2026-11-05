// from server: 38% by Intel
struct Flag {
    Flag();
};

Flag::Flag() {
    char* thisPtr = reinterpret_cast<char*>(this);
    thisPtr[0] = 1;
    float zero = 0.0f;
    *reinterpret_cast<float*>(thisPtr + 4) = zero;
    *reinterpret_cast<float*>(thisPtr + 8) = zero;
    *reinterpret_cast<float*>(thisPtr + 12) = zero;
    *reinterpret_cast<int*>(thisPtr + 16) = 0;
    *reinterpret_cast<int*>(thisPtr + 20) = 0;
}
