"""Plan deterministic source-backed native transplant batches from closure gate rows."""
import argparse
import hashlib
import json
import re
import subprocess
import sys
from collections import defaultdict
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
LIB = re.compile(r'^// roc-lib: (\S+) (.+)$', re.M)
ROC_CL = re.compile(r'^// roc-cl: (\d+)$', re.M)
ROC_FLAGS = re.compile(r'^// roc-flags: (.*)$', re.M)
LOCAL_SOURCE_ROOTS = [ROOT / 'tools/rbxgs', ROOT / 'tools/openrbx',
                      ROOT / 'work/upstream/OpenRBX', ROOT / 'tools/libs']
LOCAL_SOURCE_CACHE_PATH = ROOT / 'work/native-client/local-owner-source-cache-v2.json'
LOCAL_SOURCE_CACHE = None


def usable_source(path):
    """Exclude mined/generated helper files from the native recovery pipeline."""
    return path.is_file() and not path.name.startswith('roc_')


def attempt_key(source, header, roc_flags, symbol, marker, probe_profile):
    """Stable identity for one source/header/profile transplant hypothesis."""
    payload = {'source': str(Path(source).resolve()),
               'source_sha256': hashlib.sha256(Path(source).read_bytes()).hexdigest(),
               'header': str(header),
               'header_sha256': hashlib.sha256((ROOT / header).read_bytes()).hexdigest(),
               'roc_flags': roc_flags, 'probe_profile': probe_profile,
               'symbol': symbol, 'marker': marker}
    return hashlib.sha256(json.dumps(payload, sort_keys=True).encode()).hexdigest()


def local_owner_source(owner, method):
    """One real local source definition, or no candidate when ambiguous.

    Packet wrappers are not complete: several source-backed members live in
    local vendor trees without a roc-lib directive.  Exact definition search is
    only an analog-selection step; compile and byte proof still decide it.
    """
    global LOCAL_SOURCE_CACHE
    if LOCAL_SOURCE_CACHE is None:
        try:
            LOCAL_SOURCE_CACHE = json.loads(LOCAL_SOURCE_CACHE_PATH.read_text())
        except (OSError, json.JSONDecodeError):
            LOCAL_SOURCE_CACHE = {}
    marker = owner + '::' + method
    if marker in LOCAL_SOURCE_CACHE:
        value = LOCAL_SOURCE_CACHE[marker]
        cached = Path(value) if value else None
        if cached and usable_source(cached):
            return cached
        LOCAL_SOURCE_CACHE[marker] = ''
    command = ['rg', '-l', '--glob', '*.cpp', '--glob', '*.cc',
               r'\b' + re.escape(marker) + r'\s*\(', *map(str, LOCAL_SOURCE_ROOTS)]
    found = subprocess.run(command, capture_output=True, text=True).stdout.splitlines()
    paths = [Path(value).resolve() for value in found if usable_source(Path(value))]
    source = paths[0] if len(paths) == 1 else None
    LOCAL_SOURCE_CACHE[marker] = str(source) if source else ''
    return source


def owner_namespace(header_text, owner):
    if '::' in owner:
        return ''
    stack, depth, pending = [], 0, None
    for line in header_text.splitlines():
        if pending and '{' in line:
            stack.append((pending, depth + line[:line.index('{') + 1].count('{')))
            pending = None
        for namespace in re.finditer(r'\bnamespace\s+([A-Za-z_]\w*)\s*\{', line):
            stack.append((namespace.group(1), depth + line[:namespace.end()].count('{')))
        bare_namespace = re.match(r'^\s*namespace\s+([A-Za-z_]\w*)\s*$', line)
        if bare_namespace:
            pending = bare_namespace.group(1)
        depth += line.count('{')
        if re.search(r'\b(?:class|struct)\s+' + re.escape(owner) + r'\b', line):
            return '::'.join(name for name, _ in stack)
        depth -= line.count('}')
        while stack and stack[-1][1] > depth:
            stack.pop()
    return ''


def has_definition(text, marker):
    return bool(re.search(re.escape(marker) + r'\s*\([^;{}]*\)\s*(?:const\s*)?(?::[^{};]*)?\{', text, re.S))


def header_has_member_body(text, owner, method):
    """Find an inline body inside the exact owner class, not a same-name peer."""
    leaf = owner.rsplit('::', 1)[-1]
    found = re.search(r'\b(?:class|struct)\s+' + re.escape(leaf) + r'\b[^;{]*\{', text)
    if not found:
        return False
    depth, end = 1, found.end()
    for index in range(end, len(text)):
        depth += text[index] == '{'
        depth -= text[index] == '}'
        if not depth:
            end = index
            break
    body = text[found.end():end]
    return bool(re.search(r'\b' + re.escape(method) +
                          r'\s*\([^;{}]*\)\s*(?:const\s*)?(?::[^{};]*)?\{', body, re.S))


def safe_packet_body(text, owner, method):
    """Packet body may be used only when it already names real header types.

    Mined packets commonly replace the owner with `S` and fields with padding;
    those are codegen analogs, never source candidates.  This narrow fallback
    admits an already-qualified body and leaves all stand-in packets blocked.
    """
    marker = owner + '::' + method
    if not has_definition(text, marker):
        return False
    unsafe = (r'\breinterpret_cast\s*<',
              r'\b(?:char|unsigned\s+char)\s+(?:padding|opaque|reserved)\s*\[',
              # A packet-side aggregate is a recreated ABI, not a use of the
              # native header.  Local declarations are not enough to prove its
              # fields or virtual order and must never enter a native probe.
              r'\b(?:struct|class)\s+[A-Za-z_]\w*(?:\s*:\s*[^\{;]+)?\s*\{')
    return not any(re.search(pattern, text) for pattern in unsafe)


def parameter_count(text):
    text = text.strip()
    if not text or text == 'void':
        return 0
    depth = 0
    count = 1
    for char in text:
        if char in '(<[':
            depth += 1
        elif char in ')>]':
            depth -= 1
        elif char == ',' and depth == 0:
            count += 1
    return count


def marker_for_symbol(source_text, marker, symbol):
    """Suffix only uniquely arity-resolved overloads; otherwise stay conservative."""
    from native_conversion_queue import undecorate
    from native_transplant_probe import method_start
    decoded = undecorate(symbol)
    target = re.search(r'\((.*)\)\s*$', decoded)
    if not target:
        return marker
    arity = parameter_count(target.group(1))
    candidates, index = [], 0
    while True:
        try:
            start = method_start(source_text, marker, index)
        except ValueError:
            break
        open_paren = source_text.find('(', start + len(marker))
        depth, end = 0, open_paren
        for end in range(open_paren, len(source_text)):
            if source_text[end] == '(':
                depth += 1
            elif source_text[end] == ')':
                depth -= 1
                if not depth:
                    break
        if parameter_count(source_text[open_paren + 1:end]) == arity:
            candidates.append(index)
        index += 1
    return marker + '#' + str(candidates[0]) if len(candidates) == 1 else marker


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--gate', type=Path, required=True)
    ap.add_argument('--limit', type=int, default=200)
    ap.add_argument('--skip-attempted', action='store_true',
                    help='skip nonexact rows already probed under a real header')
    ap.add_argument('--source-includes', action=argparse.BooleanOptionalAction, default=True)
    ap.add_argument('--source-preamble', action='store_true')
    ap.add_argument('--add-flags', default='/GS-')
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    from roc import libs
    promoted, attempted = set(), set()
    probe_profile = {'source_preamble': args.source_preamble,
                     'source_includes': args.source_includes,
                     'add_flags': args.add_flags}
    # Promotion may originate from any isolated probe family.  Receipt
    # discovery, rather than a directory name, prevents re-planning bodies
    # already placed in native-classes.
    for receipt in ROOT.glob('work/native-client/**/promotion.json'):
        try:
            row = json.loads(receipt.read_text())
        except json.JSONDecodeError:
            continue
        if row.get('applied'):
            promoted.update(value.lower() for value in row.get('requested', []))
    if args.skip_attempted:
        # Receipts with an attempt key identify identical source/header/profile
        # hypotheses. Legacy receipts omit it and remain retryable after converter
        # improvements because their exact input cannot be reconstructed safely.
        receipts = ROOT.glob('work/native-client/**/result.json')
        for receipt in receipts:
            try:
                result = json.loads(receipt.read_text())
            except json.JSONDecodeError:
                continue
            rows = list(result.get('requested', []))
            for batch in result.get('results', []):
                rows.extend(batch.get('requested', []))
            for row in rows:
                if row.get('status') != 'inactive_exact' and row.get('attempt_key'):
                    attempted.add(row['attempt_key'])
    groups, blocked = defaultdict(list), []
    for row in json.loads(args.gate.read_text())['rows']:
        if row['status'] != 'convert-ready':
            continue
        if row['addr'].lower() in promoted:
            continue
        packet = ROOT / 'src/2008-06' / (row['addr'] + '.cpp')
        packet_text = packet.read_text(errors='replace') if packet.is_file() else ''
        hit = LIB.search(packet_text) if packet_text else None
        recipe = ''
        source = None
        if hit:
            recipe, rel = hit.groups()
            spec = libs.RECIPES.get(recipe)
            source = (libs.LIBS / spec['src'] / rel).resolve() if spec else None
            if recipe == 'openrbx-raknet':
                rbxgs_source = ROOT / 'tools/rbxgs/Client/Network/raknet30/Source' / rel
                if usable_source(rbxgs_source):
                    source = rbxgs_source.resolve()
        elif safe_packet_body(packet_text, row['owner'], row['method']):
            # The mined packet itself is valid source evidence only under the
            # strict predicate above.  It is still compiled solely against the
            # real header and must pass byte/data/reference proof.
            source = packet.resolve()
        else:
            source = local_owner_source(row['owner'], row['method'])
        if not source or not usable_source(source):
            blocked.append({'addr': row['addr'], 'reason': 'source unavailable or packet lacks safe real-owner body', 'recipe': recipe})
            continue
        marker = row['owner'] + '::' + row['method']
        source_text = source.read_text(errors='replace')
        if not has_definition(source_text, marker):
            blocked.append({'addr': row['addr'], 'reason': 'source lacks closure owner/method', 'source': str(source)})
            continue
        header_text = (ROOT / row['headers'][0]).read_text(errors='replace')
        if header_has_member_body(header_text, row['owner'], row['method']):
            blocked.append({'addr': row['addr'], 'reason': 'real header already defines member inline',
                            'header': row['headers'][0]})
            continue
        namespace = owner_namespace(header_text, row['owner'])
        roc_cl = int(ROC_CL.search(packet_text).group(1)) if ROC_CL.search(packet_text) else 21022
        roc_flags = ROC_FLAGS.search(packet_text).group(1) if ROC_FLAGS.search(packet_text) else ''
        if recipe in {'openrbx-raknet', 'rbxgs-raknet'} and '/FImalloc.h' not in roc_flags:
            roc_flags = (roc_flags + ' /FImalloc.h').strip()
        marker = marker_for_symbol(source_text, marker, row['symbol'])
        if attempt_key(source, row['headers'][0], roc_flags, row['symbol'], marker, probe_profile) in attempted:
            continue
        groups[(row['owner'], tuple(row['headers']), str(source), namespace, roc_cl, roc_flags)].append(
            {'addr': row['addr'], 'symbol': row['symbol'], 'marker': marker, 'header': row['headers'][0], 'namespace': namespace,
             'roc_cl': roc_cl, 'roc_flags': roc_flags})
    plans = []
    for (owner, headers, source, namespace, roc_cl, roc_flags), rows in sorted(groups.items(), key=lambda item: (-len(item[1]), item[0])):
        unique = []
        seen = set()
        for row in rows:
            if row['addr'] not in seen:
                unique.append(row)
                seen.add(row['addr'])
        for offset in range(0, len(unique), args.limit):
            selected = unique[offset:offset + args.limit]
            plans.append({'owner': owner, 'headers': list(headers), 'source': source,
                          'namespace': namespace,
                          'roc_cl': roc_cl, 'roc_flags': roc_flags,
                          'destination': 'rebuild/2008-06/native-classes/' + owner.split('::')[-1] + '.cpp',
                          'probe_records': [row['addr'] + '=' + row['marker'] for row in selected],
                          'rows': selected})
    out = {'scope': 'source availability plan only; no code/lease/promotion/proof',
           'promoted_skipped': len(promoted),
           'attempted_skipped': len(attempted) if args.skip_attempted else 0,
           'summary': {'ready_source_backed': sum(len(plan['rows']) for plan in plans),
                       'plans': len(plans), 'blocked': len(blocked)},
           'plans': plans, 'blocked': blocked}
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(out, indent=1) + '\n')
    if LOCAL_SOURCE_CACHE is not None:
        LOCAL_SOURCE_CACHE_PATH.write_text(json.dumps(LOCAL_SOURCE_CACHE, indent=1) + '\n')
    print(json.dumps(out['summary']))


if __name__ == '__main__':
    main()
