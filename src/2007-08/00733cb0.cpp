// from server: 52% by colin
struct TextureId {
    int id;
};

struct Sky {
    char pad0[0x38];
    TextureId* skyUp;      // 0x38
    int numStars;          // 0x3c
    TextureId* skyLf;      // 0x40
    float* starAngles;     // 0x44
    void setNumStars(int value);
};

extern "C" int __stdcall rand(void);

extern double g_78fee0;
extern double g_79f2c8;
extern double g_79f400;

extern void __stdcall sub_507190(TextureId* arr, int value, int flag);
extern void __stdcall sub_47c7d0(float* arr, int value, int flag);
extern float* __stdcall sub_50f560(float* out);

void Sky::setNumStars(int value)
{
    if (value == this->numStars)
        return;

    sub_507190(this->skyUp, value, 1);
    sub_47c7d0(this->starAngles, this->numStars, 1);

    int i = this->numStars - 1;
    if (i >= 0)
    {
        double base = 1.0 - g_78fee0;
        int offset = i << 4;
        do
        {
            float tmp[3];
            float* p = sub_50f560(tmp);
            TextureId* dst = (TextureId*)((char*)this->skyUp + offset);
            dst->id = *(int*)&p[0];
            *(float*)((char*)dst + 4) = p[1];
            *(float*)((char*)dst + 8) = p[2];
            *(float*)((char*)dst + 12) = 0.0f;

            int r = rand();
            float f = (float)r;
            f = (float)(f * base / g_79f2c8 + g_78fee0);
            f = f * f + (float)g_79f400;
            this->starAngles[i] = f;

            i--;
            offset -= 16;
        } while (i >= 0);
    }

    this->numStars = value;
}
