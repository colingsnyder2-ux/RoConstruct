// from server: 59% by atomic.potato
extern "C" float __cdecl ReadValue(const void*);
extern "C" void __cdecl UpdateValue(void*, const float*);

struct S
{
    int value;
    void Update(float);
    float Read() const;
};

float S::Read() const
{
    return ReadValue((const char*)this + 0xa8);
}

void S::Update(float value)
{
    UpdateValue(this, &value);
}

void f(S* p)
{
    float value = p->Read();
    p->Update(value);
}
