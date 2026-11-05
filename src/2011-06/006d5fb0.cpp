// from server: 42% by atomic.potato
struct Motor
{
    void sub_411f60(const char*);
    char reserved[0xb4];
    void* field_b4;
    void set(float);
};

void Motor::set(float value)
{
    float old = *(float*)((char*)field_b4 + 0xac);
    if (value != old)
    {
        float diff = value - old;
        if (diff < 0.0f) diff = -diff;
        float tol = old;
        if (tol < 0.0f) tol = -tol;
        tol = (tol + *(float*)0xa63b14) * *(float*)0xaa6e3c;
        if (diff < tol)
        {
            *(float*)((char*)field_b4 + 0xac) = value;
            sub_411f60((const char*)0xcd1710);
            sub_411f60((const char*)0xcd1668);
        }
    }
}
