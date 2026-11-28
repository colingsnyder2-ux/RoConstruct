import pefile
pe=pefile.PE('run/RobloxQT.exe')
needle=(0x645b30).to_bytes(4,'little')  # little-endian call target? calls use relative? Actually call near uses relative offset, not absolute. Hard.
# Instead search for bytes 5f b3 64 00? no.
print('done')
PY