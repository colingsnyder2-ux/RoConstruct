// from server: 100% by colin
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
struct Input {
    char pad[4];
    float rotation[3];
    float position[3];
};

struct Temporary {
    volatile int unused;
    float position[3];
};

extern float scale;
extern "C" void __cdecl construct(void*, const float*, const float*);

void* __cdecl f(void* result, const Input* input)
{
    Temporary temporary;
    temporary.position[0] = input->position[0] * scale;
    temporary.unused = 0;
    temporary.position[1] = input->position[1] * scale;
    temporary.position[2] = input->position[2] * scale;
    construct(result, input->rotation, temporary.position);
    return result;
}
