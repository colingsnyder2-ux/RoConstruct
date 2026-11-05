// from server: 100% by colin
// from server: 98% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_boxvectorarray3c9645955c3903c4.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise, off)

extern const unsigned char table[];

struct Vector3 {
    float x, y, z;
    Vector3():x(0),y(0),z(0){}
};

struct S {
    virtual ~S();
    Vector3 v[8];

    S(const Vector3& a, const Vector3& b);
};

S::S(const Vector3& a, const Vector3& b) {

    v[0].x = v[1].x = v[2].x = v[3].x = b.x;
    v[4].x = v[5].x = v[6].x = v[7].x = a.x;
    v[0].y = v[1].y = v[4].y = v[5].y = b.y;
    v[2].y = v[3].y = v[6].y = v[7].y = a.y;
    v[0].z = v[2].z = v[4].z = v[6].z = b.z;
    v[1].z = v[3].z = v[5].z = v[7].z = a.z;
}
