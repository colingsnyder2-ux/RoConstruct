// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct S;

struct T {
    char storage[0x8c];
    T(int, S*);
};

struct S {
    T* data;
    int count;
    int field08;
    int field0c;
    int field10;

    S(int);
};

S::S(int n)
{
    T* p = new T(n, this);
    count = n;
    data = p;
    field0c = 0;
    field10 = 0;
    field08 = 0;
}
