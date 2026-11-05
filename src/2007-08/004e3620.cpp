// from server: 25% by colin
struct PBBBuilder {
    void build(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t);
};

extern "C" void __stdcall sub_5B99B0(void*, void*);
extern "C" void* __stdcall sub_62FF32(unsigned int);
extern "C" void __stdcall sub_62FF26(void*);
extern "C" void __stdcall sub_62FC62(void*);
extern "C" void* __stdcall sub_501570();
extern "C" void* __stdcall sub_4F5360(void*, void*, void*, int);
extern "C" void __stdcall sub_4F54E0(void*);
extern "C" void __stdcall sub_4EEE30(void*, int, int, int, int);
extern "C" int __stdcall InterlockedDecrement(int*);

void PBBBuilder::build(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t)
{
    char buf[0x88];
    int* arr;
    int x, y, w, h2;
    int i2, j2;
    float fx, fy, fw, fh;
    float stepx, stepy;
    float u0, v0, u1, v1;
    float* uv;
    int* idx;
    int count;
    int* ptr;
    int* tmp;
    int* p2;

    sub_5B99B0(buf, (char*)this + 4);
    x = *(short*)(buf + 0x78);
    y = *(short*)(buf + 0x7a);
    w = x + 1;
    h2 = y + 1;
    count = w * h2;
    arr = (int*)sub_62FF32(count * 4);
    ptr = arr;
    fx = *(float*)(buf + 0x58);
    fy = *(float*)(buf + 0x5c);
    fw = *(float*)(buf + 0x60);
    fh = *(float*)(buf + 0x64);
    stepx = (fw - fx) / (float)w;
    stepy = (fh - fy) / (float)h2;
    u0 = *(float*)(buf + 0x68);
    v0 = *(float*)(buf + 0x6c);
    u1 = *(float*)(buf + 0x70);
    v1 = *(float*)(buf + 0x74);
    if (x >= 0) {
        float cy = fy;
        float cx = fx;
        int row;
        for (row = 0; row <= y; row++) {
            float px = cx;
            int col;
            for (col = 0; col <= x; col++) {
                float u = u0 + (u1 - u0) * (float)col / (float)w;
                float v = v0 + (v1 - v0) * (float)row / (float)h2;
                float* uv2 = (float*)sub_501570();
                if (uv2[0] != u || uv2[1] != v) {
                    u = u0;
                    v = v0;
                }
                float uu = u * 255.0f;
                float vv = v * 255.0f;
                float tmp2[2];
                tmp2[0] = uu;
                tmp2[1] = vv;
                float tmp3[2];
                tmp3[0] = px;
                tmp3[1] = cy;
                *ptr = (int)sub_4F5360(tmp3, tmp2, buf + 0x30, 1);
                ptr++;
                px += stepx;
            }
            cy += stepy;
        }
    }
    if (x > 0) {
        int row;
        for (row = 0; row < x; row++) {
            int col;
            for (col = 0; col < y; col++) {
                sub_4EEE30((void*)this, arr[col + row * w], arr[col + 1 + row * w], arr[col + (row + 1) * w], arr[col + 1 + (row + 1) * w]);
            }
        }
    }
    for (i2 = 0; i2 < x; i2++) {
        sub_4F54E0((void*)arr[i2]);
    }
    sub_62FF26(arr);
    if (buf[0x18]) {
        if (InterlockedDecrement((int*)(buf + 0x18)) == 0) {
            void* p = *(void**)(buf + 0x1c);
            while (p) {
                void* next = *(void**)((char*)p + 4);
                (*(void(**)(void*))p)(p);
                sub_62FC62(p);
                p = next;
            }
            (*(void(**)(void*))buf)(buf);
        }
    }
}
