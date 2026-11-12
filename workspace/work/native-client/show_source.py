"""Print a native source file without its generated top-of-file comments, so you only read the code.

  python work/native-client/show_source.py FILE [--from LINE] [--to LINE]   (default: whole file)
  python work/native-client/show_source.py FILE --function NAME             (just the function whose name contains NAME)

Hidden: the `// native-flags:` / `// 2008-06 native ...` / `// >>> native-status ... <<<` banner block and the leading
`#line` directive. They are generated metadata. Do not read them, edit them or copy them; the proof tools use them
(`// native-flags:` selects compiler flags) and leave them alone. Line numbers shown are the real file line numbers.
"""
import argparse
import re
import sys
from pathlib import Path


def body_start(lines):
    """Index of the first line that is real code: after the leading banner comments / #line / blank lines."""
    i, in_banner = 0, False
    while i < len(lines):
        s = lines[i].strip()
        if s.startswith('// >>> native-status'):
            in_banner = True
        elif in_banner:
            in_banner = not s.startswith('// <<< native-status')
        elif not (s == '' or s.startswith(('// native-flags:', '// 2008-06 native', '// roc-', '#line ')) ):
            break
        i += 1
    return i


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('file')
    ap.add_argument('--from', dest='first', type=int)
    ap.add_argument('--to', dest='last', type=int)
    ap.add_argument('--function', metavar='NAME')
    args = ap.parse_args()
    lines = Path(args.file).read_text(encoding='utf-8', errors='replace').splitlines()
    start = body_start(lines)
    lo, hi = max(args.first or 1, start + 1), args.last or len(lines)
    if args.function:
        hit = next((i for i in range(start, len(lines)) if lines[i][:1].strip() and args.function in lines[i] and re.search(r'\w\s*\(', lines[i]) and not lines[i].lstrip().startswith(('//', '*', '#', 'return')) and not lines[i].rstrip().endswith(';')), None)
        if hit is None:
            sys.exit('no function containing %r' % args.function)
        depth, seen, end = 0, False, hit
        for j in range(hit, len(lines)):
            depth += lines[j].count('{') - lines[j].count('}')
            seen = seen or '{' in lines[j]
            end = j
            if seen and depth <= 0:
                break
        lo, hi = hit + 1, end + 1
    for n in range(lo, min(hi, len(lines)) + 1):
        print('%5d  %s' % (n, lines[n - 1]))


if __name__ == '__main__':
    main()
