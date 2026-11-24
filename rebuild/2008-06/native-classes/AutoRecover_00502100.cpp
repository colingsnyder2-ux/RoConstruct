// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: minimal local declarations of the G3D types; no native headers were shown.
namespace G3D {

class Color3 {
public:
    float r, g, b;
    Color3() {}
    Color3(float R, float G, float B) : r(R), g(G), b(B) {}
    Color3 operator/(float s) const;   // ??K (operator/) at 0x514c40
};

class Vector3 {
public:
    float x, y, z;
    Vector3() {}
    Vector3(float X, float Y, float Z) : x(X), y(Y), z(Z) {}
    Vector3 xyz() const;               // 0x514890
};

class GLight {
public:
    char storage[0x50];
    static GLight directional(const Vector3& toLight, const Color3& color,
                              bool castsShadows, bool specular);
};

class RenderDevice {
public:
    void enableLighting();
    void setAmbientLightColor(const Color3& c);
};

} // namespace G3D

using namespace G3D;

extern "C" int __fastcall fn_00478a00(void* self, int unusedEdx, int a1, int a2);

// INFERRED: unknown float globals (constants read from the original data section)
extern "C" float g_0081c434;
extern "C" float g_0081c3b8;
extern "C" float g_0081e704;
extern "C" float g_0082740c;

// INFERRED: layout of the lighting object at owner+0x2ec
struct LightingState {
    char pad0[0x18];
    Color3 colorA;        // +0x18
    Color3 colorB;        // +0x24
    char pad1[0x10];
    GLight* lights;       // +0x40
    int numLights;        // +0x44
    int allocLights;      // +0x48
    GLight* extraLights;  // +0x4c
    int numExtra;         // +0x50
};

struct LightingOwner {
    char pad0[0x2d9];
    bool flag;                  // +0x2d9
    char pad1[0x2ec - 0x2da];
    LightingState* lighting;    // +0x2ec
};

extern "C" void __fastcall fn_00502100(LightingOwner* self, int unusedEdx, RenderDevice* rd, bool addExtra)
{
    rd->enableLighting();

    LightingState* L = self->lighting;
    int i;
    for (i = 0; i < L->numLights; ++i) {
        fn_00478a00(rd, 0, i, (int)(L->lights + i));
        L = self->lighting;
    }

    if (addExtra) {
        L = self->lighting;
        for (i = 0; i < L->numExtra; ++i) {
            fn_00478a00(rd, 0, self->lighting->numLights + i, (int)(self->lighting->extraLights + i));
            L = self->lighting;
        }
    }

    L = self->lighting;
    Color3 sum(L->colorB.r + L->colorA.r,
               L->colorB.g + L->colorA.g,
               L->colorB.b + L->colorA.b);
    Color3 ambient = sum / g_0081c434;
    rd->setAmbientLightColor(ambient);

    L = self->lighting;
    int idx = L->numExtra * 2;
    Vector3 dir(g_0082740c, g_0081c3b8, g_0081e704);
    if (L->numExtra > 0) {
        Vector3 v = ((Vector3*)L->extraLights)->xyz();
        dir = Vector3(-v.x, -v.y, -v.z);
    }

    if (!self->flag)
        return;

    L = self->lighting;
    if (!(ambient.r == L->colorB.r && ambient.g == L->colorB.g && ambient.b == L->colorB.b)) {
        Color3 diff(L->colorB.r - ambient.r,
                    L->colorB.g - ambient.g,
                    L->colorB.b - ambient.b);
        GLight l = GLight::directional(dir, diff, false, true);
        fn_00478a00(rd, 0, idx, (int)&l);
        ++idx;
    }

    LightingState* M = self->lighting;
    if (!(ambient.r == M->colorA.r && ambient.g == M->colorA.g && ambient.b == M->colorA.b)) {
        Color3 diff(M->colorA.r - ambient.r,
                    M->colorA.g - ambient.g,
                    M->colorA.b - ambient.b);
        static Vector3 up(0.0f, 1.0f, 0.0f);
        GLight l = GLight::directional(up, diff, false, true);
        ++idx;
        fn_00478a00(rd, 0, idx, (int)&l);
    }
}
