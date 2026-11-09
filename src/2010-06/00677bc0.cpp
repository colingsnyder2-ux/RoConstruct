// from server: 49% by atomic.potato
struct Geometry
{
    char padding0[208];
    void* handler;
    char padding1[48];
    float value;

    void setValue(float value);
};

void Geometry::setValue(float value)
{
    if (!(value == this->value))
    {
        this->value = value;
        if (this->handler)
        {
            void (__thiscall *callback)(void*) =
                (void (__thiscall *)(void*))0x699ac0;
            callback(this);
        }
    }
}
