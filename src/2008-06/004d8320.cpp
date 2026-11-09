// from server: 100% by EspClaude
// from server: 64% by colin
// roc 2008-06 004d8320  unit: RBX::RenderBase::SimpleSceneManager  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004d8320
// 004d8320  8b4904               mov ecx, dword ptr [ecx + 4]
struct T {
    int v;
    T& operator=(T other);
    bool operator==(const T& o) const { return v == o.v; }
};

struct Array {
    T* data;
    int num;
    int size() const { return num; }
    void resize(int n, bool shrinkIfNecessary);
    void resize(int n) { resize(n, true); }
    int findIndex(const T& value) const {
        for (int i = 0; i < num; ++i) {
            if (data[i] == value)
                return i;
        }
        return -1;
    }
    void fastRemove(int index) {
        data[index] = data[num - 1];
        resize(size() - 1);
    }
};

struct Outer {
    char pad[8];
    Array arr;
};

struct S {
    char pad[4];
    Outer* outer;
    void f(const T& value);
};

void S::f(const T& value)
{
    outer->arr.fastRemove(outer->arr.findIndex(value));
}
