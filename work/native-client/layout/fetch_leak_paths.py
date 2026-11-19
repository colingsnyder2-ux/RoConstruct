"""File names (no contents) of the 2016 Roblox source leak mirror, via the GitHub trees API.

Writes leak2016-paths.json: {top-level folder: [relative paths]}. Nothing of the repository's files is
downloaded; only the listing. 'Library' (vendored third-party code) is counted, not listed.

Run: python work/native-client/layout/fetch_leak_paths.py
"""
import json
import urllib.request
from pathlib import Path

REPO = 'Artifaqt/ROBLOX2016'
OUT = Path(__file__).resolve().parent / 'leak2016-paths.json'
KEEP = ('.cpp', '.cc', '.c', '.h', '.hpp', '.inl', '.mm', '.m')


def get(url):
    with urllib.request.urlopen(urllib.request.Request(url, headers={'User-Agent': 'path-listing'}), timeout=120) as r:
        return json.load(r)


def main():
    top = get('https://api.github.com/repos/%s/git/trees/main' % REPO)
    result = json.loads(OUT.read_text(encoding='utf-8')) if OUT.exists() else {}   # resume: folders already listed stay
    counts = {}
    for entry in top['tree']:
        if entry['type'] != 'tree' or entry['path'] in result or entry['path'] == 'Library':
            continue
        tree = get('https://api.github.com/repos/%s/git/trees/%s?recursive=1' % (REPO, entry['sha']))
        paths = [x['path'] for x in tree['tree'] if x['type'] == 'blob' and x['path'].lower().endswith(KEEP)]
        counts[entry['path']] = (len(paths), bool(tree.get('truncated')))
        if entry['path'] != 'Library':
            result[entry['path']] = [p for p in paths]
        OUT.write_text(json.dumps(result), encoding='utf-8')
    for name, (n, cut) in sorted(counts.items(), key=lambda kv: -kv[1][0]):
        print('%-24s %6d%s' % (name, n, ' (truncated)' if cut else ''))


if __name__ == '__main__':
    main()
