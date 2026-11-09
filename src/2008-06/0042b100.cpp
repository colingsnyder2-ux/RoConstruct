// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct Receiver {
    void accept(std::string);
};
struct Argument {
    char reserved[16];
    char *object;
};
struct S {
    std::string *value;
    void *f(void *, Argument *);
};
void *S::f(void *result, Argument *argument)
{
    Receiver *receiver = reinterpret_cast<Receiver *>(argument->object + 8);
    receiver->accept(*value);
    return result;
}
