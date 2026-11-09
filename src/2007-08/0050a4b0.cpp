// from server: 100% by colin
struct GCamera {
    void construct(float, float, float, float, float, float, float, float, float);
};

extern GCamera g_camera;
extern unsigned int g_cameraInitFlag;

GCamera* getCamera()
{
    if ((g_cameraInitFlag & 1) == 0) {
        g_cameraInitFlag |= 1;
        g_camera.construct(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    }
    return &g_camera;
}
