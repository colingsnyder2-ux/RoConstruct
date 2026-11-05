// from server: 100% by Intel
struct VRegistry {
    void add_ref(int value);
};

void VRegistry::add_ref(int value) {
    *(int*)((char*)this + 8) += value;
}
