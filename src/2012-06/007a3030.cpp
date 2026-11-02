// from server: 93% by tajop
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);
extern "C" char g_d601e8[];
extern "C" char g_d65108[];
extern "C" const float g_b5ef80;

struct Instance {
    char pad0[0x38];
    Instance* parent;
    Instance* getRootAncestor();
};

struct Camera {
    char pad0[0x148];
    int cameraType;
    void apply(float value);
};

struct CameraHolder {
    virtual void slot0();
    virtual Camera* get();
};

struct Workspace {
    char pad0[0x150];
};

struct DataModel {
    Workspace* getWorkspace();
};

struct Settings {
    char pad0[0x8c];
    int mode;
    char pad1[6];
    char flag;
};

extern "C" Settings* __cdecl sub_443530();

struct StepEvent {
    char pad0[8];
    double dt;
};

struct InputState {
    char pad0[2];
    bool a;
    bool b;
    char pad1[2];
    bool c;
    bool d;
};

struct Controller : Instance {
    char pad1[0xb4 - 0x3c];
    int count;
    float speed;
    void method(const StepEvent* e, const InputState* in);
};

void Controller::method(const StepEvent* e, const InputState* in)
{
    Workspace* ws;
    Instance* root;
    DataModel* dm;
    if (!this) goto none;
    {
        Instance* p = parent;
        if (p) {
            Instance* q = p->parent;
            if (q) p = q->getRootAncestor();
            root = p;
        } else {
            root = this;
        }
    }
    if (!root) goto none;
    dm = (DataModel*)__RTDynamicCast(root, 0, g_d601e8, g_d65108, 0);
    if (dm) {
        ws = dm->getWorkspace();
    } else {
none:
        ws = 0;
    }
    Camera* cam = ((CameraHolder*)((char*)ws + 0x150))->get();
    Settings* s = sub_443530();
    int v;
    if (s->mode == 3 && s->flag == 0) {
        v = in->c ? 1 : (in->d ? -1 : 0);
    } else {
        v = in->a ? 1 : (in->b ? -1 : 0);
    }
    if (cam->cameraType != 6 && v != 0) {
        cam->apply((float)e->dt * speed * v * g_b5ef80);
        count++;
        return;
    }
    count = 0;
}
