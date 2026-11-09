// from server: 100% by king_originala
typedef unsigned int size_t;

void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

struct Stage;
struct Body;

struct Joint {
    char storage[36];
    Joint();
};

struct ActiveObject {
    void activate();
};

struct Link3 {
    char pad[44];
    ActiveObject* active;
};

struct Link2 {
    char pad[16];
    Link3* next;
};

struct Link1 {
    char pad[160];
    Link2* next;
};

struct Owner {
    char pad[28];
    Link1* next;
};

struct Body {
    char pad[36];
    Owner* owner;
    void attach(Stage*);
    void setJoint(int);
};

struct InsertResult {
    unsigned int data[3];
};

struct Collection {
    InsertResult insert(Body* const&);
};

struct Manager {
    void update(Body*, int);
};

struct Stage {
    char pad0[12];
    Manager* manager;
    char pad1[240];
    Collection collection;
    void f(Body* volatile);
};

void Stage::f(Body* volatile body)
{
    Body* saved = body;
    saved->attach(this);
    saved->setJoint((int)new Joint);

    ActiveObject* active = saved->owner->next->next->next->active;
    if (active)
        active->activate();

    collection.insert((Body* const&)body);
    manager->update(saved, 1);
}
