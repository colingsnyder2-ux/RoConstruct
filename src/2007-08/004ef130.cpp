// from server: 100% by colin
extern "C" bool __cdecl sub_4a00e0(double);

struct RBX_Render_SceneManager {
};

bool __cdecl method(float (*matrix)[3]) {
    int row = 0;
    while (row < 3) {
        int col = 0;
        while (col < 3) {
            if (!sub_4a00e0((double)matrix[row][col])) {
                return false;
            }
            col++;
        }
        row++;
    }
    return true;
}
