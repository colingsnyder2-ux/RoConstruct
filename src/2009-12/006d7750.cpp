// from server: 79% by atomic.potato
struct LaserTool {
    unsigned int next;
    void set(unsigned int value);
};

void LaserTool::set(unsigned int value) {
    unsigned int current = next;
    unsigned int node;
    if (current != 0 && current <= value) {
        node = current;
        current = *reinterpret_cast<unsigned int *>(node);
        if (current != 0 && current <= value) {
            node = current;
            do {
                current = *reinterpret_cast<unsigned int *>(node);
                if (current == 0 || current > value)
                    break;
                node = current;
            } while (true);
        }
        current = *reinterpret_cast<unsigned int *>(node);
    } else {
        node = reinterpret_cast<unsigned int>(this);
    }
    *reinterpret_cast<unsigned int *>(value) = current;
    *reinterpret_cast<unsigned int *>(node) = value;
}
