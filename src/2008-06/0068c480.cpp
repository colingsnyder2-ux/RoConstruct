// from server: 100% by king_originala
struct Matrix4;
struct Camera;
struct Renderer;

typedef const Matrix4& (__thiscall *ViewMatrixFunction)(Camera*, bool);
extern ViewMatrixFunction getViewMatrix;

struct CameraTable {
    char padding[0x148];
    const Matrix4& (__thiscall *getProjectionMatrix)(Camera*);
};

struct Camera {
    CameraTable* table;
};

struct RendererTable {
    char padding[0x68];
    void (__thiscall *setViewMatrix)(Renderer*, const Matrix4&);
    void (__thiscall *setProjectionMatrix)(Renderer*, const Matrix4&);
};

struct Renderer {
    RendererTable* table;
};

struct S {
    char padding0[0x34];
    Renderer* renderer;
    char padding1[0xB8 - 0x38];
    Camera* camera;
    char padding2[0x41D8 - 0xBC];
    bool viewDirty;
    bool projectionDirty;

    void updateMatrices();
};

void S::updateMatrices()
{
    if (viewDirty) {
        RendererTable* table = renderer->table;
        const Matrix4& matrix = getViewMatrix(camera, true);
        table->setViewMatrix(renderer, matrix);
        viewDirty = false;
    }

    if (projectionDirty) {
        RendererTable* table = renderer->table;
        const Matrix4& matrix = camera->table->getProjectionMatrix(camera);
        table->setProjectionMatrix(renderer, matrix);
        projectionDirty = false;
    }
}
