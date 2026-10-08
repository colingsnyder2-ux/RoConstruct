#!/usr/bin/env python3
"""Search public indexes for high-value RoConstruct artifacts.

Metadata only: this never downloads executables or archives. Every query and
result is recorded in docs/artifact-search-log.json so later runs skip repeats.
"""
from __future__ import annotations

import argparse
import json
import re
import ssl
import sys
import urllib.parse
import urllib.request
from concurrent.futures import ThreadPoolExecutor
from datetime import datetime, timezone
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
LOG = ROOT / "docs" / "artifact-search-log.json"
TARGETS = [
    "RobloxPlayer.pdb", "RobloxApp.pdb", "RobloxPlayer.map", "RobloxApp.map",
    "libcpmt.lib", "libcmt.lib", "msvcprt.lib", "vc80.pdb", "vc90.pdb",
    ".vcproj", "RobloxPlayer.obj", "RobloxApp.obj",
]
UA = "RoConstruct-artifact-scout/1.0 (public preservation research)"
CTX = ssl.create_default_context()


def load_log():
    if LOG.exists():
        return json.loads(LOG.read_text(encoding="utf-8"))
    return {"version": 1, "queries": [], "results": []}


def get(url, timeout=8):
    req = urllib.request.Request(url, headers={"User-Agent": UA, "Accept": "application/json"})
    try:
        with urllib.request.urlopen(req, timeout=timeout, context=CTX) as r:
            return r.status, r.read(2_000_000).decode("utf-8", "replace")
    except Exception as e:
        return 0, str(e)


def add_query(log, source, target, url, status, results):
    key = f"{source}|{target}|{url}"
    if any(q.get("key") == key for q in log["queries"]):
        return
    log["queries"].append({"key": key, "source": source, "target": target,
                           "url": url, "status": status,
                           "checked_at": datetime.now(timezone.utc).isoformat()})
    for item in results:
        item["source"] = source
        item["target"] = target
        item["query_url"] = url
        log["results"].append(item)


def commoncrawl(log, target):
    q = urllib.parse.quote(f"*{target}*", safe="")
    url = f"https://index.commoncrawl.org/CC-MAIN-2026-30-index?url={q}&output=json&filter=status:200"
    status, body = get(url)
    rows = []
    if status == 200:
        for line in body.splitlines():
            try:
                x = json.loads(line)
                rows.append({"url": x.get("url"), "mime": x.get("mime"), "digest": x.get("digest")})
            except json.JSONDecodeError:
                pass
    add_query(log, "Common Crawl", target, url, status, rows[:100])


def wayback(log, target):
    url = "https://web.archive.org/cdx/search/cdx?" + urllib.parse.urlencode({
        "url": f"*{target}", "output": "json", "filter": "statuscode:200",
        "fl": "original,statuscode,mimetype,digest,timestamp", "collapse": "digest",
    })
    status, body = get(url)
    rows = []
    if status == 200:
        try:
            data = json.loads(body)
            for row in data[1:101]:
                rows.append(dict(zip(data[0], row)))
        except (ValueError, IndexError):
            pass
    add_query(log, "Wayback CDX", target, url, status, rows)


def sourcegraph(log, target):
    query = f'"{target}"'
    url = "https://sourcegraph.com/search/stream?" + urllib.parse.urlencode({"q": query, "v": "V3"})
    status, body = get(url)
    rows = []
    for line in body.splitlines():
        if '"type":"match"' not in line:
            continue
        m = re.search(r'"repository":"([^"]+)"', line)
        if m:
            rows.append({"repository": m.group(1)})
    add_query(log, "Sourcegraph", target, url, status, rows[:100])


def main():
    ap = argparse.ArgumentParser(description="Scout public indexes for RoConstruct artifacts")
    ap.add_argument("--target", action="append", choices=TARGETS, help="only search this target (repeatable)")
    args = ap.parse_args()
    log = load_log()
    targets = args.target or TARGETS
    done = {q.get("key") for q in log["queries"]}
    jobs = []
    for target in targets:
        for source, fn in (("Common Crawl", commoncrawl), ("Wayback CDX", wayback), ("Sourcegraph", sourcegraph)):
            marker = next((q.get("key") for q in log["queries"] if q.get("source") == source and q.get("target") == target), None)
            if not marker or marker not in done:
                jobs.append((fn, target))
    with ThreadPoolExecutor(max_workers=8) as pool:
        list(pool.map(lambda job: job[0](log, job[1]), jobs))
    log["last_run"] = datetime.now(timezone.utc).isoformat()
    LOG.write_text(json.dumps(log, indent=2, sort_keys=True) + "\n", encoding="utf-8")
    new = sum(1 for q in log["queries"] if q.get("checked_at") == log["last_run"])
    print(f"scout: checked {new} new index queries; total {len(log['queries'])}; results {len(log['results'])}")


if __name__ == "__main__":
    main()
