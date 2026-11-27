// from server: 100% by Xemicl
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /D_SECURE_SCL=0
#include <string>
namespace G3D {
template <class T>
class Array {
    T* data;
    int num;
    int numAllocated;
public:
    void resize(int n, bool shrinkIfNecessary = true);
    void push(const T& value);
    T* getCArray() { return data; }
    void pop(bool shrinkUnderlyingArrayIfNecessary = true) {
        resize(num - 1, shrinkUnderlyingArrayIfNecessary);
    }
};
class TextOutput {
    char pad0[0x28];
    Array<char> data;
public:
    void commitString(std::string& out);
    std::string commitString();
};
inline void TextOutput::commitString(std::string& out) {
    // Null terminate
    data.push('\0');
    out = data.getCArray();
    data.pop();
}
std::string TextOutput::commitString() {
    std::string str;
    commitString(str);
    return str;
}
}