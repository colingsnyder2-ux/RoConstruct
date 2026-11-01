// from server: 100% by Espeon
// from server: 88% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
struct Signal {
    void emit(float*);
};

struct Connection {
    char padding[0x10];
    Signal signal;
};

struct Registry {
    Connection* find(void*);
};

struct Primary {char data[0x14];};
struct Instance {char data[0x130];volatile float threshold;bool flag;};
struct S : Primary, Instance {

    void notify(void*);
    void f(int, float);
};

extern "C" bool __cdecl check(S*, int);

void S::f(int, float value)
{
    if (threshold > value) {
        flag = !flag;
        notify(reinterpret_cast<void*>(0x97bf64));
        if (check(this, 1)) {
            Connection* connection =
                reinterpret_cast<Registry*>(0x97bf80)->find(static_cast<Instance*>(this));
            if (connection)
                connection->signal.emit(&value);
        }
    }
}
