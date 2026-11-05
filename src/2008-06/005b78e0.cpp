// from server: 100% by colin
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedExchangeAdd)

struct String;
extern String* (__thiscall *copyString)(String*, const String&);

struct String {
    char storage[28];
    String(const String&);
};

__forceinline String::String(const String& source)
{
    copyString(this, source);
}

struct Control {
    long unused;
    volatile long references;
};

struct Payload {
    String text;
    int value;
    void* object;
    Control* control;

    Payload(const Payload&);
};

__forceinline Payload::Payload(const Payload& source)
    : text(source.text),
      value(source.value),
      object(source.object),
      control(source.control)
{
    if (control) {
        volatile long* count = reinterpret_cast<volatile long*>(control);
        ++count;
        _InterlockedIncrement(count);
    }
}

struct S {
    int first;
    int second;
    int third;
    Payload payload;
    bool enabled;
    bool flag;

    S(int, int, int, const Payload&, bool);
};

S::S(int a, int b, int c, const Payload& source, bool state)
    : first(a),
      second(b),
      third(c),
      payload(source),
      enabled(state),
      flag(false)
{
}
