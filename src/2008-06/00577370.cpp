// from server: 100% by king_originala
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
inline void __cdecl operator delete(void*, void*) {}

struct StringPair {
    char storage[56];
    StringPair(const StringPair&);
};

struct Value {
    int first;
    StringPair second;
};

void __cdecl construct(Value* volatile destination, const Value& source)
{
    new (static_cast<void*>(destination)) Value(source);
}
