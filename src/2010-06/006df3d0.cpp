// from server: 80% by atomic.potato
extern "C" void __cdecl Call_0061f1a0(void*, float, float, float);

struct ImageLabel {
    char padding[32];
    float x20;
    float x24;
    float x28;
    void* SetImage(void*);
};

void* ImageLabel::SetImage(void* value)
{
    Call_0061f1a0(value, x28, x24, x20);
    return value;
}
