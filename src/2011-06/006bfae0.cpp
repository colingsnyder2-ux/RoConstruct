// from server: 52% by atomic.potato
struct VInsertService_EventDesc {
    char pad0[4];
    int field4;
    int init(int, int);
};

extern "C" int __stdcall sub_4C1670(int*, int);
extern "C" int __fastcall sub_6BE200(void*, int, int);

int VInsertService_EventDesc::init(int a, int b) {
    sub_4C1670(&field4, 1);
    sub_6BE200(this, a, b);
    return a;
}
