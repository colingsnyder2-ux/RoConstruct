"""Create an inactive real-header compile probe from one mined method body.

The output stays under work/.  It is never promoted to native-classes: exact
compile/data/call proof plus a lease are required before that separate step.
"""
import argparse
import re
from pathlib import Path


SAFE_SYSTEM_INCLUDES = {'assert.h', 'ctype.h', 'float.h', 'limits.h', 'malloc.h',
                        'math.h', 'memory.h', 'stdio.h', 'stdlib.h', 'string.h', 'time.h'}
TARGET_DEFINES = {'_WIN32', '_MSC_VER'}


def active_externs(prefix, used):
    """Keep only donor extern declarations active for the VS2008 Windows target."""
    out, stack, active = [], [], True
    for line in prefix.splitlines():
        text = line.strip()
        directive = re.match(r'^#\s*(ifdef|ifndef|if|else|endif)\b\s*(.*)$', text)
        if directive:
            kind, value = directive.groups()
            if kind in ('ifdef', 'ifndef'):
                condition = value.strip() in TARGET_DEFINES
                if kind == 'ifndef':
                    condition = not condition
                stack.append((active, condition))
                active = active and condition
            elif kind == 'if':
                names = re.findall(r'defined\s*\(\s*([A-Za-z_]\w*)\s*\)', value)
                condition = bool(names) and all(name in TARGET_DEFINES for name in names)
                if '!' in value:
                    condition = not condition
                stack.append((active, condition))
                active = active and condition
            elif kind == 'else' and stack:
                parent, condition = stack[-1]
                active = parent and not condition
            elif kind == 'endif' and stack:
                active, _ = stack.pop()
            continue
        if active and re.match(r'^extern\s+[^;{}]+;\s*$', text):
            calls = re.findall(r'\b([A-Za-z_]\w*)\s*\(', text)
            if calls and calls[-1] in used:
                out.append(text)
    return list(dict.fromkeys(out))


def method_start(text, marker, occurrence=0):
    matches = []
    for match in re.finditer(re.escape(marker) + r'\s*\(', text):
        depth = 0
        for pos in range(match.end() - 1, len(text)):
            if text[pos] == '(':
                depth += 1
            elif text[pos] == ')':
                depth -= 1
                if depth == 0:
                    tail = text[pos + 1:].lstrip()
                    initializer = tail.startswith(':') and ('{' in tail) and (tail.find('{') < tail.find(';') if ';' in tail else True)
                    if tail.startswith('{') or re.match(r'const\s*\{', tail) or initializer:
                        matches.append(match)
                    break
    if not matches:
        raise ValueError('method marker not found: ' + marker)
    if occurrence >= len(matches):
        raise ValueError('method overload missing: ' + marker)
    start = matches[occurrence].start()
    return text.rfind('\n', 0, start) + 1


def body_at(text, marker, occurrence=0):
    start = method_start(text, marker, occurrence)
    brace = text.find('{', start)
    if brace < 0:
        raise ValueError('method body missing: ' + marker)
    depth = 0
    for pos in range(brace, len(text)):
        if text[pos] == '{':
            depth += 1
        elif text[pos] == '}':
            depth -= 1
            if depth == 0:
                return text[start:pos + 1]
    raise ValueError('unterminated method: ' + marker)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--packet', type=Path, required=True)
    ap.add_argument('--marker', action='append', default=[])
    ap.add_argument('--record', action='append', default=[], metavar='ADDR=MARKER')
    ap.add_argument('--namespace', dest='namespace_', required=True)
    ap.add_argument('--include', action='append', required=True)
    ap.add_argument('--include-dir', action='append', default=[])
    ap.add_argument('--flags', default='')
    ap.add_argument('--support-globals', action='store_true')
    ap.add_argument('--source-preamble', action='store_true')
    ap.add_argument('--source-includes', action='store_true')
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    if bool(args.marker) == bool(args.record):
        ap.error('supply --marker or --record')
    text = args.packet.read_text(errors='replace')
    records, starts = [], []
    occurrences = {}
    for value in args.record:
        addr, sep, marker = value.partition('=')
        if not sep or not __import__('re').fullmatch(r'[0-9a-fA-F]{8}', addr):
            ap.error('--record needs ADDR=MARKER')
        marker, forced, occurrence_text = marker.rpartition('#')
        if forced and occurrence_text.isdigit():
            occurrence = int(occurrence_text)
        else:
            marker = value.partition('=')[2]
            occurrence = occurrences.get(marker, 0)
        occurrences[marker] = occurrence + 1
        records.append((addr.lower(), body_at(text, marker, occurrence)))
        starts.append(method_start(text, marker, occurrence))
    methods = [body_at(text, marker) for marker in args.marker] if args.marker else [body for _, body in records]
    # native-bulk compiles in a hashed object directory.  Relative include
    # paths from a plan would then point at that directory, not repository
    # root.  Freeze probe include roots to their resolved paths.
    include_dirs = [str(Path(value).resolve()) for value in args.include_dir]
    profile = ' '.join(part for part in [args.flags, *('/I' + value for value in include_dirs)] if part)
    flags = '// native-flags: ' + profile + '\n' if profile else ''
    includes = ''.join('#include "%s"\n' % value for value in args.include)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    scopes = [name for name in args.namespace_.split('::') if name]
    opened = ''.join('namespace %s {\n' % name for name in scopes)
    closed = ''.join('}\n' for _ in scopes)
    bodies = ('\n\n'.join('// native-transplant: %s\n%s' % (addr, body)
                           for addr, body in records) if records else '\n\n'.join(methods))
    supports = []
    if args.support_globals and records:
        used = set(re.findall(r'\b[A-Za-z_]\w*\b', bodies))
        prefix = text[:min(starts)]
        depth = 0
        for line in prefix.splitlines():
            at_top_level = depth == 0
            match = re.match(r'^\s*((?:static\s+)?[^{};#\n]+;)\s*(?://.*)?$', line)
            if not match or not at_top_level or not line.lstrip().startswith('static '):
                depth += line.count('{') - line.count('}')
                continue
            calls = re.findall(r'\b([A-Za-z_]\w*)\s*\(', line)
            bare = (re.match(r'^\s*(?:[A-Za-z_]\w*(?:::\w+)?(?:<[^;{}()]*>)?\s+)+([A-Za-z_]\w*)\s*;\s*$', line)
                    if not re.match(r'^\s*(?:delete|return|break|continue|throw)\b', line) else None)
            assigned = re.search(r'\b([A-Za-z_]\w*)\s*=', match.group(1))
            name = calls[-1] if line.lstrip().startswith('static ') and calls else (assigned.group(1) if assigned else (bare.group(1) if bare else ''))
            if name in used:
                supports.append(match.group(1))
            depth += line.count('{') - line.count('}')
    support_text = ('\n'.join('// native-support-global\n' + line for line in supports) + '\n\n') if supports else ''
    if (args.source_preamble or args.source_includes) and records:
        # The selected real header is authoritative.  Donor packets often include a
        # same-basename stand-in header from another include root; emitting both
        # creates a duplicate class, not useful evidence.  `decomp.h` is packet
        # annotation support, absent from real builds and irrelevant to extracted
        # method bodies.
        primary_basenames = {Path(value).name.lower() for value in args.include}
        vendor_includes = re.findall(r'^\s*#include\s+([<"])([^>"]+)[>"]', text, re.M)
        # Source includes are flattened into a new TU, so retaining conditional
        # platform headers would defeat their #if (RakPeer.cpp would include
        # unistd.h even under WIN32).  Preserve local quoted headers plus a
        # small, non-platform C runtime allowlist the original source named.
        source_dir = args.packet.parent
        vendor_includes = [(bracket, value) for bracket, value in vendor_includes
                           if ((bracket == '"' and ((source_dir / value).is_file() or any((Path(d) / value).is_file() for d in include_dirs))) or
                               (bracket == '<' and value.lower() in SAFE_SYSTEM_INCLUDES))
                           and value not in args.include
                           and Path(value).name.lower() not in primary_basenames
                           and Path(value).name.lower() != 'decomp.h']
        includes += ''.join('#include %s%s%s\n' % (bracket, value, '>' if bracket == '<' else '"')
                            for bracket, value in dict.fromkeys(vendor_includes))
    if args.source_preamble and records:
        namespace = re.search(r'\bnamespace\s+' + re.escape(scopes[0]) + r'\s*\{', text) if scopes else None
        if scopes and not namespace:
            raise ValueError('source preamble needs a matching namespace')
        support_text = text[namespace.end() if namespace else 0:min(starts)].strip() + '\n\n'
        externs = active_externs(text[:min(starts)], used)
        if externs:
            support_text += '\n'.join('// native-support-global\n' + line for line in externs) + '\n\n'
    # Native headers declare class-name globals as `extern const char sX[]`; donor sources define `char* sX = "X"`.
    support_text = re.sub(r'^(\s*)(?:const\s+)?char\s*\*\s*(s[A-Z]\w*)\s*=\s*("[^"\n]*")\s*;',
                          r'\1const char \2[] = \3;', support_text, flags=re.M)
    args.output.write_text('// generated inactive real-header probe; do not promote without proof\n' + flags + includes +
                           '\n' + opened + support_text + bodies + '\n' + closed)
    print('generated', args.output, 'methods', len(methods),
          'bytes', sum(map(len, methods)), 'packet', args.packet)


if __name__ == '__main__':
    main()
