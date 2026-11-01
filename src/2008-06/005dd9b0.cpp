// from server: 100% by king_originala
extern const float rotationMinimum;
extern const float rotationMaximum;
extern const float positionMinimum;
extern const float positionMaximum;

struct Frame {
    float rotation[3][3];
    float position[3];
};

bool validateFrame(const Frame& frame)
{
    for (int i = 0; i < 3; ++i) {
        double rotation = frame.rotation[i][i];
        for (int j = 0; j < 3; ++j) {
            if (!(rotation > rotationMinimum &&
                  rotation < rotationMaximum))
                return false;
        }

        double position = frame.position[i];
        if (!(position > positionMinimum &&
              position < positionMaximum))
            return false;
    }
    return true;
}
