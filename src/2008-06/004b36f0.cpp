// from server: 100% by king_originala
typedef void (__thiscall *DestructorProc)(void *);

extern DestructorProc stringDestructor;

void __stdcall destroyArray(
    void *array, unsigned int elementSize,
    int elementCount, DestructorProc destructor);

struct Base {
    char storage[32];
    ~Base();
};

struct S : Base {
    char strings[128 * 28];
    ~S();
};

S::~S()
{
    destroyArray(strings, 28, 128, stringDestructor);
}
