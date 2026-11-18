"""Vendor twins -> the unit and symbol the binary really holds.

A remaining function whose mined source replays a vendor unit (`// roc-lib: <recipe> <unit>`) is often only a
masked-byte TWIN of that unit's function: same code shape, other class (another ctor / CreateObject / atexit stub).
The prover then says REJECTED (bytes equal, references differ).  The binary says which class it is: the vftables the
body installs carry RTTI (research-twins/evidence.json "rtti").  For each such address this script
  A. looks in the proved wrapper for the byte-equal symbol whose vftable references undecorate to exactly that RTTI
     class, binds it with root_ref_bind.py (the prover still compares bytes, relocations and referenced data) and
     proves again;
  B. when the wrapper's unit has no such symbol, writes vendor_i wrappers (same format as vendor_i.py: the recipe's
     preprocessed unit, mined flags + /Gy) for the units of the same library that define that class, and repeats A.
No name is guessed: a symbol is bound only when it is the ONE byte-equal symbol of the unit that installs every
vftable the image's RTTI names for that address.

  python work/native-client/vendor_retarget.py [--only ADDR,ADDR] [--recipe SUBSTR] [--budget SECONDS] [--no-new-units]
Results: work/native-client/vendor-retarget.json {addr: {status, symbol, wrapper, tried}} (resumable; delete a row to retry)."""
import argparse
import json
import os
import re
import subprocess
import sys
import time
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.path.insert(0, str(HERE))
sys.path.insert(0, str(ROOT))
import agent_prove  # noqa: E402
import root_ref_bind  # noqa: E402
from roc import libs  # noqa: E402
from roc.native_bulk import Targets  # noqa: E402

UNDNAME = ROOT / 'tools/vc2008rtm/Program Files/Microsoft Visual Studio 9.0/VC/bin/undname.exe'
VENDOR_I = ROOT / 'rebuild/2008-06/native-classes/vendor_i'
DONE = HERE / 'vendor-retarget.json'
# The binary holds XTP 11.2.2; a 15.2.1 twin names the same class in the 11.2.2 tree.
SAME_TREE = {'xtp-15.2.1-shared-mfc': 'xtp-11.2.2-shared-mfc'}
XTP_CONFIGS = ['xtp-11.2.2-shared-mfc', 'xtp-11.2.2-lib-strlen', 'xtp-11.2.2']     # same tree, other MFC configuration
RANK = ['EXACT', 'REFERENCES UNPROVEN', 'AMBIGUOUS RTTI SYMBOL', 'REJECTED', 'NO RTTI SYMBOL', 'DIFF', 'COMPILE FAILED', 'RETRY LATER', 'NOT PROVED', 'NO WRAPPER']
_targets = None


def norm(name):
    """'class A::B [subobject +32]' / "const A::B::`vftable'{for `C'}" -> 'A::B' (keywords and spaces dropped)."""
    name = re.sub(r"\s*\[subobject.*$|::`vftable'.*$|^const ", '', name.strip())
    return re.sub(r'\b(class|struct|union|enum)\s+|\s+', '', name)


def undname(symbols):
    out = subprocess.run([str(UNDNAME)] + list(symbols), capture_output=True, text=True).stdout
    return dict(zip(symbols, [line[6:].strip().strip('"') for line in out.splitlines() if line.startswith('is :- ')]))


def remaining_rows():
    """{addr: {recipe, unit, flags, cl, wrappers, rtti}} for remaining roc-lib functions with RTTI evidence."""
    remaining = json.loads((HERE / 'remaining-classified.json').read_text())
    evidence = json.loads((HERE / 'research-twins/evidence.json').read_text())
    wrappers = {}
    for base in ('donor_i', 'vendor_i'):
        for path in (ROOT / 'rebuild/2008-06/native-classes' / base).rglob('*.cpp'):
            for addr in set(re.findall(r'\b00[0-9a-f]{6}\b', path.read_text(errors='replace')[:40000])):
                wrappers.setdefault(addr, []).append(path)
    rows = {}
    for addr in remaining:
        source = ROOT / 'src/2008-06' / (addr + '.cpp')
        text = source.read_text(errors='replace')[:3000] if source.is_file() else ''
        lib = re.search(r'^// roc-lib: (\S+)[ \t]+(\S.*)$', text, re.M)
        rtti = {norm(r) for r in (evidence.get(addr) or {}).get('rtti', [])}
        if not lib or not rtti or lib.group(1) not in libs.RECIPES:
            continue
        if lib.group(1).startswith(('rbxgs', 'openrbx')):
            continue     # donor (Roblox) trees are another era's source: their class names are not evidence here
        flags = re.search(r'^// roc-flags: (.*)$', text, re.M)
        cl = re.search(r'^// roc-cl: (\d+)', text, re.M)
        rows[addr] = dict(recipe=lib.group(1), unit=lib.group(2).strip().replace('\\', '/'), rtti=rtti,
                          flags=flags.group(1).strip() if flags else '', cl=int(cl.group(1)) if cl else 21022,
                          wrappers=sorted(wrappers.get(addr, [])))
    return rows


def rtti_symbols(wrapper, addr, rtti):
    """Byte-equal symbols of the proved WRAPPER at ADDR whose vftable references include every RTTI class of ADDR."""
    global _targets
    out = HERE / 'prove-out' / ('prove-' + Path(wrapper).stem)
    try:
        family = json.loads((out / 'manifest.json').read_text(encoding='utf-8'))['families'][0]
        rows = family['symbols']
        raw = root_ref_bind.proved_object(out, family).read_bytes()
    except (OSError, ValueError, KeyError, IndexError):
        return []
    _targets = _targets or Targets('2008-06')
    hits = []
    for row in rows:
        if not any(q.get('addr') == addr for q in row.get('rejections') or []) or row['symbol'].startswith('__'):
            continue
        found = {}
        try:
            root_ref_bind.reachable(raw, row['symbol'], int(addr, 16), row['size'], _targets, found)
        except Exception:  # noqa: BLE001 - an unreadable symbol is simply not a hit
            continue
        tables = [name for name in found if name.startswith('??_7')]
        classes = {norm(text) for text in undname(tables).values()} if tables else set()
        if rtti <= classes:       # every vftable the image's RTTI names at ADDR is installed by this symbol
            hits.append(row['symbol'])
    return hits


def settle(wrapper, addr, rtti):
    """prove -> bind the RTTI-proven symbol -> prove (references are listed once the symbol is bound) -> ..."""
    status, text, symbol = 'NOT PROVED', '', ''
    for _ in range(3):
        status, text = agent_prove.verdict(wrapper, {addr: ''})[addr]
        if status != 'REJECTED':
            break
        hits = rtti_symbols(wrapper, addr, rtti)
        if len(hits) != 1:
            return 'NO RTTI SYMBOL' if not hits else 'AMBIGUOUS RTTI SYMBOL', text[:300], ''
        symbol = hits[0]
        why = ('the body at %s installs the vftable(s) whose RTTI in the image is %s (research-twins/evidence.json); '
               '%s is the only byte-equal symbol of this vendor unit that installs exactly those' % (
                   addr, ' + '.join(sorted(rtti)), symbol[:100]))
        bound = agent_prove.run([sys.executable, str(HERE / 'root_ref_bind.py'), str(wrapper), '%s=%s' % (addr, symbol),
                                 '--why', why])
        if 'bound' not in bound:
            return 'REFERENCES UNPROVEN', bound.strip()[-300:], symbol
    return status, text[:300], symbol or (text if status == 'EXACT' else '')


def class_units(recipe, rtti):
    """Library .cpp files (relative paths) that define the RTTI class: best first."""
    leaves = set()
    for name in rtti:
        for part in re.findall(r'[A-Za-z_]\w*', name):
            if len(part) > 4:
                leaves.update({part, re.sub(r'(Factory|Data)$', '', part)})    # IMPLEMENT_THEME_FACTORY(x) -> xFactory
    folder = libs.fetch(recipe).resolve()
    scored = []
    for path in folder.rglob('*.cpp'):
        if path.name.startswith('roc_'):       # miners' generated units are not library source
            continue
        text = path.read_text(errors='replace')
        score = sum(3 * len(re.findall(r'\b%s::' % leaf, text)) + len(re.findall(r'\b%s\b' % leaf, text)) for leaf in leaves)
        if score:
            scored.append((-score, path.relative_to(folder).as_posix()))
    return [rel for _, rel in sorted(scored)[:3]]


def write_wrapper(recipe, rel, flags, build, addr):
    """Same wrapper as vendor_i.py writes (preprocessed unit of the recipe, mined flags + /Gy); None when unbuildable."""
    flat = rel.replace('/', '__')
    stem = re.sub(r'[^A-Za-z0-9_.-]', '_', flat.rsplit('.', 1)[0])
    wrapper = VENDOR_I / recipe / ('%s__%s.cpp' % (stem, re.sub(r'[^0-9A-Za-z]', '', flags)[:12]))
    if wrapper.is_file():
        return wrapper
    try:
        libs.unit(recipe, rel, build)
    except Exception as error:  # noqa: BLE001 - one unbuildable unit must not stop the batch
        print('   preprocess failed', recipe, rel, str(error)[:160], flush=True)
        return None
    cache = next(iter(sorted((ROOT / 'work/libcache' / recipe / str(build)).glob(flat + '*.i'))), None)
    if not cache:
        return None
    wrapper.parent.mkdir(parents=True, exist_ok=True)
    wrapper.write_text('// native-profile: vendor\n// native-flags: %s /Gy\n'
                       '// 2008-06 native vendor unit (inactive): %s unit %s, preprocessed as mined (roc/libs.py unit(), roc-cl %s;\n'
                       '// local cache - regenerate with work/native-client/vendor_retarget.py). RTTI-retargeted twin: %s\n'
                       '#include "%s"\n' % (flags, recipe, rel, build, addr,
                                            os.path.relpath(cache, wrapper.parent).replace('\\', '/')))
    return wrapper


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--only', default='')
    ap.add_argument('--recipe', default='')
    ap.add_argument('--budget', type=float, default=450)
    ap.add_argument('--no-new-units', action='store_true')
    args = ap.parse_args()
    done = json.loads(DONE.read_text()) if DONE.is_file() else {}
    start = time.time()
    for addr, row in sorted(remaining_rows().items(), key=lambda kv: (kv[1]['recipe'], kv[1]['unit'])):
        if (args.only and addr not in args.only.split(',')) or args.recipe not in row['recipe'] or addr in done:
            continue
        if time.time() - start > args.budget:
            break
        tried, result = [], ('NO WRAPPER', '', '')
        for wrapper in row['wrappers'][:1]:
            result = settle(wrapper, addr, row['rtti'])
            tried.append([wrapper.relative_to(ROOT).as_posix(), result[0]])
        recipe = SAME_TREE.get(row['recipe'], row['recipe'])
        if result[0] != 'EXACT' and not args.no_new_units:
            if not class_units(recipe, row['rtti']) and all(name.startswith('CXT') for name in row['rtti']):
                recipe = XTP_CONFIGS[0]   # a Codejock class whose body is a twin of an MFC/other vendor function
            # Bytes equal but vftable slots at other addresses = the unit was preprocessed for another MFC
            # configuration (static / shared / _LIB): the same units are then tried under the tree's other recipes.
            configs = [recipe] + [c for c in XTP_CONFIGS if c != recipe and recipe in XTP_CONFIGS]
            for config in configs:
                if config != recipe and result[0] not in ('REFERENCES UNPROVEN', 'REJECTED'):
                    break
                for rel in class_units(config, row['rtti']):
                    if rel == row['unit'] and config == row['recipe']:
                        continue
                    wrapper = write_wrapper(config, rel, row['flags'], row['cl'], addr)
                    if not wrapper:
                        continue
                    attempt = settle(wrapper, addr, row['rtti'])
                    tried.append([wrapper.relative_to(ROOT).as_posix(), attempt[0]])
                    if RANK.index(attempt[0]) < RANK.index(result[0]):
                        result = attempt                     # report the attempt that got furthest
                    if result[0] == 'EXACT':
                        break
                if result[0] == 'EXACT':
                    break
        done[addr] = dict(status=result[0], symbol=result[2][:200], detail=result[1], rtti=sorted(row['rtti']), tried=tried)
        DONE.write_text(json.dumps(done, indent=1))
        print(addr, result[0], '|', ' + '.join(sorted(row['rtti']))[:70], '|', result[2][:70], '|',
              ' ; '.join('%s=%s' % (Path(w).name[:50], s) for w, s in tried), flush=True)
    print('exact %d / %d decided' % (sum(1 for r in done.values() if r['status'] == 'EXACT'), len(done)))


def demo():
    assert norm('class CXTPCustomizeSheet::CCustomizeButton [subobject +32]') == 'CXTPCustomizeSheet::CCustomizeButton'
    assert norm("const CXTPHeapAllocatorT<struct CXTPReportRowAllocatorData>::`vftable'") == \
        norm('class CXTPHeapAllocatorT<struct CXTPReportRowAllocatorData>')
    assert norm("const A::`vftable'{for `B'}") == 'A'


if __name__ == '__main__':
    demo()
    main()
