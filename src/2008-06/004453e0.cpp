// from server: 100% by king_originala
#pragma pointers_to_members(full_generality, multiple_inheritance)

struct Object;

struct S {
    char padding[16];
    void (Object::*setter)(int);
    void setValue(void* object, const float* value);
};

void S::setValue(void* object, const float* value)
{
    Object* adjusted = object
        ? reinterpret_cast<Object*>(static_cast<char*>(object) - 20)
        : 0;
    (adjusted->*setter)(static_cast<int>(*value));
}
