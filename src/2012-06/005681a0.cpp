// from server: 70% by tester
struct GuidData {
    unsigned char bytes[2];
};

struct GuidItem {
    unsigned int bits;
    int pad1;
    int pad2;
    unsigned char* buffer;
    void append(const GuidData& data);
};

extern void __stdcall sub_00567970(int);
extern bool __stdcall sub_00567e60();

void GuidItem::append(const GuidData& data)
{
    sub_00567970(0x10);
    bool flag = sub_00567e60();
    unsigned int idx = bits >> 3;
    unsigned char* dst = buffer + idx;
    if (flag) {
        dst[0] = data.bytes[1];
        dst[1] = data.bytes[0];
    } else {
        dst[0] = data.bytes[0];
        dst[1] = data.bytes[1];
    }
    bits += 0x10;
}
