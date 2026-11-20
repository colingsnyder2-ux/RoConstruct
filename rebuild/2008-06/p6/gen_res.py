"""Write a .res holding the unmodified resources of the original exe.
The output is generated from the proprietary client and stays in out/."""
import struct, sys
import pefile

def name_bytes(entry):
    if entry.name is not None:
        return (str(entry.name) + "\0").encode("utf-16le")
    return struct.pack("<HH", 0xffff, entry.id)

def pad(data):
    return data + b"\0" * (-len(data) % 4)

def record(kind, name, lang, data):
    tail = struct.pack("<IHHII", 0, 0x1030, lang, 0, 0)
    head = pad(kind + name)
    size = 8 + len(head) + len(tail)
    return pad(struct.pack("<II", len(data), size) + head + tail + data)

def generate(exe, out):
    pe = pefile.PE(exe, fast_load=True)
    pe.parse_data_directories([2])
    blob = record(struct.pack("<HH", 0xffff, 0), struct.pack("<HH", 0xffff, 0), 0, b"")
    count = 0
    for kind in pe.DIRECTORY_ENTRY_RESOURCE.entries:
        for name in kind.directory.entries:
            for lang in name.directory.entries:
                entry = lang.data.struct
                blob += record(name_bytes(kind), name_bytes(name), lang.id,
                               pe.get_data(entry.OffsetToData, entry.Size))
                count += 1
    with open(out, "wb") as f:
        f.write(blob)
    return count

if __name__ == "__main__":
    print(generate(sys.argv[1], sys.argv[2]), "resources")
