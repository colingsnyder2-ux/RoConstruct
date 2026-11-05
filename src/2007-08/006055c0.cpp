// from server: 49% by colin
struct Assembly {
    char pad[0x60];
    float* field60;
};

struct SleepStage {
    char pad0[0x14];
    char field14[0x24];
    char field38[0x24];
    void stepSleepStage(Assembly* a);
};

extern "C" double __stdcall sqrt_helper(double);
extern "C" void __stdcall func52dc20(void*, void*, void*);
extern "C" void __stdcall func605300(void*, void*, void*);

void SleepStage::stepSleepStage(Assembly* a)
{
    float* p = a->field60;
    float x = p[1];
    float y = p[2];
    float z = p[3];
    float v;
    if (x < y) {
        if (x < z) {
            v = y * z;
        } else {
            v = x * y;
        }
    } else {
        if (y < z) {
            v = x * z;
        } else {
            v = x * y;
        }
    }
    double d = sqrt_helper((double)v);
    float fd = (float)d;
    int n = (int)fd;
    void* ptr1 = a;
    int val1 = n;
    func52dc20((char*)this + 0x14, &ptr1, &val1);
    void* ptr2 = a;
    int val2 = n;
    func605300((char*)this + 0x38, &ptr2, &val2);
}
