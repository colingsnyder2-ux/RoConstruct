// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct Receiver {
    void write(std::string value, unsigned char flag);
};
struct Argument {
    unsigned char padding[16];
    unsigned char* object;
};
struct Value {
    std::string text;
    unsigned char flag;
};
struct S {
    Value* value;
    void* f(void* result, Argument* argument);
};
void* S::f(void* result, Argument* argument)
{
    Receiver* receiver = reinterpret_cast<Receiver*>(argument->object + 8);
    receiver->write(value->text, value->flag);
    return result;
}
