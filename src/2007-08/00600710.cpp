// from server: 100% by colin
struct InputObject;

struct Widget {
    char pad[0x100];
    void* verb;
    void onClick(const InputObject* event);
};

void Widget::onClick(const InputObject* event)
{
    if (verb != 0) {
        if (((bool (__thiscall*)(void*))((*(void***)verb)[2]))(verb)) {
            void* v = verb;
            void* e = *(void**)((char*)event + 0x10);
            ((void (__thiscall*)(void*, void*))((*(void***)v)[4]))(v, e);
        }
    }
}
