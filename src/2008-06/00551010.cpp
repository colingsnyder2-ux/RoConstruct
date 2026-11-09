// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
// Analog for 00551010: converts strip/quad index lists to triangle lists
// (3 = triangle strip, 5 = quads, 6 = quad strip).
template<class T>
class Array {
public:
    int size() const;
    void resize(int n);
    T& operator[](int n);
    T* data;
    int num;
    int numAllocated;
};

void triangulate(Array<int>& source, int primitive, Array<int>& triangles)
{
    do {} while (0);
    int n = source.size();
    switch (primitive) {
    case 3: {
        do {} while (0);
        triangles.resize((n - 2) * 3);
        bool flip = false;
        for (int j = 0, i = 0; j <= n - 2; ++j, i += 3) {
            if (flip) {
                triangles[i] = source[j + 1];
                triangles[i + 1] = source[j];
                triangles[i + 2] = source[j + 2];
                flip = false;
            } else {
                triangles[i] = source[j];
                triangles[i + 1] = source[j + 1];
                triangles[i + 2] = source[j + 2];
                flip = true;
            }
        }
        break;
    }
    case 5: {
        do {} while (0);
        triangles.resize((int)(n * 1.5));
        for (int j = 0, i = 0; j <= n - 4; j += 4, i += 6) {
            triangles[i] = source[j];
            triangles[i + 1] = source[j + 1];
            triangles[i + 2] = source[j + 3];
            triangles[i + 3] = source[j + 1];
            triangles[i + 4] = source[j + 2];
            triangles[i + 5] = source[j + 3];
        }
        break;
    }
    case 6: {
        do {} while (0);
        triangles.resize((n - 2) * 3);
        for (int j = 0, i = 0; j <= n - 2; j += 2, i += 6) {
            triangles[i] = source[j];
            triangles[i + 1] = source[j + 1];
            triangles[i + 2] = source[j + 2];
            triangles[i + 3] = source[j + 2];
            triangles[i + 4] = source[j + 1];
            triangles[i + 5] = source[j + 3];
        }
        break;
    }
    }
}
