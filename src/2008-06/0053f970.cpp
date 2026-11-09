// from server: 100% by king_originala
#pragma optimize("", off)

struct Matrix3 {
    const float* operator[](int index) const;
};

extern bool __cdecl validValue(double value);

bool __cdecl f(const Matrix3& matrix)
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (!validValue(matrix[i][j]))
                return false;
        }
    }
    return true;
}
