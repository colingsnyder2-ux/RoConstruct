// from server: 74% by colin
struct KeyframeSequence {
    char pad[0xcc];
    bool loop;
    void setLoop(bool value);
};

void KeyframeSequence::setLoop(bool value) {
    if (loop != value) {
        loop = value;
        extern void __stdcall firePropertyChanged(const char*, void*);
        firePropertyChanged((const char*)0xe4a90c, (void*)0);
    }
}
