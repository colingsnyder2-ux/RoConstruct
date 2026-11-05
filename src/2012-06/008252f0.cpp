// from server: 80% by Intel
struct VPlayer {
    int getRefPropDescriptor();
};

int VPlayer::getRefPropDescriptor() {
    int* obj = *reinterpret_cast<int**>(this + 44);
    int* vtable = *reinterpret_cast<int**>(obj);
    int (__thiscall *func)(int*) = reinterpret_cast<int (__thiscall*)(int*)>(vtable[1]);
    return func(obj);
}
