namespace RBX { extern int httpTransportMode; }

void nativeSetOutputMode(int mode)
{
    RBX::httpTransportMode = mode;
}
