// from server: 12% by colin
// roc 2007-08 004fa7f0  unit: RBX::Render::TextureProxy  size: 1232 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004fa7f0

struct TextureProxy {
    char pad0[0x28];
    void* texture;          // 0x28
    char pad2c[0x04];
    void* device;           // 0x30
    char pad34[0x04];
    char flag34;            // 0x34
    void* field38;          // 0x38
    void* field3c;          // 0x3c
    float f40;              // 0x40
    float f44;              // 0x44
    float f48;              // 0x48
    void method(int a, int b);
};

extern "C" {
    int __stdcall InterlockedDecrement(int*);
    int __stdcall InterlockedIncrement(int*);
    int __cdecl sprintf(char*, const char*, ...);
}

void TextureProxy::method(int a, int b)
{
    char buf[0x400];
    char buf2[0x100];
    char buf3[0x100];
    int i;
    void* p;
    int n;

    if (*(char*)((char*)this + 0x2c) != 0)
        return;

    if (field3c != 0) {
        char* s;
        if (*(unsigned*)((char*)field3c + 0x24) >= 0x10)
            s = *(char**)((char*)field3c + 0x10);
        else
            s = (char*)field3c + 0x10;
        sprintf(buf, "%g%g%g%s", f40, f44, f48, s);
    }

    for (i = 0; i < 0x100; i++) {
        buf3[i*3+0] = 0;
        buf3[i*3+1] = 0;
        buf3[i*3+2] = 0;
    }

    n = 0;
    if (n > 0) {
        int j = 0;
        do {
            unsigned char c = ((unsigned char*)buf2)[j];
            char* src = buf3 + c*3;
            ((unsigned char*)buf2)[j+0] = src[0];
            ((unsigned char*)buf2)[j+1] = src[1];
            ((unsigned char*)buf2)[j+2] = src[2];
            j += 3;
            n--;
        } while (n != 0);
    }
}
