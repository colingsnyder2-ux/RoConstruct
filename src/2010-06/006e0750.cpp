// from server: 42% by atomic.potato
struct P8GuiTextMixin_GetSetImpl {
    char pad0[8];
    void* field8;
    char padC[4];
    void* fieldC;
    void invoke(void* a, void* b);
};

void P8GuiTextMixin_GetSetImpl::invoke(void* a, void* b) {
    char* p = (char*)a;
    if (p != 0) {
        p = p - 0x1c;
    } else {
        p = 0;
    }
    float* src = (float*)b;
    float v0 = src[0];
    float v1 = src[1];
    float v2 = src[2];
    float tmp[3];
    tmp[0] = v0;
    tmp[1] = v1;
    tmp[2] = v2;
    void* target = (char*)fieldC + (int)p;
    void (*fn)(void*, float*) = (void (*)(void*, float*))field8;
    fn(target, tmp);
}
