// from server: 47% by atomic.potato
struct DxUserInputJob
{
    int enabled;
    int value;
};

struct InputVector
{
    float x;
    float y;
};

extern "C" void __cdecl Function00497e30(InputVector* result, DxUserInputJob* input)
{
    result->x = 0.0f;
    result->y = 0.0f;

    if (input->enabled == 0)
        result->x = (float)input->value;
    else
        result->y = (float)input->value;
}
