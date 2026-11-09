// from server: 32% by atomic.potato
struct CRecord
{
    int field_00;
    int field_04;
    int field_08;
    char pad_0C[0x70 - 0x0C];
    int off70;
    int off78;
    char pad_7C[0x44C - 0x7C];
    int off44C;

    void sub_478990();
    void sub_47AFD0();
    void sub_478620();
    void render();
};

extern "C" void __stdcall glBegin(unsigned int mode);
extern "C" void __stdcall glEnd(void);
extern "C" void __stdcall glColor4fv(const float *v);
extern "C" void __stdcall glShadeModel(unsigned int mode);

extern "C" float cosf(float);
extern "C" float sinf(float);

extern float g_874DB0;

extern void sub_525ED0(float *dst, float *a, float *b);
extern void sub_7B0250(float *v, CRecord *rec, int i);

void CRecord::render()
{
    float mat[16];
    float pt[4];
    float col[4];
    float tmp[4];
    float a[4], b[4], c[4];
    int i, j, n;
    int flag = 0;

    for (i = 0; i < 0x28; i++)
    {
        float ang = (float)i * g_874DB0;
        float s = sinf(ang);
        float cc = cosf(ang);

        tmp[0] = cc * a[0] - s * a[1] + mat[12];
        tmp[1] = s * a[0] + cc * a[1] + mat[13];
        tmp[2] = a[2] + mat[14];
        tmp[3] = b[3];

        pt[0] = tmp[0] * a[3] + mat[4];
        pt[1] = tmp[1] * a[3] + mat[8];
        pt[2] = tmp[2] * a[3] + mat[0];
        pt[3] = 1.0f;
    }

    this->sub_478990();
    this->off70 += 0xC8;
    this->sub_47AFD0();
    glBegin(6);

    for (j = 0; j <= 0x28; j++)
    {
        n = j;
        float ang = (float)n * g_874DB0;
        float s = sinf(ang);
        float cc = cosf(ang);

        col[0] = a[0] * cc + a[1] * s + a[3];
        col[1] = b[0] * cc + b[1] * s + b[3];
        col[2] = c[0] * cc + c[1] * s + c[3];
        col[3] = tmp[3];

        glColor4fv(col);
    }

    glEnd();

    this->sub_478620();
    this->off70 += 0x28;

    col[0] = a[3];
    col[1] = b[3];
    col[2] = c[3];
    col[3] = tmp[3];
    glColor4fv(col);

    this->off78 += 1;
    if (flag != this->off44C)
    {
        this->off44C = flag;
        glShadeModel(0x1D00 + (flag != 0));
        this->off70 += 1;
    }

    sub_525ED0(a, b, c);
    sub_7B0250(c, this, 0);
}
