// from server: 100% by king_originala
struct Target {
    char padding[0x1d0];
    double timestamp;
};

struct Result {
    char padding[0x1a0];
    Target* target;
};

struct Input {
    Result* get();
};

extern "C" int __cdecl check(Target*);
extern "C" double __cdecl timeNow();

void __cdecl update(Input* input)
{
    Result* result = input->get();
    if (result) {
        Target* target = result->target;
        if (target && check(target))
            target->timestamp = timeNow();
    }
}
