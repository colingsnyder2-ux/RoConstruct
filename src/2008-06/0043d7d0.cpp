// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_vectoritemnativeb17e25fc0c5c10d2.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/Vector3.h>
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// from server: 83% by king_originala
extern const unsigned int primaryTable[];
extern const unsigned int secondaryTable[];
extern const unsigned int tertiaryTable[];
extern const char axis0[];
extern const char axis1[];
extern const char axis2[];

struct Text {
    char storage[0x60];
};

extern void (__thiscall *assignText)(Text*, const char*);

struct Primary {virtual ~Primary();char padding[0x1c];};
struct Secondary {virtual ~Secondary();char padding[0x88];Text text;};
struct Tertiary {virtual ~Tertiary();char padding[0x20];};
struct PropertyItem : Primary,Secondary,Tertiary {PropertyItem(void*,int);virtual ~PropertyItem();};

struct Vector3Item : PropertyItem {
    virtual ~Vector3Item();
    int axis;
    G3D::Vector3 vector;

    Vector3Item(void* argument, int value, int selectedAxis);
};

Vector3Item::Vector3Item(void* argument, int value, int selectedAxis)
    : PropertyItem(argument, value),
      axis(selectedAxis),
      vector()
{

    switch (selectedAxis) {
    case 0:
        assignText(&text, axis0);
        break;
    case 1:
        assignText(&text, axis1);
        break;
    case 2:
        assignText(&text, axis2);
        break;
    }
}
