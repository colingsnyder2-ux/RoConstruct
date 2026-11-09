// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
namespace G3D {
template<class T> class Array {
public:
    int num;
    int numAllocated;
    T* data;
    T& operator[](int n);
};
template<class T> T& Array<T>::operator[](int n) { return data[n]; }
struct P8{int a,b;};
template class Array<P8>;
}
