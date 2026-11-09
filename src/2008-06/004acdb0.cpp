// from server: 100% by king_originala
extern void __cdecl transfer(void *destination, const float *source);

struct S {
    char padding[4];
    int enabled;
    void apply(const float *source);
};

void __cdecl initialize(S *object, void *destination)
{
    float value[3] = { 0.0f, 0.0f, 0.0f };
    transfer(destination, value);
    if (object->enabled != 0)
        object->apply(value);
}
