// from server: 22% by tester
struct ViewBase {
    double value1;
    double value2;
    double value3;
    void setValue(int, double);
};

void ViewBase::setValue(int index, double value) {
    switch (index) {
        case 0:
            this->value1 = value;
            break;
        case 1:
            this->value2 = value;
            break;
        case 2:
            this->value3 = value;
            break;
        default:
            // Handle invalid index
            break;
    }
}
