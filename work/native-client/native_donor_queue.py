"""Queue high-confidence donor names for deterministic native probing.

Donor names are candidates only.  This script never binds a symbol, edits a
native file, or treats a header's short class name as namespace proof.  It
only finds the narrow cases where a donor owner/method has one local native
header declaration and a mined packet, ready for a byte-exact probe.
"""
import argparse
import json
import re
import subprocess
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
METHOD = re.compile(r"\b([~A-Za-z_]\w*)\s*\(")
ROC_LIB = re.compile(r'^// roc-lib: (\S+) (.+)$', re.M)
LOCAL_SOURCE_ROOTS = [ROOT / 'tools/rbxgs', ROOT / 'tools/openrbx', ROOT / 'tools/libs']
SOURCE_CACHE_PATH = ROOT / 'work/native-client/donor-source-definition-cache.json'
SOURCE_CACHE = None


def split_candidate(candidate):
    """Return candidate owner/method, including templated owners."""
    depth = 0
    for index in range(len(candidate) - 1, 0, -1):
        char = candidate[index]
        if char == '>':
            depth += 1
        elif char == '<':
            depth -= 1
        elif depth == 0 and candidate[index - 1:index + 1] == '::':
            return candidate[:index - 1], candidate[index + 1:]
    return '', candidate


def declared(header, method):
    try:
        return method in METHOD.findall((ROOT / header).read_text(errors='replace'))
    except OSError:
        return False


def native_providers(owner, method):
    short = owner.rsplit('::', 1)[-1]
    marker = short + '::' + method
    definition = re.compile(re.escape(marker) +
                            r'\s*\([^;{}]*\)\s*(?:const\s*)?(?::[^{};]*)?\{', re.S)
    return sorted(path.relative_to(ROOT).as_posix()
                  for path in (ROOT / 'rebuild/2008-06/native-classes').glob('*.cpp')
                  if definition.search(path.read_text(errors='replace')))


def source_definitions(owner, method):
    """Find one real local definition without treating mined packet text as source."""
    global SOURCE_CACHE
    if SOURCE_CACHE is None:
        try:
            SOURCE_CACHE = json.loads(SOURCE_CACHE_PATH.read_text())
        except (OSError, json.JSONDecodeError):
            SOURCE_CACHE = {}
    key = owner + '::' + method
    if key in SOURCE_CACHE:
        return SOURCE_CACHE[key]
    short = owner.rsplit('::', 1)[-1]
    marker = short + '::' + method
    command = ['rg', '-l', '--glob', '*.cpp', '--glob', '*.cc',
               r'\b' + re.escape(marker) + r'\s*\(', *map(str, LOCAL_SOURCE_ROOTS)]
    found = subprocess.run(command, capture_output=True, text=True).stdout.splitlines()
    result = sorted(str(Path(value).resolve().relative_to(ROOT)).replace('\\', '/')
                    for value in found if Path(value).is_file())
    SOURCE_CACHE[key] = result
    return result


def packet_library_source(packet):
    """Resolve packet's declared vendor unit before heuristic source search."""
    try:
        match = ROC_LIB.search(packet.read_text(errors='replace'))
        if not match:
            return []
        from roc import libs
        recipe, relative = match.groups()
        spec = libs.RECIPES.get(recipe)
        if not spec:
            return []
        source = (libs.LIBS / spec['src'] / relative).resolve()
        return [str(source.relative_to(ROOT)).replace('\\', '/')] if source.is_file() else []
    except (OSError, ValueError):
        return []


def has_member_definition(source, owner, method):
    short = owner.rsplit('::', 1)[-1]
    marker = short + '::' + method
    try:
        return bool(re.search(re.escape(marker) +
                              r'\s*\([^;{}]*\)\s*(?:const\s*)?(?::[^{};]*)?\{',
                              (ROOT / source).read_text(errors='replace'), re.S))
    except OSError:
        return False


def uses_layout_proxy(source):
    """Stand-in offset/layout bodies cannot become authentic native methods."""
    try:
        text = (ROOT / source).read_text(errors='replace')
    except OSError:
        return False
    return bool(re.search(r'reinterpret_cast\s*<\s*[^>]*\b\w*Layout\w*\s*\*\s*>\s*\(\s*this\s*\)', text))


def attempted_donor_probes():
    """Only exact same donor/source/header failures suppress a future probe."""
    attempts = {}
    for receipt in ROOT.glob('work/native-client/**/result.json'):
        try:
            data = json.loads(receipt.read_text())
        except (OSError, json.JSONDecodeError):
            continue
        if not data.get('scope', '').startswith('donor candidate compile'):
            continue
        for row in data.get('results', []):
            if row.get('status') == 'inactive_exact':
                continue
            key = (row.get('address', '').lower(), row.get('candidate'),
                   row.get('source'), row.get('header'))
            if all(key):
                attempts[key] = row.get('status')
    return attempts


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--donors', type=Path, required=True)
    ap.add_argument('--closure', type=Path, required=True)
    ap.add_argument('--inventory', type=Path,
                    default=Path('work/native-client/native-recovery-inventory.json'))
    ap.add_argument('--minimum-strings', type=int, default=2)
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    donors = json.loads(args.donors.read_text())['functions']
    inventory = json.loads(args.inventory.read_text())
    bound = {row['addr'].lower() for row in json.loads(args.closure.read_text())['bindings']}
    header_classes = inventory['header_classes']
    attempted = attempted_donor_probes()
    rows = []
    for donor in donors:
        address = donor['address'].lower()
        if (donor['verdict'] != 'new' or donor['shared_unique_strings'] < args.minimum_strings
                or address in bound):
            continue
        owner, method = split_candidate(donor['candidate'])
        short = owner.rsplit('::', 1)[-1]
        headers = sorted(set(header_classes.get(short, [])))
        declaring = [header for header in headers if declared(header, method)]
        packet = ROOT / 'src/2008-06' / (address + '.cpp')
        providers = native_providers(owner, method)
        packet_sources = packet_library_source(packet) if packet.is_file() else []
        layout_proxy = any(uses_layout_proxy(source) for source in packet_sources)
        packet_sources = [source for source in packet_sources
                          if has_member_definition(source, owner, method) and not uses_layout_proxy(source)]
        sources = packet_sources or source_definitions(owner, method)
        attempt_key = (address, donor['candidate'], sources[0], declaring[0]) \
            if len(sources) == 1 and len(declaring) == 1 else None
        if not packet.is_file():
            status, reason = 'blocked-no-packet', 'mined packet absent'
        elif layout_proxy:
            status, reason = 'blocked-layout-proxy-source', 'packet roc-lib body uses stand-in Layout reinterpret_cast'
        elif not declaring:
            status, reason = 'blocked-no-declaring-header', 'no local header declares donor method name'
        elif len(declaring) != 1:
            status, reason = 'blocked-ambiguous-header', 'multiple local headers declare donor method name'
        elif providers:
            status, reason = 'profile-sweep', 'native class already defines donor method name'
        elif attempt_key in attempted:
            status, reason = 'blocked-attempted-probe', 'same donor/source/header previously ' + attempted[attempt_key]
        elif not sources:
            status, reason = 'blocked-no-local-body', 'no real local source defines donor owner/method'
        elif len(sources) != 1:
            status, reason = 'blocked-ambiguous-local-body', 'multiple local sources define donor owner/method'
        else:
            status, reason = 'candidate-probe', 'one local declaring header and one real local body; byte-exact probe required'
        rows.append({'addr': address, 'candidate': donor['candidate'], 'owner': owner,
                     'method': method, 'shared_unique_strings': donor['shared_unique_strings'],
                     'headers': declaring, 'native_providers': providers, 'source_files': sources,
                     'source_evidence': 'packet-roc-lib' if packet_sources else 'definition-search',
                     'status': status, 'reason': reason})
    rows.sort(key=lambda row: (-row['shared_unique_strings'], row['status'], row['candidate'], row['addr']))
    summary = {status: sum(row['status'] == status for row in rows)
               for status in sorted({row['status'] for row in rows})}
    out = {'scope': 'donor owner evidence only; no declaration identity, byte proof, provider selection, or promotion',
           'donors': str(args.donors), 'closure': str(args.closure),
           'minimum_shared_unique_strings': args.minimum_strings, 'summary': summary, 'rows': rows}
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(out, indent=1) + '\n')
    if SOURCE_CACHE is not None:
        SOURCE_CACHE_PATH.write_text(json.dumps(SOURCE_CACHE, indent=1) + '\n')
    print(json.dumps(summary))


if __name__ == '__main__':
    main()
