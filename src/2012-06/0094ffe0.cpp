// from server: 30% by Intel
struct Vector3 {
    float x, y, z;
};

struct Matrix3x3 {
    Vector3 rows[3];
};

struct Transform {
    Matrix3x3 rotation;
    Vector3 translation;
};

extern "C" void __cdecl sub_94FA70(void* ecx, void* edx);

Transform* __cdecl sub_94FFE0(Transform* first, Transform* last, Transform* dest, void* arg3) {
    if (first == last) {
        return dest;
    }

    Transform* currentSrc = first;
    Transform* currentDest = dest;

    do {
        currentDest->rotation.rows[0] = currentSrc->rotation.rows[0];

        sub_94FA70(&currentDest->rotation.rows[1], &currentSrc->rotation.rows[1]);

        currentDest->rotation.rows[1].z = currentSrc->rotation.rows[1].z;
        currentDest->rotation.rows[2].z = currentSrc->rotation.rows[2].z;
        currentDest->rotation.rows[2].x = currentSrc->rotation.rows[2].x;
        currentDest->rotation.rows[2].y = currentSrc->rotation.rows[2].y;

        currentSrc = reinterpret_cast<Transform*>(reinterpret_cast<char*>(currentSrc) + 0x28);
        currentDest = reinterpret_cast<Transform*>(reinterpret_cast<char*>(currentDest) + 0x28);
    } while (currentSrc != last);

    return currentDest;
}
