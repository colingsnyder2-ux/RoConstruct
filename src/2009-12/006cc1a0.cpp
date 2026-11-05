// from server: 75% by atomic.potato
struct P8PartInstance {
    char pad0[8];
    float (__thiscall *fn)(void *);
    int offsetC;
    int index10;
    char pad14[0x84];
    int field98;
    float GetSetImpl(int, float *);
};

float P8PartInstance::GetSetImpl(int arg, float *out) {
    P8PartInstance *p = (P8PartInstance *)(arg ? arg - 0x1c : 0);
    float *result;
    int idx = this->index10;
    int off = *(int *)((char *)p + 0x98);
    off = *(int *)(off + idx);
    off += this->offsetC;
    float (__thiscall *f)(void *) = this->fn;
    f((char *)p + 0x98 + off);
    out[0] = result[0];
    out[1] = result[1];
    out[2] = result[2];
    return out[0];
}
