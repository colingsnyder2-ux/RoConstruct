// from server: 100% by Intel
struct MovingAssemblyStage {
    int getCount();
};

int MovingAssemblyStage::getCount() {
    return (*reinterpret_cast<int*>(this + 12) - *reinterpret_cast<int*>(this + 8)) >> 2;
}
