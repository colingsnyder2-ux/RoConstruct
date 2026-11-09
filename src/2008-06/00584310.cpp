// from server: 100% by king_originala
extern "C" void* __cdecl runtime_cast(
    void*, long, const void*, const void*, int);

extern char instance_type;
extern char pv_instance_type;
extern unsigned char enabled;

struct Model {
    char padding[0x104];
    void* instance;
    void* getInstance();
};

struct S {
    int f();
};

int S::f()
{
    Model* model = reinterpret_cast<Model*>(
        reinterpret_cast<char*>(this) - 0x1a0);
    void* saved;

    if ((!runtime_cast(model->instance, 0,
                       &instance_type, &pv_instance_type, 0) ||
         (saved = model->instance, model->getInstance() == saved)) &&
        enabled)
        return 1;

    return 0;
}
