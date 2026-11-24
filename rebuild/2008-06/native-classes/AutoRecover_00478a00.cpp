// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is G3D::RenderDevice::setLight(int i, const GLight* light).
// The RenderDevice header is not available, so the object is accessed through
// raw byte offsets. Minimal G3D types are declared locally with the layouts
// the disassembly implies.

namespace G3D {

struct Color3 {
    float r, g, b;
    Color3 operator*(float s) const;
};

struct CoordinateFrame;

struct GLight {
    float  position[4];      // 0x00
    float  spotDirection[3]; // 0x10
    double spotCutoff;       // 0x20
    double attenuation[3];   // 0x28, 0x30, 0x38
    Color3 color;            // 0x40
    bool   enabled;          // 0x4c
    bool   specular;         // 0x4d
    bool   diffuse;          // 0x4e
    // sizeof == 0x50

    bool operator!=(const GLight& other) const;
    GLight& operator=(const GLight& other);
};

int  glGetInteger(unsigned int which);
void glLoadMatrix(const CoordinateFrame& cf);

} // namespace G3D

extern "C" {
__declspec(dllimport) void __stdcall glEnable(unsigned int cap);
__declspec(dllimport) void __stdcall glDisable(unsigned int cap);
__declspec(dllimport) void __stdcall glMatrixMode(unsigned int mode);
__declspec(dllimport) void __stdcall glPushMatrix(void);
__declspec(dllimport) void __stdcall glPopMatrix(void);
__declspec(dllimport) void __stdcall glLoadIdentity(void);
__declspec(dllimport) void __stdcall glLightfv(unsigned int light, unsigned int pname, const float* params);
__declspec(dllimport) void __stdcall glLightf(unsigned int light, unsigned int pname, float param);
}

using namespace G3D;

extern "C" void __fastcall fn_00478a00(void* selfv, int unusedEdx, int i, const GLight* light)
{
    char* self = (char*)selfv;

    ++*(int*)(self + 0x78);
    unsigned int gi = 0x4000 + i;

    if (light == 0) {
        if (self[i + 0x3a0]) {
            self[i + 0x3a0] = 0;
            self[0x3bd] = 1;
            glDisable(gi);
        }
        ++*(int*)(self + 0x70);
        return;
    }

    if (!self[i + 0x3a0]) {
        glEnable(gi);
        self[i + 0x3a0] = 1;
        self[0x3bd] = 1;
    }

    GLight* stored = (GLight*)(self + 0x120 + i * 0x50);
    if (*stored != *light) {
        self[0x3bd] = 1;
        *stored = *light;

        ++*(int*)(self + 0x70);

        float black[4];
        black[0] = 0.0f;
        black[1] = 0.0f;
        black[2] = 0.0f;
        black[3] = 1.0f;

        float scale = (float)*(double*)(self + 0x10);
        Color3 c = light->color * scale;
        float col[4];
        col[0] = c.r;
        col[1] = c.g;
        col[2] = c.b;
        col[3] = 1.0f;

        int oldMode = glGetInteger(0xBA0);
        glMatrixMode(0x1700);
        glPushMatrix();
        glLoadIdentity();
        glLoadMatrix(*(const CoordinateFrame*)(self + 0x808));

        glLightfv(gi, 0x1203, light->position);
        glLightfv(gi, 0x1204, light->spotDirection);
        glLightf(gi, 0x1206, (float)light->spotCutoff);
        glLightfv(gi, 0x1200, black);
        glLightfv(gi, 0x1201, light->diffuse ? col : black);
        glLightfv(gi, 0x1202, light->specular ? col : black);
        glLightf(gi, 0x1207, (float)light->attenuation[0]);
        glLightf(gi, 0x1208, (float)light->attenuation[1]);
        glLightf(gi, 0x1209, (float)light->attenuation[2]);

        glPopMatrix();
        glMatrixMode((unsigned int)oldMode);
    }
}
