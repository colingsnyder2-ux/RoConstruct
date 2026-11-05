// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Vector2 {
    float x;
    float y;
};

struct Input {
    int axis;
    int value;
};

void __cdecl f(Vector2* result, const Input* input)
{
    result->x = 0.0f;
    if (input->axis == 0) {
        result->y = 0.0f;
        result->x = (float)input->value;
    } else {
        result->y = 0.0f;
        result->y = (float)input->value;
    }
}