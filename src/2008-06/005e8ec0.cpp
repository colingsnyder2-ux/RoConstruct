// from server: 100% by king_originala
struct Listener {
    void detach(void*);
    void attach(void*);
    unsigned char storage[0x20];
};

struct Connections {
    unsigned char padding[0x40];
    Listener first;
    Listener second;
};

struct Object {
    unsigned char padding[0x2e4];
    Connections* connections;
};

struct Instance {
    Object* getObject();
};

struct PhysicsService {
    unsigned char padding[0x130];
    unsigned int first;
    unsigned int second;

    void change(Instance*, Instance*);
};

void PhysicsService::change(Instance* previous, Instance* current)
{
    if (previous) {
        Object* object = previous->getObject();
        if (object) {
            Connections* connections = object->connections;
            void* listener = this ? &first : 0;
            if (connections)
                connections->first.detach(listener);
            listener = this ? &second : 0;
            if (connections)
                connections->second.detach(listener);
        }
    }

    if (current) {
        Object* object = current->getObject();
        if (object) {
            Connections* connections = object->connections;
            void* listener = this ? &first : 0;
            if (connections)
                connections->first.attach(listener);
            listener = this ? &second : 0;
            if (connections)
                connections->second.attach(listener);
        }
    }
}
