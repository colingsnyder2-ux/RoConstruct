// from server: 100% by king_originala
int __cdecl sub_495e80(int, int);

struct Result {
    int data[3];
};

struct Handler {
    void invoke(Result*, int*);
};

struct Receiver {
    void invoke(int);
};

struct S {
    char padding[0x90];
    unsigned char disabled;
    char alignment[3];
    Handler handler;

    void f(int, Receiver*);
};

void S::f(int value, Receiver* receiver)
{
    if ((unsigned char)sub_495e80((int)this - 0x340, 1) && !disabled) {
        Result result;
        handler.invoke(&result, &value);
    } else {
        receiver->invoke(value);
    }
}
