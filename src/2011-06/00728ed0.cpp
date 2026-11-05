// from server: 83% by atomic.potato
extern int g_value;

struct FaceInstance
{
    int padding[41];
    int value;
    void setValue(int);
};

void FaceInstance::setValue(int value)
{
    if (this->value == value)
        return;
    this->value = value;
    g_value = 0;
}
