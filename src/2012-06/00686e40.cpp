// from server: 24% by tajop
namespace std {
    template<class T> inline const T& max(const T& a, const T& b) { return a < b ? b : a; }
    template<class T> inline const T& min(const T& a, const T& b) { return b < a ? b : a; }
}

struct Camera {
    static float distanceMin() { return 0.5f; }
    static float distanceMax() { return 1000.0f; }
    static float getNewZoomDistance(float currentDistance, float in);
};

float Camera::getNewZoomDistance(float currentDistance, float in) {
    if (in > 0.0f) {
        return std::max(currentDistance / (in * 0.25f + 1.0f), distanceMin());
    } else if (in < 0.0f) {
        return std::min((1.0f - in * 0.25f) * currentDistance, distanceMax());
    }
    return currentDistance;
}
