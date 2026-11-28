"""python sizecheck.py [--jobs 4]: bulk LAYOUT check -- the true object size of every RBX class (the original allocates
it: `push N; call operator new/malloc` followed by that class's constructor, or a constructor that stores its
primary vtable) against sizeof(RBX::C) from the NATIVE headers (one tiny compile per class, run in parallel; the
compiler error for `char (*)[sizeof(C)] = 0` prints the size). A smaller native class means converted code writes
past the native object (heap corruption); a larger one shifts every field after the mismatch.
Writes auto/sizecheck.json [{class, orig, native, header}]."""
import collections, concurrent.futures as cf, json, re, sys
from pathlib import Path
import capstone, pefile
H = Path(__file__).parent
ROOT = H.parents[1]
sys.path.insert(0, str(ROOT)); sys.path.insert(0, str(ROOT / 'rebuild/2008-06/tests'))
from roc import rebuild
import native_check_runner as ncr
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
o = pefile.PE(str(ROOT / 'clients/2008-06/Roblox.exe'), fast_load=True).get_memory_mapped_image()
reg = json.load(open(ROOT / 'work/2008-06/identity-registry.json'))
B = 0x400000
name = lambda a: (reg.get('%08x' % a) or {}).get('name') or ''


def vt_class(t):
    for j in md.disasm(bytes(o[t - B:t - B + 0x80]), t):
        if j.mnemonic == 'mov' and j.op_str.startswith(('dword ptr [esi], 0x', 'dword ptr [eax], 0x', 'dword ptr [ecx], 0x', 'dword ptr [edi], 0x')):
            m = re.match(r'^\?\?_7(\w+)@RBX@@6B@$', name(int(j.op_str.split(', ')[1], 16)))
            return m.group(1) if m else None
        if j.mnemonic == 'ret':
            return None


sizes = collections.defaultdict(collections.Counter)
ff = sorted(int(a, 16) for a in json.load(open(ROOT / 'work/native-client/layout/function-files.json')))
for a in ff:
    if not 0x401000 <= a < 0x7c0000:
        continue
    pend = None
    for i in md.disasm(bytes(o[a - B:a - B + 0x180]), a):
        if i.mnemonic == 'push' and i.op_str.startswith('0x') and 8 <= int(i.op_str, 16) < 0x4000:
            pend = int(i.op_str, 16)
        elif i.mnemonic == 'call' and pend:
            t = int(i.op_str, 16) if i.op_str.startswith('0x') else None
            n = name(t) if t else ('malloc' if 'ptr' in i.op_str else '')
            if 'malloc' in n or n.startswith('??2@') or '0x8028b0' in i.op_str:
                # the next constructor call after the allocation names the class
                for k in md.disasm(bytes(o[i.address + 5 - B:i.address + 5 - B + 0x40]), i.address + 5):
                    if k.mnemonic == 'call' and k.op_str.startswith('0x'):
                        c = re.match(r'^\?\?0(\w+)@RBX@@QAE@XZ$', name(int(k.op_str, 16)))
                        cls = c.group(1) if c else vt_class(int(k.op_str, 16))
                        if cls:
                            sizes[cls][pend] += 1
                        break
                pend = None
        if i.mnemonic in ('ret', 'int3'):
            break
HDR = {}
for h in (ROOT / 'rebuild/2008-06/native-headers').rglob('*.h'):
    if any(seg in h.parts for seg in ('creatable-n-params', 'nullable-class-name')):
        continue
    for m in re.finditer(r'^\s*class\s+(\w+)\s*(?::|\{|$)', h.read_text(errors='replace'), re.M):
        HDR.setdefault(m.group(1), h.relative_to(ROOT / 'rebuild/2008-06/native-headers').as_posix())
tc = rebuild.toolchain(21022)
work = H / 'linkexp/sizecheck'; work.mkdir(exist_ok=True)


def native_size(c):
    src = work / ('sz_%s.cpp' % c)
    src.write_text('// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS\n#include "util/Object.h"\n'
                   '#include "%s"\nchar (*roc_sz)[sizeof(RBX::%s)] = 1;\n' % (HDR[c], c))
    code, text = rebuild.run(tc, 'cl', ncr.compiler_flags(src) + ['/c', '/Fo' + str(work / ('sz_%s.obj' % c)), str(src)], work)
    m = re.search(r'char \(\*\)\[(\d+)\]', text)
    return c, (int(m.group(1)) if m else None), (None if m else (re.findall(r'error C\d+:[^\n]*', text) or [''])[0][:100])


todo = [c for c in sizes if c in HDR]
res = []
with cf.ThreadPoolExecutor(int(sys.argv[sys.argv.index('--jobs') + 1]) if '--jobs' in sys.argv else 4) as ex:
    for c, n, err in ex.map(native_size, todo):
        orig = sizes[c].most_common(1)[0][0]
        res.append({'class': c, 'orig': orig, 'orig_all': dict(sizes[c]), 'native': n, 'header': HDR[c], 'err': err})
bad = [r for r in res if r['native'] is not None and r['native'] != r['orig']]
(H / 'auto/sizecheck.json').write_text(json.dumps(res, indent=0))
print('sizecheck: classes with original sizes %d, with native headers %d, compiled %d, SIZE MISMATCH %d'
      % (len(sizes), len(todo), sum(1 for r in res if r['native']), len(bad)))
for r in sorted(bad, key=lambda r: r['native'] - r['orig']):
    print('  %-28s orig %#5x native %#5x (%+d) %s' % (r['class'], r['orig'], r['native'], r['native'] - r['orig'], r['header']))
