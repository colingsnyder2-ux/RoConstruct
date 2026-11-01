// from server: 100% by Cezant64gamejr
struct S {
    void f() {
        if (this->byteAtOffset1() != 0) {
            this->byteAtOffset1() = 0;
        }
    }

    unsigned char& byteAtOffset1() {
        return *(unsigned char*)((char*)this + 1);
    }
};

int main() {
    S s;
    s.f();
    return 0;
}
