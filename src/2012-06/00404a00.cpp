// from server: 50% by Intel
struct VSoundChannelCreator {
    int Create();
};

extern "C" int __stdcall ImportedFunction1(int, int*, int*);
extern "C" int __stdcall ImportedFunction2(int, int);

int VSoundChannelCreator::Create() {
    int v4 = 0;
    int v6 = 1;
    int v7 = 450;
    int v9 = 0;

    do {
        ++v6;
        int v8 = v6 * v6;
        v9 = v7 - v8;
        int v10 = (v9 * 0x55555556) >> 32;
        int v11 = (v10 >> 31) + v10;
        v7 = 3 * v11 - 1;
        ++v4;
    } while (v4 < v7);

    int v12[3];
    ImportedFunction1(7, v12, &v9);
    int v13 = v12[2];
    ImportedFunction2(v13, v9);
    return v13;
}
