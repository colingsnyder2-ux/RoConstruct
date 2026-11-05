// from server: 100% by king_originala
struct Vector {
    float x, y, z;
};

struct Camera {
    float rotation[9];
    Vector position;
    Vector* direction(Vector*);
    void column(Vector*, int);
};

struct View {
    void* camera(void*);
    void* instance();
};

struct ViewSource {
    virtual void unused();
    virtual View* getView();
};

struct Provider {
    char padding[0x288];
    ViewSource source;
};

struct VelocitySource {
    virtual Vector* getSource();
};

struct MovingObject {
    const Vector* velocity();
};

struct CastObject {
    char padding[0x134];
    int* baseOffsets;
};

struct Collection {
    char storage[32];
};

struct Owner {
    char padding[0x178];
    double deadline;
    Collection first;
    Collection second;
};

extern Provider* __cdecl findProvider(void*);
extern bool __cdecl convertVector(const Vector*, Vector*);
extern double __cdecl currentTime();
extern void __cdecl updateCollection(Collection*);
extern void __cdecl checkResult(int);
extern "C" int __stdcall updateSystem(void*);
extern "C" int __stdcall setListener(
    void*, int, const Vector*, const Vector*, const Vector*, const Vector*);
extern "C" void* __cdecl __RTDynamicCast(
    void*, long, void*, void*, int);

extern char instanceType;
extern char movingType;
extern const double updateInterval;

struct SoundService {
    void* unused;
    void* system;
    void update(void*, void*, void*);
};

void SoundService::update(void*, void*, void*)
{
    if (!system)
        return;

    Owner* owner = reinterpret_cast<Owner*>(
        reinterpret_cast<char*>(this) - 0x130);

    Provider* provider = findProvider(owner);
    if (provider) {
        View* view = provider->source.getView();
        if (view) {
            Camera camera;
            Vector position;
            Vector forward;
            Vector up;
            Vector velocity;

            view->camera(&camera);
            if (convertVector(&camera.position, &position)) {
                Vector* direction = camera.direction(&up);
                velocity.x = -direction->x;
                velocity.y = -direction->y;
                velocity.z = -direction->z;

                if (convertVector(&velocity, &forward)) {
                    camera.column(&velocity, 1);
                    if (convertVector(&velocity, &up)) {
                        velocity.z = 0.0f;
                        velocity.y = 0.0f;
                        velocity.x = 0.0f;

                        CastObject* object =
                            static_cast<CastObject*>(__RTDynamicCast(
                                view->instance(), 0,
                                &instanceType, &movingType, 0));

                        if (object) {
                            VelocitySource* source =
                                reinterpret_cast<VelocitySource*>(
                                    reinterpret_cast<char*>(object) +
                                    0x134 + object->baseOffsets[1]);
                            MovingObject* moving =
                                reinterpret_cast<MovingObject*>(
                                    source->getSource());
                            if (moving)
                                convertVector(moving->velocity(), &velocity);
                        }

                        checkResult(setListener(
                            system, 0, &position, &velocity, &forward, &up));
                    }
                }
            }
        }
    }

    if (!(currentTime() < owner->deadline)) {
        updateCollection(&owner->first);
        updateCollection(&owner->second);
        owner->deadline = currentTime() + updateInterval;
    }

    checkResult(updateSystem(system));
}
