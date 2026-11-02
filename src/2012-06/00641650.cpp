// from server: 49% by Intel





extern "C" void* __cdecl memchr(const void* block, int c, size_t count);

struct Sphere {
    int __cdecl findIntersection(const char* rayOrigin, const char* rayDirection, int maxDistance, int tMin, int tMax, int step);
};

int Sphere::findIntersection(const char* rayOrigin, const char* rayDirection, int maxDistance, int tMin, int tMax, int step) {
    if (maxDistance < step)
        return 0;
    if (step == 0)
        return 0;

    int rayOriginEnd = (int)rayOrigin - 1;
    int v6 = tMin - rayOriginEnd;
    v6 -= step;
    v6 += maxDistance;

    unsigned char firstChar = *rayDirection;
    if (!memchr(rayOrigin, firstChar, v6))
        return 0;

    const char* searchStart = rayOrigin + 1;
    int remaining = step - 1;
    int searchLen = remaining + 1;
    const char* current = searchStart;

    while (true) {
        if (remaining >= 4) {
            do {
                if (*(int*)current != *(int*)searchStart)
                    goto mismatch;
                remaining -= 4;
                searchStart += 4;
                current += 4;
            } while (remaining >= 4);
        }

        if (remaining == 0)
            return 1;

        if (*current != *searchStart)
            goto mismatch;
        if (remaining == 1)
            return 1;

        if (current[1] != searchStart[1])
            goto mismatch;
        if (remaining == 2)
            return 1;

        if (current[2] != searchStart[2])
            goto mismatch;
        return 1;

    mismatch:
        int v13 = tMax - searchLen;
        v13 -= step;
        v13 += maxDistance;
        unsigned char nextChar = *rayDirection;
        if (!memchr(rayDirection, nextChar, v13))
            return 0;
        searchLen++;
        remaining = step - 1;
        searchStart = rayDirection + 1;
        current = searchStart;
    }
}
