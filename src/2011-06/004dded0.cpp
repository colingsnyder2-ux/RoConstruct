// from server: 65% by atomic.potato
struct W4PacketReliability_EnumDesc_Helper {
    char pad[0x68];
    int* begin;
    int* end;
};

extern "C" int* __stdcall sub_4dd210(int* p);

struct W4PacketReliability_EnumDesc {
    int get(int index);
};

int W4PacketReliability_EnumDesc::get(int index) {
    int* p = sub_4dd210(&index);
    int v = *p;
    if (v < 0)
        return 0;
    W4PacketReliability_EnumDesc_Helper* self = (W4PacketReliability_EnumDesc_Helper*)this;
    int count = (int)(self->end - self->begin);
    if ((unsigned int)v >= (unsigned int)count)
        return 0;
    return self->begin[v];
}
