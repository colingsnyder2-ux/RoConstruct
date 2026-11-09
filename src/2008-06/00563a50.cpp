// from server: 100% by king_originala
struct S {
    float value;
    char storage[128];

    S();
    ~S();
};

float f()
{
    return S().value;
}
