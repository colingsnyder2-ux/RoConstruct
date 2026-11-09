// from server: 15% by atomic.potato
struct GfxAttachement {
    char pad0[0x10];
    int field10;
    char pad14[4];
    char field18[0x20];
    char field38[8];
    char field40[8];

    int init(int a, int b, int c);
};

extern "C" void __stdcall sub_41ae90();
extern "C" char __stdcall sub_4f4a10(int, int, int);

int GfxAttachement::init(int a, int b, int c)
{
    sub_41ae90();
    *(int*)this = 0x9ae384;
    field10 = c;
    *(int*)((char*)this + 0x18) = 0;
    if (sub_4f4a10(a, b, (int)((char*)this + 0x20))) {
        *(int*)((char*)this + 0x18) = 0xb12610;
    } else {
        *(int*)((char*)this + 0x18) = 0;
    }
    *(int*)((char*)this + 0x38) = 0;
    *(int*)((char*)this + 0x3c) = 0;
    *(int*)((char*)this + 0x40) = 0;
    *(int*)((char*)this + 0x44) = 0;
    return 0;
}
