// from server: 100% by atomic.potato
extern "C" int __cdecl sub_794240(int);

struct S {
    unsigned int flags;
    void setflag(int, char);
};

void S::setflag(int value, char enable) {
    if (enable) {
        flags |= sub_794240(value);
    } else {
        flags &= ~sub_794240(value);
    }
}
