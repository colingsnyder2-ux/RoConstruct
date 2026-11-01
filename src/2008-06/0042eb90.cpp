// from server: 100% by king_originala
struct Object {
    char padding[0x2c];
    unsigned int flags;
};

extern "C" int __stdcall check(Object* object);

int __stdcall update(Object* object)
{
    if (!check(object))
        return 0;

    object->flags &= ~0x200u;
    return 1;
}
