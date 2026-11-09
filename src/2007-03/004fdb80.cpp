// from server: 100% by tester
struct Camera {
    char pad[0x4c];
    int m_field4c;
    void method();
};

void __stdcall sub_508780(int);

void Camera::method() {
    sub_508780(m_field4c + 1);
}
