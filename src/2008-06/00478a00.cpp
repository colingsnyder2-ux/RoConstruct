// from server: 100% by king_originala
#pragma float_control(precise, off)

extern "C" {
extern void (__stdcall *glDisable)(unsigned int);
extern void (__stdcall *glEnable)(unsigned int);
extern void (__stdcall *glMatrixMode)(unsigned int);
extern void (__stdcall *glLoadIdentity)();
extern void (__stdcall *glPushMatrix)();
extern void (__stdcall *glPopMatrix)();
extern void (__stdcall *glLightfv)(unsigned int, unsigned int, const float*);
extern void (__stdcall *glLightf)(unsigned int, unsigned int, float);
}

struct Color3 {
    float r, g, b;
    Color3* multiply(Color3*, float) const;
};

struct Light {
    float position[4];
    float direction[4];
    double exponent;
    double constantAttenuation;
    double linearAttenuation;
    double quadraticAttenuation;
    Color3 color;
    unsigned char flags[4];

    bool operator!=(const Light&) const;
    Light& operator=(const Light&);
};

struct Matrix {
    float data[12];
};

extern int __cdecl getInteger(unsigned int);
extern void __cdecl loadMatrix(const Matrix&);

struct S {
    unsigned char padding0[0x10];
    double colorScale;
    unsigned char padding1[0x58];
    int changes;
    unsigned char padding2[4];
    int calls;
    unsigned char padding3[0xa4];
    Light lights[8];
    unsigned char enabled[8];
    unsigned char padding4[0x15];
    unsigned char dirty;
    unsigned char padding5[0x44a];
    Matrix matrix;

    void setLight(int, const Light*);
};

void S::setLight(int index, const Light* light)
{
    ++calls;
    unsigned int number = index + 0x4000;

    if (!light) {
        if (enabled[index]) {
            enabled[index] = 0;
            dirty = 1;
            glDisable(number);
        }
        ++changes;
        return;
    }

    if (!enabled[index]) {
        glEnable(number);
        enabled[index] = 1;
        dirty = 1;
    }

    Light& cached = lights[index];
    if (cached != *light) {
        dirty = 1;
        cached = *light;
        ++changes;

        float black[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
        Color3 temporary;
        const Color3* scaled = light->color.multiply(&temporary, colorScale);
        float color[4] = { scaled->r, scaled->g, scaled->b, 1.0f };

        int oldMode = getInteger(0xba0);
        glMatrixMode(0x1700);
        glPushMatrix();
        glLoadIdentity();
        loadMatrix(matrix);

        void (__stdcall *lightfv)(unsigned int, unsigned int, const float*) = glLightfv;
        lightfv(number, 0x1203, light->position);
        lightfv(number, 0x1204, light->direction);

        void (__stdcall *lightf)(unsigned int, unsigned int, float) = glLightf;
        lightf(number, 0x1206, light->exponent);
        lightfv(number, 0x1200, black);

        if (light->flags[2])
            lightfv(number, 0x1201, color);
        else
            lightfv(number, 0x1201, black);

        if (light->flags[1])
            lightfv(number, 0x1202, color);
        else
            lightfv(number, 0x1202, black);

        lightf(number, 0x1207, light->constantAttenuation);
        lightf(number, 0x1208, light->linearAttenuation);
        lightf(number, 0x1209, light->quadraticAttenuation);

        glPopMatrix();
        glMatrixMode(oldMode);
    }
}
