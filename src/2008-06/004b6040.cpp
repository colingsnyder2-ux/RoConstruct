// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct Result {
    void *object;
};

struct Signal {
    Result invoke(std::string text, int value);
};

struct Object {
    unsigned char padding[16];
    Signal signal;
};

extern Object *__stdcall resolve(void *object);

void __stdcall dispatch(void *object, std::string text, int value) {
    Object *resolved = resolve(object);
    if (resolved)
        resolved->signal.invoke(text, value);
}
