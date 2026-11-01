// from server: 100% by colin
void* __cdecl operator new(unsigned int);
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
inline void __cdecl operator delete(void*, void*) {}

struct Pointer {
    int* value;
    void* count;

    Pointer();
    ~Pointer();
    void reset(int*);
};

struct Header {
    Pointer pointer;
    bool flag;

    Header();
};

__forceinline Pointer::Pointer() : value(0), count(0) {}

__forceinline Header::Header() : pointer(), flag(false) {
    pointer.reset(new int(1));
}

void __cdecl construct_header(char* p) {
    Header* h = p ? (Header*)(p - 12) : 0;
    new (h) Header;
}
