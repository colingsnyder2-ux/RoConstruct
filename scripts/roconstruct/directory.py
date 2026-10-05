#!/usr/bin/env python3
"""Opt-in metadata-only public server directory."""
import argparse
import json
import os
import sqlite3
import time
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from urllib.parse import urlparse


class Directory(BaseHTTPRequestHandler):
    db = None
    token = ""

    def log_message(self, fmt, *args):
        return

    def send_json(self, code, value):
        data = json.dumps(value).encode()
        self.send_response(code)
        self.send_header("Content-Type", "application/json")
        self.send_header("Content-Length", str(len(data)))
        self.end_headers()
        self.wfile.write(data)

    def body(self):
        return json.loads(self.rfile.read(int(self.headers.get("Content-Length", 0))) or b"{}")

    def do_GET(self):
        if urlparse(self.path).path != "/v1/servers":
            return self.send_json(404, {"error": "not found"})
        rows = self.db.execute("SELECT name,url,description,client,project,seen FROM servers WHERE seen>? ORDER BY name",
                               (time.time() - 300,)).fetchall()
        self.send_json(200, {"servers": [{"name": r[0], "url": r[1], "description": r[2],
                                           "client": r[3], "project": r[4], "seen": r[5]} for r in rows]})

    def do_POST(self):
        if self.headers.get("X-Directory-Token") != self.token:
            return self.send_json(401, {"error": "directory token required"})
        if urlparse(self.path).path != "/v1/register":
            return self.send_json(404, {"error": "not found"})
        item = self.body()
        if not item.get("name") or not item.get("url"):
            return self.send_json(400, {"error": "name and url required"})
        self.db.execute("INSERT OR REPLACE INTO servers(url,name,description,client,project,seen) VALUES(?,?,?,?,?,?)",
                        (item["url"], item["name"], item.get("description", ""), item.get("client", "unknown"),
                         item.get("project", "default"), time.time()))
        self.db.commit()
        self.send_json(200, {"registered": True})


def main():
    parser = argparse.ArgumentParser(description="Run opt-in metadata-only RoConstruct server directory")
    parser.add_argument("--host", default="127.0.0.1")
    parser.add_argument("--port", type=int, default=8780)
    parser.add_argument("--db", default="directory.db")
    parser.add_argument("--token", default=os.environ.get("ROCONSTRUCT_DIRECTORY_TOKEN", ""))
    args = parser.parse_args()
    db = sqlite3.connect(args.db, check_same_thread=False)
    db.execute("CREATE TABLE IF NOT EXISTS servers(url TEXT PRIMARY KEY,name TEXT,description TEXT,client TEXT,project TEXT,seen REAL)")
    db.commit()
    Directory.db = db; Directory.token = args.token
    print("RoConstruct directory: http://%s:%d" % (args.host, args.port), flush=True)
    ThreadingHTTPServer((args.host, args.port), Directory).serve_forever()


if __name__ == "__main__":
    main()
