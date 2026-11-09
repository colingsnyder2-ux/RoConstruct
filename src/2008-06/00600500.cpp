// from server: 100% by tester
struct S_005d4cb0 {
    void* f();
};

extern float G_007bb79c;
extern float G_007bb798;
extern float G_008c6a68;
extern float G_008c6a6c;
extern float G_008c6a70;
extern unsigned int G_008c6a74;

void* S_005d4cb0::f()
{
    if (!(G_008c6a74 & 1)) {
        G_008c6a68 = G_007bb79c;
        G_008c6a74 |= 1;
        G_008c6a6c = G_007bb798;
        G_008c6a70 = G_007bb798;
    }
    return &G_008c6a68;
}
