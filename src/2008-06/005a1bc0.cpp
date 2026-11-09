// from server: 100% by colin
// from server: 97% by king_originala
extern char instanceDescriptor;
extern char renderableDescriptor;

extern "C" void *__cdecl __RTDynamicCast(
    void *, long, void *, void *, int);

struct Instance;

struct IRenderable;

struct RenderableSet {
    void remove(IRenderable *);
};

struct NotificationArgument {
    bool value;
};

struct Notification {
    void notify(NotificationArgument);
    char storage[0x44];
};

struct S {
    char padding[0x344];
    Notification notification;
    RenderableSet renderables;

    void baseRemove(Instance **);
    void remove(Instance **);
};

void S::remove(Instance **object)
{
    void *raw = *object;
    IRenderable *renderable = static_cast<IRenderable *>(
        __RTDynamicCast(raw, 0, &instanceDescriptor,
                        &renderableDescriptor, 0));
    if (renderable)
        renderables.remove(renderable);

    baseRemove(object);

    NotificationArgument argument;
    argument.value = false;
    notification.notify(argument);
}
