// from server: 59% by king_originala
struct String {
    unsigned char storage[28];
    String(const String&);
};

struct Disposable {
    virtual ~Disposable();
};

struct Guard {
    Disposable* volatile p;
    unsigned char padding[4];
    Guard(Disposable* q) : p(q) {}
    ~Guard() {
        Disposable* q = p;
        if (q) delete q;
    }
};

struct __multiple_inheritance Receiver;
typedef void (Receiver::*Method)(String);

struct Payload {
    Disposable* first;
    Disposable* second;
    String value;
};

struct Descriptor {
    unsigned char padding[56];
    Method method;
    void invoke(Receiver*, const Payload*);
};

void Descriptor::invoke(Receiver* receiver, const Payload* payload)
{
    Guard first(payload->first);
    Guard second(payload->second);
    (receiver->*method)(payload->value);
}
