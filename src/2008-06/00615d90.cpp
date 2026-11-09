// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client-dll roc_espeon_pickrayconstants7f4be0a0b4b3a9ea.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/Ray.h>
#include <vector>

extern "C" void* __cdecl sub_6a0920(unsigned int);
extern "C" void __cdecl sub_6a067a(void*);
extern "C" void* __cdecl sub_6a17c6(int, int, void*, void*, int);

extern char g948304[], g9516c8[];
extern const float g8439d8, g82746c;

typedef G3D::Vector3 Vec3;typedef G3D::Ray Ray;typedef std::vector<void*> Collection;

struct Subject
{
    char padding[0x1dc];
    int f1dc;
    int method();
};

struct CharacterSubject
{
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void collect(Collection*) = 0;
};

struct Camera
{
    virtual void slot0() = 0;
    virtual Subject* subject() = 0;
    void collect(Collection*);
};

extern "C" int __cdecl sub_615940(
    Ray*, void*, Collection*, void*, Vec3*, float);

struct S
{
    char padding[0x18];
    char* object;

    Ray makeRay(void*);
    int f(void*, void*, Vec3*);
};

int S::f(void* input, void* argument, Vec3* output)
{
    Ray ray = makeRay(input);

    void* context = *reinterpret_cast<void**>(
        *reinterpret_cast<char**>(object + 0x2e4) + 0x84);

    Collection collection;
    Camera* camera = object
        ? reinterpret_cast<Camera*>(object + 0x288)
        : 0;
    camera->collect(&collection);

    Subject* subject =
        reinterpret_cast<Camera*>(object + 0x288)->subject();

    if (subject)
    {
        CharacterSubject* character =
            static_cast<CharacterSubject*>(
                sub_6a17c6(subject->method(), 0,
                           g948304, g9516c8, 0));
        if (character)
            character->collect(&collection);
    }

    int result = sub_615940(
        &ray, context, &collection, argument, output, 2048.0f);

    if (!result)
    {
        *output=ray.direction*10000.0f+ray.origin;
    }

    return result;
}