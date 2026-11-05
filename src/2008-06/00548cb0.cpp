// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
// Analog for 00548cb0 (G3D VAR setup for the slot arrays of 00548000): drains
// glGetError, creates a vertex area (004763d0) sized for the slots and uploads
// each array into its global VAR (ctors 00502910/00551400, assign 00502ab0).
extern "C" __declspec(dllimport) unsigned __stdcall glGetError(void);

template<class T>
class Array {
public:
    int size() const;
    T* data;
    int num;
    int numAllocated;
};

template<class T>
class Ref {
public:
    Ref(const Ref& other);
    ~Ref();
    T* pointer;
};

class VARArea {
public:
    static Ref<VARArea> create(unsigned size, int hint);
};

class VAR {
public:
    template<class T> VAR(const Array<T>& source, Ref<VARArea> area);
    VAR& operator=(const VAR& other);
    ~VAR();
    Ref<VARArea> area;
    int type;
    unsigned elementSize;
    unsigned numElements;
    unsigned __int64 generation;
    void* pointer;
    unsigned maxSize;
};

class Vec3 { public: float x, y, z; };
class Vec2 { public: float x, y; };

extern bool sharedDisabled;
extern Array<Vec3> slotFirst;
extern Array<Vec3> slotSecond;
extern Array<Vec2> slotThird;
extern Array<Vec3> slotFourth;
extern VAR vertexProgram;
extern VAR pixelProgram;
extern VAR stageZero;
extern VAR stageTwo;

void initializeShared()
{
    if (!sharedDisabled)
        return;
    unsigned err = glGetError();
    while (err != 0)
        err = glGetError();
    Ref<VARArea> area = VARArea::create(slotFirst.size() * 0x2c + 0x400, 0);
    vertexProgram = VAR(slotFirst, area);
    pixelProgram = VAR(slotSecond, area);
    stageZero = VAR(slotThird, area);
    stageTwo = VAR(slotFourth, area);
    sharedDisabled = false;
}
