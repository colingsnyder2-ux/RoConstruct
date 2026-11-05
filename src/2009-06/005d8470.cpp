// from server: 100% by why2
struct RBX_Team {
    int getField90(int* out);
};

int RBX_Team::getField90(int* out) {
    *out = *(int*)((char*)this + 0x90);
    return (int)out;
}
