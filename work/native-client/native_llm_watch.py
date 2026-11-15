"""Live failure watch for a native_llm run: waits (up to --wait s) for new chat files, then prints each new answer's
status, model, first compile error and the reply's first lines.  State in native-llm/watch-seen.json.
  python work/native-client/native_llm_watch.py [--wait 120]"""
import argparse
import json
import re
import time
from pathlib import Path

HERE = Path(__file__).resolve().parent / 'native-llm'
SEEN = HERE / 'watch-seen.json'


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--wait', type=float, default=120)
    args = ap.parse_args()
    seen = set(json.loads(SEEN.read_text())) if SEEN.is_file() else {p.name for p in (HERE / 'chats').glob('*.json')}
    deadline = time.time() + args.wait
    while True:
        new = sorted(p for p in (HERE / 'chats').glob('*.json') if p.name not in seen)
        if new or time.time() > deadline:
            break
        time.sleep(5)
    for path in new:
        seen.add(path.name)
        chat = json.loads(path.read_text(encoding='utf-8'))
        error = re.search(r'error C\d+:[^\n]{0,140}', chat['result'] or '')
        print('%-15s %-14s %-44s %s' % (chat['status'], chat['model'].split(':')[-1], chat['qual'][-44:],
                                         error.group(0) if error else (chat['result'] or '')[:100].replace('\n', ' ')))
        if chat['status'] not in ('inactive_exact', 'draft'):
            code = (re.findall(r'```(?:cpp)?\s*\n(.*?)```', chat['reply'] or '', re.S) or [chat['reply'] or ''])[-1]
            print('    ' + '\n    '.join(code.strip().splitlines()[:6]))
    SEEN.write_text(json.dumps(sorted(seen)))
    print('-- %d new' % len(new))


if __name__ == '__main__':
    main()
