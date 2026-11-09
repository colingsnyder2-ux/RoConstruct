// from server: 80% by atomic.potato
extern "C" void __cdecl f_0040c470(void);

struct FaceInstance_0069f2b0 {
    char pad[164];
    int value;
    void setValue(int value);
};

void FaceInstance_0069f2b0::setValue(int value)
{
    if (this->value == value)
        return;
    this->value = value;
    f_0040c470();
}
