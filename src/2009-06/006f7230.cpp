// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0066a730  unit: RBX::GroupDragTool  size: 143 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0066a730
//
// 0066a730  83ec0c               sub esp, 0xc
// 0066a733  56                   push esi
// 0066a734  8bf1                 mov esi, ecx
// 0066a736  807e2800             cmp byte ptr [esi + 0x28], 0
// 0066a73a  57                   push edi
// 0066a73b  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0066a73f  756c                 jne 0x66a7ad
// 0066a741  0fbf4708             movsx eax, word ptr [edi + 8]
// 0066a745  0fbf4f0a             movsx ecx, word ptr [edi + 0xa]
// 0066a749  89442418             mov dword ptr [esp + 0x18], eax
// 0066a74d  db442418             fild dword ptr [esp + 0x18]
// 0066a751  894c2418             mov dword ptr [esp + 0x18], ecx
// 0066a755  db442418             fild dword ptr [esp + 0x18]
// 0066a759  d9c9                 fxch st(1)
// 0066a75b  d86620               fsub dword ptr [esi + 0x20]
// 0066a75e  d9c9                 fxch st(1)
// 0066a760  d86624               fsub dword ptr [esi + 0x24]
// 0066a763  dcc8                 fmul st(0), st(0)
// 0066a765  d9c1                 fld st(1)
// 0066a767  deca                 fmulp st(2)
// 0066a769  dec1                 faddp st(1)
// 0066a76b  d9fa                 fsqrt 
// 0066a76d  d81d6c6e8200         fcomp dword ptr [0x826e6c]
// 0066a773  dfe0                 fnstsw ax
// 0066a775  f6c441               test ah, 0x41
// 0066a778  7533                 jne 0x66a7ad
// 0066a77a  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 0066a77d  c6462801             mov byte ptr [esi + 0x28], 1
// 0066a781  e87a36faff           call 0x60de00
// 0066a786  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 0066a789  e8f237faff           call 0x60df80
// 0066a78e  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 0066a791  57                   push edi
// 0066a792  8d54240c             lea edx, [esp + 0xc]
// 0066a796  52                   push edx
// 0066a797  e82437faff           call 0x60dec0
// 0066a79c  d900                 fld dword ptr [eax]
// 0066a79e  d95e2c               fstp dword ptr [esi + 0x2c]
// 0066a7a1  d94004               fld dword ptr [eax + 4]
// 0066a7a4  d95e30               fstp dword ptr [esi + 0x30]
// 0066a7a7  d94008               fld dword ptr [eax + 8]
// 0066a7aa  d95e34               fstp dword ptr [esi + 0x34]
// 0066a7ad  8b06                 mov eax, dword ptr [esi]
// 0066a7af  8b5008               mov edx, dword ptr [eax + 8]
// 0066a7b2  57                   push edi
// 0066a7b3  8bce                 mov ecx, esi
// 0066a7b5  ffd2                 call edx
// 0066a7b7  5f                   pop edi
// 0066a7b8  5e                   pop esi
// 0066a7b9  83c40c               add esp, 0xc
// 0066a7bc  c20400               ret 4

#pragma float_control(precise, off)

extern "C" double __cdecl sqrt(double);
#pragma intrinsic(sqrt)

struct Event {
    char padding[8];
    short x;
    short y;
};

struct Vector2 {
    float x, y;
    Vector2(float, float);
    Vector2 operator-(const Vector2&) const;
};

inline Vector2::Vector2(float a, float b) : x(a), y(b) {}

inline Vector2 Vector2::operator-(const Vector2& other) const
{
    return Vector2(x - other.x, y - other.y);
}

struct Vector3 {
    float x, y, z;
};

struct Controller {
    void begin();
    void update();
    Vector3* position(Vector3*, const Event*);
};

struct S {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void dispatch(const Event*) = 0;

    char padding[24];
    Controller* controller;
    Vector2 start;
    bool dragging;
    Vector3 dragPosition;

    void f(const Event*);
};

void S::f(const Event* event)
{
    if (!dragging) {
        Vector2 delta = Vector2((float)event->x, (float)event->y) - start;
        float distance = (float)sqrt(delta.x * delta.x + delta.y * delta.y);
        if (distance > *(const float*)0x00826e6c) {
            dragging = true;
            controller->begin();
            controller->update();
            Vector3 temporary;
            const Vector3* position = controller->position(&temporary, event);
            dragPosition.x = position->x;
            dragPosition.y = position->y;
            dragPosition.z = position->z;
        }
    }
    dispatch(event);
}
