// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

__forceinline void increment(volatile long* count)
{
    _InterlockedExchangeAdd(count, 1);
}

struct Control
{
    void* table;
    volatile long strong;
};

struct Payload
{
    void* first;
    Control* firstControl;
    void* second;
    Control* secondControl;
    int value;

    Payload(const Payload& source);
    ~Payload();
};

struct String
{
    unsigned char storage[28];
};

extern String* (__thiscall *copy_string)(String*, const String*);

struct S
{
    Payload payload;
    String text;

    S(const S& source);
};

__forceinline Payload::Payload(const Payload& source)
{
    first = source.first;
    firstControl = source.firstControl;
    if (firstControl)
        increment(&firstControl->strong);

    second = source.second;
    secondControl = source.secondControl;
    if (secondControl)
        increment(&secondControl->strong);

    value = source.value;
}

S::S(const S& source) : payload(source.payload)
{
    copy_string(&text, &source.text);
}
