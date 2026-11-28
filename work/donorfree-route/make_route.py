"""Harness link glue (NOT native source): route the donor's pointer-form (PBDB) Described<>::classDescriptor()
for each class that has one native twin, to the authentic 2008 array-form (QBDB/PADA) specialization, so the donor and native halves share
one class-descriptor tree. Each thunk is a plain jmp; placed first on the link line, /FORCE:MULTIPLE keeps it over
the donor COMDAT. Delete this when the donor is gone (rbxgs uses `const char* const*` ClassName; 2008 uses arrays).

    python work/donorfree-route/make_route.py   -> work/donorfree-route/DescriptorRoute.obj
"""
import re, subprocess, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
from roc import rebuild

HERE = Path(__file__).parent
MAP = ROOT / 'rebuild/2008-06/out/native-current-audit/roblox.map'
CD = re.compile(r'^\?classDescriptor@\?\$Described@V(\w+)@RBX@@\$1\?s\w+@2@3(PBDB|QBDB|PADA)\S*@Reflection@RBX@@SAAAVClassDescriptor@23@XZ$')


def names():
    """(donor PBDB symbol, native symbol) for every class with exactly one non-PBDB (2008) classDescriptor."""
    by = {}
    for line in MAP.read_text(errors='replace').splitlines():
        parts = line.split()
        if len(parts) > 2 and CD.match(parts[1]):
            m = CD.match(parts[1])
            by.setdefault(m.group(1), set()).add(parts[1])
    out = []
    for cls, syms in sorted(by.items()):
        donor = [s for s in syms if '3PBDB' in s]
        native = [s for s in syms if '3PBDB' not in s]
        if len(donor) == 1 and len(native) == 1:
            out.append((donor[0], native[0]))
    return out


def main():
    lines = ['.386', '.model flat', 'option casemap:none']
    for donor, native in names():
        lines.append('EXTERN %s:PROC' % native)
    lines.append('_TEXT SEGMENT')
    for donor, native in names():
        lines += ['PUBLIC %s' % donor, '%s PROC' % donor, '    jmp %s' % native, '%s ENDP' % donor]
    lines += ['_TEXT ENDS', 'END', '']
    asm = HERE / 'DescriptorRoute.asm'
    asm.write_text('\n'.join(lines))
    tc = rebuild.toolchain(21022)
    code, log = rebuild.run(tc, str(rebuild._ml()), ['/nologo', '/c', '/coff', '/Fo' + str(HERE / 'DescriptorRoute.obj'), str(asm)], HERE)
    print(code, log[-800:])
    sys.exit(code)


if __name__ == '__main__':
    main()
