// from server: 100% by king_originala
struct Listener {
    char storage;
};

struct ListenerCollection {
    void detach(Listener*);
    void attach(Listener*);
};

struct Service {
    char padding[0x150];
    ListenerCollection listeners;
};

struct Instance {
    Service* getService();
};

struct Prefix {
    char padding[0x138];
};

struct BodyMover : Prefix, Listener {
    void changeParent(Instance* previous, Instance* current);
};

void BodyMover::changeParent(Instance* previous, Instance* current)
{
    if (previous) {
        Listener* listener = static_cast<Listener*>(this);
        Service* service = previous->getService();
        if (service)
            service->listeners.detach(listener);
    }

    if (current) {
        Listener* listener = static_cast<Listener*>(this);
        Service* service = current->getService();
        if (service)
            service->listeners.attach(listener);
    }
}
