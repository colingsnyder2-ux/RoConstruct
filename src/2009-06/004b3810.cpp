// from server: 100% by tester
struct RBX_Team {
    int getField90(int* out);
};

int RBX_Team::getField90(int* out) {
    *out = *(int*)((char*)this + 0x94);
    return (int)out;
}