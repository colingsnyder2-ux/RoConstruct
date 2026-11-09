// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD

extern "C" __declspec(dllimport) void __stdcall glShadeModel(unsigned);
extern "C" __declspec(dllimport) void __stdcall glDepthMask(unsigned char);

class GCamera;
class GLight { char data[0x50]; };
class Color4;

class Lighting
{
public:
    char pad[0x4c];
    GLight* shadowedLightData;
    int shadowedLightNum;
};

class Sky
{
public:
    void render(class RenderDevice* rd, const void* params);
    void renderLensFlare(class RenderDevice* rd, const void* params);
};

class ToneMap { public: void beginFrame(); void endFrame(); };
class DepthBlur { public: void apply(); };

class RenderDevice
{
public:
    char pad0[0x3c];
    int triangleCount;
    char pad1[0x70 - 0x40];
    int minorGLStateChanges;
    char pad2[0x78 - 0x74];
    int minorStateChanges;
    char pad3[0x3e1 - 0x7c];
    bool depthWrite;
    char pad4[0x44c - 0x3e2];
    int shadeMode;

    void setStencilConstant(int);
    void setStencilClearValue(int);
    void setProjectionAndCameraMatrix(const GCamera&);
    void setColorClearValue(const Color4*);
    void clear(bool, bool, bool);
    void setDepthTest(int);
    void setAlphaTest(int, double);
    void pushState();
    void popState();
    void setBlendFunc(int, int, int);
    void enableLighting();
    void setLight(int, const GLight&);
    void setPolygonOffset(double);
    void setStencilTest(int);
    int debugNumPushStateCalls();
    int debugNumMajorOpenGLStateChanges();
    int debugNumMinorOpenGLStateChanges();
    int debugNumMajorStateChanges();
    int debugNumMinorStateChanges();

    void setShadeMode(int s)
    {
        minorStateChanges += 1;
        if (shadeMode != s)
        {
            shadeMode = s;
            glShadeModel(s == 0 ? 0x1d00 : 0x1d01);
            minorGLStateChanges += 1;
        }
    }

    void disableDepthWrite()
    {
        minorStateChanges += 1;
        if (depthWrite)
        {
            minorGLStateChanges += 1;
            glDepthMask(0);
            depthWrite = false;
        }
    }
};

class Timer { public: void tick(); void tock(); };

class Mesh
{
public:
    static void beginRender(RenderDevice*, bool, bool);
    static void endRender(RenderDevice*);
};

ToneMap* __stdcall getToneMap(RenderDevice*);
DepthBlur* __stdcall getDepthBlur(RenderDevice*);

class RenderScene
{
public:
    char pad0[0x14];
    Color4* colorClearValueDummy;
    char pad1[0x138 - 0x18];
    Timer cpuRenderTotal;
    char pad2[0x190 - 0x139];
    Timer cpuShadow;
    char pad3[0x240 - 0x191];
    int majorStateChanges;
    int majorGLStateChanges;
    int minorStateChanges;
    int minorGLStateChanges;
    int pushPadding0;
    int pushPopCount;
    int totalTriangles;
    int markShadowsTriangles;
    int shadowedLightTriangles;
    int unshadowedTriangles;
    char pad4[0x2d4 - 0x268];
    bool stencilShadows;
    bool alphaBlendShadowLights;
    bool useAllLights;
    bool skyBox;
    bool applyToneMap;
    bool pad5;
    bool applyDepthBlur;
    char pad6[0x2ec - 0x2db];
    Lighting* lighting;
    char pad7[0x304 - 0x2f0];
    bool debugShadowVolumes;
    char pad8[3];
    Sky* sky;
    char pad9[0x408 - 0x30c];
    char skyParameters[1];

    void render(RenderDevice* rd, const GCamera& camera);
    void computeProxyArrays(RenderDevice*, const GCamera&);
    void turnOnLights(RenderDevice*, bool);
    void sendDiffuseProxyMeshGeometry(RenderDevice*);
    void markStencilShadows(RenderDevice*, const GCamera&, const GLight&);
    void reflectionPass(RenderDevice*);
    void transparentPass(RenderDevice*);
};

void RenderScene::render(RenderDevice* rd, const GCamera& camera)
{
    int startTriangleCount = rd->triangleCount;
    int markShadowsTriCount = 0;
    int unshadowedTriCount = 0;
    int shadowedTriCount = 0;

    cpuRenderTotal.tick();

    rd->setStencilConstant(0);
    rd->setStencilClearValue(0);
    rd->setProjectionAndCameraMatrix(camera);

    if (applyToneMap)
    {
        getToneMap(rd)->beginFrame();
    }

    rd->setColorClearValue((Color4*)((char*)this + 0x14));
    rd->clear(sky == 0 || !skyBox, true, true);

    if (sky != 0 && skyBox)
    {
        sky->render(rd, skyParameters);
    }

    computeProxyArrays(rd, camera);

    rd->setShadeMode(1);
    rd->setDepthTest(3);
    rd->setAlphaTest(0, 0.1);
    rd->pushState();

    turnOnLights(rd, useAllLights);

    Mesh::beginRender(rd, true, false);

    if (!debugShadowVolumes)
    {
        int prevTriangleCount = rd->triangleCount;
        sendDiffuseProxyMeshGeometry(rd);
        unshadowedTriCount = rd->triangleCount - prevTriangleCount;
    }

    Mesh::endRender(rd);

    rd->popState();

    if (stencilShadows)
    {
        rd->pushState();
        rd->disableDepthWrite();
        rd->setDepthTest(3);

        for (int i = 0; i < lighting->shadowedLightNum; i++)
        {
            if (i > 0)
            {
                rd->clear(false, false, true);
            }

            const GLight& current = lighting->shadowedLightData[i];

            if (alphaBlendShadowLights)
            {
                rd->setBlendFunc(2, 2, 2);
                rd->enableLighting();
                rd->setLight(0, current);
            }
            else
            {
                turnOnLights(rd, true);
            }

            int prevTriangleCount = rd->triangleCount;
            markStencilShadows(rd, camera, current);
            markShadowsTriCount += rd->triangleCount - prevTriangleCount;

            if (!debugShadowVolumes)
            {
                rd->setStencilConstant(0);
                rd->setDepthTest(3);

                int prevTriCount = rd->triangleCount;

                rd->setPolygonOffset(0.0);
                rd->setStencilTest(5);

                Mesh::beginRender(rd, true, false);
                sendDiffuseProxyMeshGeometry(rd);
                Mesh::endRender(rd);

                shadowedTriCount += rd->triangleCount - prevTriCount;
            }
        }

        rd->popState();
    }
    else
    {
        cpuShadow.tick();
        cpuShadow.tock();
    }

    rd->pushState();

    Mesh::beginRender(rd, true, false);
    reflectionPass(rd);
    Mesh::endRender(rd);

    rd->popState();

    rd->pushState();

    turnOnLights(rd, true);
    Mesh::beginRender(rd, true, false);
    transparentPass(rd);
    Mesh::endRender(rd);

    rd->popState();

    if (sky != 0 && skyBox)
    {
        sky->renderLensFlare(rd, skyParameters);
    }

    if (applyDepthBlur)
    {
        getDepthBlur(rd)->apply();
    }

    if (applyToneMap)
    {
        getToneMap(rd)->endFrame();
    }

    cpuRenderTotal.tock();
    pushPopCount = rd->debugNumPushStateCalls();

    int endTriangleCount = rd->triangleCount;

    markShadowsTriangles = markShadowsTriCount;
    totalTriangles = endTriangleCount - startTriangleCount;
    shadowedLightTriangles = shadowedTriCount;
    unshadowedTriangles = unshadowedTriCount;
    majorGLStateChanges = rd->debugNumMajorOpenGLStateChanges();
    minorGLStateChanges = rd->debugNumMinorOpenGLStateChanges();
    majorStateChanges = rd->debugNumMajorStateChanges();
    minorStateChanges = rd->debugNumMinorStateChanges();
}
