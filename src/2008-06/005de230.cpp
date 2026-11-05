// from server: 100% by king_originala
extern "C" double __cdecl fabs(double);

struct Matrix {
    float m[3][3];
};

bool __cdecl fuzzyEqual(const Matrix& a, const Matrix& b, float tolerance)
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            double x = a.m[i][j];
            double y = b.m[i][j];
            if (x != y) {
                if (!(fabs(x - y) <= (fabs(x) + 1.0) * tolerance))
                    return false;
            }
        }
    }
    return true;
}
