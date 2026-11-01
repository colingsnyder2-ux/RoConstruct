// from server: 100% by king_originala
struct String;
String* __cdecl convertNumber(String*, const double&);

struct Getter {
    virtual void slot0();
    virtual void slot1();
    virtual double get(void*);
};

struct S {
    unsigned char padding[24];
    Getter* volatile getter;
    String* convert(String*, void*);
};

String* S::convert(String* result, void* object)
{
    union {
        volatile int initial;
        double value;
    } number;

    number.initial = 0;
    number.value = getter->get(object);
    convertNumber(result, number.value);
    return result;
}
