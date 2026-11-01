// from server: 100% by colin
// from server: 98% by king_originala
// roc 2008-06 005032a0  unit: RBX::Render::RenderScene  size: 308 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005032a0
//
// 005032a0  83ec28               sub esp, 0x28
// 005032a3  53                   push ebx
// 005032a4  55                   push ebp
// 005032a5  56                   push esi
// 005032a6  8bf1                 mov esi, ecx
// 005032a8  8d9e90010000         lea ebx, [esi + 0x190]
// 005032ae  57                   push edi
// 005032af  8bcb                 mov ecx, ebx
// 005032b1  895c2410             mov dword ptr [esp + 0x10], ebx
// 005032b5  e836ea0000           call 0x511cf0
// 005032ba  8b6c2440             mov ebp, dword ptr [esp + 0x40]
// 005032be  6a00                 push 0
// 005032c0  6a00                 push 0
// 005032c2  8bcd                 mov ecx, ebp
// 005032c4  e8f7f2ffff           call 0x5025c0
// 005032c9  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 005032cd  6a00                 push 0
// 005032cf  6a00                 push 0
// 005032d1  e8dad2f7ff           call 0x4805b0
// 005032d6  8b7c2444             mov edi, dword ptr [esp + 0x44]
// 005032da  8d44242c             lea eax, [esp + 0x2c]
// 005032de  50                   push eax
// 005032df  8bcf                 mov ecx, edi
// 005032e1  e8aa150100           call 0x514890
// 005032e6  d94008               fld dword ptr [eax + 8]
// 005032e9  d94004               fld dword ptr [eax + 4]
// 005032ec  8d4c2414             lea ecx, [esp + 0x14]
// 005032f0  d900                 fld dword ptr [eax]
// 005032f2  51                   push ecx
// 005032f3  dcc8                 fmul st(0), st(0)
// 005032f5  8bcd                 mov ecx, ebp
// 005032f7  d9c1                 fld st(1)
// 005032f9  deca                 fmulp st(2)
// 005032fb  dec1                 faddp st(1)
// 005032fd  d9c1                 fld st(1)
// 005032ff  deca                 fmulp st(2)
// 00503301  dec1                 faddp st(1)
// 00503303  d9fa                 fsqrt 
// 00503305  d9e8                 fld1 
// 00503307  def1                 fdivrp st(1)
// 00503309  d9c0                 fld st(0)
// 0050330b  d808                 fmul dword ptr [eax]
// 0050330d  d94004               fld dword ptr [eax + 4]
// 00503310  d8ca                 fmul st(2)
// 00503312  d94008               fld dword ptr [eax + 8]
// 00503315  decb                 fmulp st(3)
// 00503317  d9c9                 fxch st(1)
// 00503319  d9e0                 fchs 
// 0050331b  d9c9                 fxch st(1)
// 0050331d  d9e0                 fchs 
// 0050331f  d9ca                 fxch st(2)
// 00503321  d9e0                 fchs 
// 00503323  d9442450             fld dword ptr [esp + 0x50]
// 00503327  dcca                 fmul st(2), st(0)
// 00503329  d9ca                 fxch st(2)
// 0050332b  d95c2418             fstp dword ptr [esp + 0x18]
// 0050332f  d9ca                 fxch st(2)
// 00503331  d8c9                 fmul st(1)
// 00503333  d95c241c             fstp dword ptr [esp + 0x1c]
// 00503337  dec9                 fmulp st(1)
// 00503339  d95c2420             fstp dword ptr [esp + 0x20]
// 0050333d  e80efcffff           call 0x502f50
// 00503342  8d54242c             lea edx, [esp + 0x2c]
// 00503346  52                   push edx
// 00503347  8bcf                 mov ecx, edi
// 00503349  e842150100           call 0x514890
// 0050334e  d94008               fld dword ptr [eax + 8]
// 00503351  d94004               fld dword ptr [eax + 4]
// 00503354  d900                 fld dword ptr [eax]
// 00503356  dcc8                 fmul st(0), st(0)
// 00503358  d9c1                 fld st(1)
// 0050335a  deca                 fmulp st(2)
// 0050335c  dec1                 faddp st(1)
// 0050335e  d9c1                 fld st(1)
// 00503360  deca                 fmulp st(2)
// 00503362  dec1                 faddp st(1)
// 00503364  d9fa                 fsqrt 
// 00503366  d9e8                 fld1 
// 00503368  def1                 fdivrp st(1)
// 0050336a  d94004               fld dword ptr [eax + 4]
// 0050336d  d8c9                 fmul st(1)
// 0050336f  d94008               fld dword ptr [eax + 8]
// 00503372  d8ca                 fmul st(2)
// 00503374  33ff                 xor edi, edi
// 00503376  39be9c020000         cmp dword ptr [esi + 0x29c], edi
// 0050337c  d900                 fld dword ptr [eax]
// 0050337e  decb                 fmulp st(3)
// 00503380  d9ca                 fxch st(2)
// 00503382  d95c2420             fstp dword ptr [esp + 0x20]
// 00503386  d95c2424             fstp dword ptr [esp + 0x24]
// 0050338a  d95c2428             fstp dword ptr [esp + 0x28]
// 0050338e  7e33                 jle 0x5033c3
// 00503390  33db                 xor ebx, ebx
// 00503392  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 00503396  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 0050339a  8b8698020000         mov eax, dword ptr [esi + 0x298]
// 005033a0  51                   push ecx
// 005033a1  55                   push ebp
// 005033a2  52                   push edx
// 005033a3  8d4c242c             lea ecx, [esp + 0x2c]
// 005033a7  03c3                 add eax, ebx
// 005033a9  51                   push ecx
// 005033aa  8b4840               mov ecx, dword ptr [eax + 0x40]
// 005033ad  50                   push eax
// 005033ae  e89d5c0400           call 0x549050
// 005033b3  47                   inc edi
// 005033b4  83c344               add ebx, 0x44
// 005033b7  3bbe9c020000         cmp edi, dword ptr [esi + 0x29c]
// 005033bd  7cd3                 jl 0x503392
// 005033bf  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 005033c3  8bcb                 mov ecx, ebx
// 005033c5  e826ea0000           call 0x511df0
// 005033ca  5f                   pop edi
// 005033cb  5e                   pop esi
// 005033cc  5d                   pop ebp
// 005033cd  5b                   pop ebx
// 005033ce  83c428               add esp, 0x28
// 005033d1  c21400               ret 0x14

extern "C" double __cdecl sqrt(double);
#pragma intrinsic(sqrt)
#pragma float_control(precise, off)

struct Vector3 {
    float x, y, z;
    Vector3();
    Vector3(float, float, float);
};

__forceinline Vector3::Vector3() {}
__forceinline Vector3::Vector3(float a, float b, float c)
    : x(a), y(b), z(c) {}

struct Stopwatch {
    unsigned char storage[0x108];
    void start();
    void stop();
};

struct VectorArray {
    void clear(int, int);
    void append(const Vector3&);
};

struct OtherArray {
    void clear(int, int);
};

struct Camera {
    const Vector3& direction(Vector3&);
};

struct Entry;

struct Processor {
    void process(Entry*, const Vector3&, OtherArray*, VectorArray*, void*);
};

struct Entry {
    unsigned char storage[0x40];
    Processor* processor;
};

struct Scene {
    unsigned char padding[0x190];
    Stopwatch stopwatch;
    Entry* entries;
    int count;

    void render(OtherArray*, VectorArray*, Camera*, void*, float);
};

void Scene::render(OtherArray* other, VectorArray* vectors,
                   Camera* camera, void* context, float distance)
{
    stopwatch.start();
    vectors->clear(0, 0);
    other->clear(0, 0);

    Vector3 temporary;
    {
        const Vector3& direction = camera->direction(temporary);
        float inverseLength = (float)(1.0 / sqrt(
            direction.x * direction.x +
            direction.y * direction.y +
            direction.z * direction.z));

        Vector3 normalized(direction.x * inverseLength,
                           direction.y * inverseLength,
                           direction.z * inverseLength);
        Vector3 negative(-normalized.x, -normalized.y, -normalized.z);
        Vector3 displacement(negative.x * distance,
                             negative.y * distance,
                             negative.z * distance);
        vectors->append(displacement);
    }

    const Vector3& direction = camera->direction(temporary);
    double inverseLength = 1.0 / sqrt(
        direction.x * direction.x +
        direction.y * direction.y +
        direction.z * direction.z);

    Vector3 unitDirection(direction.x * inverseLength,
                          direction.y * inverseLength,
                          direction.z * inverseLength);

    for (int i = 0; i < count; ++i) {
        Entry* entry = entries + i;
        entry->processor->process(entry, unitDirection, other, vectors, context);
    }

    stopwatch.stop();
}
