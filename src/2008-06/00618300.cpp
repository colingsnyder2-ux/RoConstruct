// from server: 100% by king_originala
struct Instance;
struct Camera;

struct S {
    unsigned char flags[9];
    S();
    int f();
};

inline S::S()
{
    flags[0] = 0;
    flags[1] = 0;
    flags[2] = 0;
    flags[3] = 0;
    flags[4] = 0;
    flags[5] = 0;
    flags[6] = 0;
    flags[7] = 0;
    flags[8] = 0;
}

struct Camera {
    void func_005ce960(S*);
};

struct ServiceProvider {
    char padding[0x130];
    Camera* camera;
};

ServiceProvider* __cdecl func_005a32e0(Instance*);
void __cdecl func_005d7750(const float*, const float*);

struct NewNullTool {
    char padding0[0x14];
    Instance* instance;
    char padding1[0x1c];
    unsigned char enabled;
    char padding2[3];
    float position[3];

    void func_00618300(const float*);
};

void NewNullTool::func_00618300(const float* argument)
{
    if (enabled) {
        ServiceProvider* provider = func_005a32e0(instance);
        if (provider) {
            S state;
            provider->camera->func_005ce960(&state);
            if (!(unsigned char)state.f())
                func_005d7750(argument, position);
        }
    }
}
