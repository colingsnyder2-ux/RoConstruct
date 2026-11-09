// from server: 48% by atomic.potato
extern "C" void __cdecl Function0040C080(void);

struct S
{
    char padding[192];
    float value;

    void set(float value);
};

void S::set(float value)
{
    this->value = value;
    Function0040C080();
}
