// from server: 64% by atomic.potato
struct S
{
    void update();
};

extern "C" float get_value(void*);
extern "C" void set_value(float*);

void S::update()
{
    float value = get_value((char*)this + 0xC0);
    set_value(&value);
}
