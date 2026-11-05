// from server: 71% by atomic.potato
struct MovingAssemblyStage {
    void set(int a, int b);
};

void MovingAssemblyStage::set(int a, int b) {
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 4) = 0;
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 8) = 0;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 12) = a;
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 9) = 3;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 16) = b;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 20) = -1;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 24) = -1;
}
