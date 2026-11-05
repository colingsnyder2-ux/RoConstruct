// from server: 58% by Intel
struct BeveledBlockBuilder {
    void func(int a, int b);
};

void BeveledBlockBuilder::func(int a, int b) {
    float* ptr = reinterpret_cast<float*>(a);
    *ptr = 0.0f;
    *reinterpret_cast<int*>(ptr + 1) = 1;
    *reinterpret_cast<int*>(ptr + 2) = 1;
    if (b <= 0) {
        *reinterpret_cast<char*>(ptr + 3) = 0;
    } else {
        *reinterpret_cast<char*>(ptr + 3) = 1;
    }
}
