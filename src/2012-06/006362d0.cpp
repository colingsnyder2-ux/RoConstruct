// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace G3D {
template<class T> class Array {
public:
    T* data; int num; int numAllocated;
    int size() const { return num; }
    T& operator[](int n) { return data[n]; }
};
class TextInput {
public:
    char pad[0x20];
    Array<char> buffer;
    int x2c;
    int currentCharOffset;
    int peekInputChar(int distance);
};
int TextInput::peekInputChar(int distance) {
    if ((currentCharOffset + distance) >= buffer.size()) {
        return -1;
    }
    unsigned char c = buffer[currentCharOffset + distance];
    return c;
}
}
