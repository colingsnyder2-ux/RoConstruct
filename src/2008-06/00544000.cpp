// from server: 100% by king_originala
#pragma optimize("", off)

struct VChunk;
extern char* __cdecl flagPointer(VChunk* p);

struct S {
    char pad[0x18];
    VChunk* pointer;
    int state;

    VChunk* acquire();
    char* getPointer();
    VChunk** getSecondPointer();
    char* getThirdPointer();
    void initialize();
};

void S::initialize()
{
    pointer = acquire();
    *flagPointer(pointer) = 1;
    *reinterpret_cast<VChunk**>(getPointer()) = pointer;
    *getSecondPointer() = pointer;
    *reinterpret_cast<VChunk**>(getThirdPointer()) = pointer;
    state = 0;
}
