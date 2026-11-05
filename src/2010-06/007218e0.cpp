// from server: 69% by atomic.potato
struct UniversalTool {
    char pad0[8];
    int* field8;
    char padC[4];
    int* field10;
    int get(int idx);
    int __cdecl set(int idx, int val);
};

int UniversalTool::set(int idx, int val) {
    int* p = (int*)this->get(idx);
    int t = p[2];
    int v;
    if (t == 5) {
        v = *(int*)(*(int*)p + 0xc);
    } else if (t == 7) {
        v = *(int*)(*(int*)p + 8);
    } else {
        v = *(int*)((char*)this->field10 + t * 4 + 0x98);
    }
    if (v == 0)
        return 0;
    int* dst = this->field8;
    *dst = v;
    dst[2] = 5;
    this->field8 = dst + 4;
    return 1;
}
