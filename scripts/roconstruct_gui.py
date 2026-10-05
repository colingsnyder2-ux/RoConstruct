#!/usr/bin/env python3
"""RoConstruct desktop control panel. Tkinter stdlib; no GUI dependency."""
import json
import hashlib
import queue
import subprocess
import sys
import threading
import tkinter as tk
import os
import urllib.request
from pathlib import Path
from tkinter import messagebox, scrolledtext, ttk

def find_root():
    start = Path(sys.executable).resolve().parent if getattr(sys, "frozen", False) else Path(__file__).resolve()
    for parent in (start, *start.parents):
        if (parent / "scripts" / "re" / "rebuild.py").exists():
            return parent
    return Path(__file__).resolve().parents[1]


ROOT = find_root()
SERVICE = ROOT / "scripts" / "roconstruct"
TOKEN = os.environ.get("ROCONSTRUCT_TOKEN", "")
PROJECT = os.environ.get("ROCONSTRUCT_PROJECT", "default")
DATA_ROOT = Path(os.environ.get("ROCONSTRUCT_DATA_ROOT", str(ROOT / "work" / "re"))).resolve()


class App(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title("RoConstruct // distributed lab")
        self.geometry("760x520")
        self.minsize(700, 460)
        self.configure(bg="#0b1020")
        style = ttk.Style(self)
        style.theme_use("clam")
        style.configure("TFrame", background="#0b1020")
        style.configure("TLabel", background="#0b1020", foreground="#c9d7ff")
        style.configure("Title.TLabel", foreground="#61f4ff", font=("Segoe UI", 18, "bold"))
        style.configure("Sub.TLabel", foreground="#8391b8", font=("Segoe UI", 9))
        style.configure("TButton", background="#182448", foreground="#d9e2ff", padding=(8, 5), borderwidth=0)
        style.map("TButton", background=[("active", "#25407a")], foreground=[("active", "#7dfff1")])
        style.configure("TLabelframe", background="#0b1020", foreground="#61f4ff")
        style.configure("TLabelframe.Label", background="#0b1020", foreground="#61f4ff")
        self.events = queue.Queue()
        self.proc = None
        self.worker_proc = None
        self.build()
        self.poll()

    def build(self):
        top = ttk.Frame(self, padding=(16, 12, 16, 4)); top.pack(fill="x")
        ttk.Label(top, text="ROCONSTRUCT", style="Title.TLabel").pack(anchor="w")
        ttk.Label(top, text="Distributed source reconstruction lab  //  keep client files local", style="Sub.TLabel").pack(anchor="w")
        actions = ttk.LabelFrame(self, text="CONTROL", padding=8); actions.pack(fill="x", padx=16, pady=8)
        for text, fn in (("1  Setup", self.setup), ("2  Check data", self.check_data), ("3  Start server", self.start),
                         ("4  Start worker", self.start_worker), ("5  Add jobs", self.seed),
                         ("↻  Refresh", self.refresh), ("■  Stop", self.stop)):
            ttk.Button(actions, text=text, command=fn).pack(side="left", padx=(0, 5))
        self.status = tk.StringVar(value="OFFLINE  // click Start server")
        ttk.Label(actions, textvariable=self.status, style="Sub.TLabel").pack(side="right", padx=4)
        info = ttk.LabelFrame(self, text="QUICK GUIDE", padding=8); info.pack(fill="x", padx=16)
        ttk.Label(info, justify="left", text="Check data → Start server → Add jobs → Start worker.\nData folder: %s\nEach worker uses its own local client/database; server shares only IDs, source, logs, evidence." % DATA_ROOT).pack(anchor="w")
        box = ttk.LabelFrame(self, text="LIVE FEED", padding=6); box.pack(fill="both", expand=True, padx=16, pady=8)
        self.log = scrolledtext.ScrolledText(box, state="disabled", bg="#070b16", fg="#7dfff1", insertbackground="#7dfff1", relief="flat", font=("Cascadia Mono", 8), height=12)
        self.log.pack(fill="both", expand=True)

    def write(self, text):
        self.log.configure(state="normal"); self.log.insert("end", text + "\n"); self.log.see("end"); self.log.configure(state="disabled")

    def start(self):
        if self.proc and self.proc.poll() is None: return
        try:
            args = [*self.launcher(), str(SERVICE / "coordinator.py"), "--db", str(ROOT / "coordinator.db"), "--project", PROJECT]
            if TOKEN: args += ["--token", TOKEN]
            self.proc = subprocess.Popen(args,
                                         cwd=ROOT, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
            threading.Thread(target=self.read, daemon=True).start(); self.status.set("Coordinator running on http://127.0.0.1:8765")
        except Exception as error:
            messagebox.showerror("Coordinator", str(error))

    def setup(self):
        try:
            sys.path.insert(0, str(ROOT / "scripts" / "re"))
            import bootstrap
            bootstrap.install()
            self.write("setup complete; restart app if Python/MSVC was added")
        except Exception as error:
            messagebox.showerror("Setup", str(error))

    def check_data(self):
        db = DATA_ROOT / "rbx2008m.db"
        client = DATA_ROOT / "bin" / "RobloxApp_client.exe"
        self.write("DATA ROOT: %s" % DATA_ROOT)
        self.write("2008 DB: %s" % ("READY" if db.exists() else "MISSING  (run summarize.py ingest)"))
        self.write("2008 client: %s" % ("READY" if client.exists() else "MISSING  (place authorized EXE in data\\bin)"))

    def launcher(self):
        if not getattr(sys, "frozen", False): return [sys.executable]
        import shutil
        for name in ("py", "python"):
            if shutil.which(name): return [name]
        raise RuntimeError("Python missing; run first-run setup")

    def start_worker(self):
        if self.worker_proc and self.worker_proc.poll() is None: return
        try:
            self.worker_proc = subprocess.Popen([*self.launcher(), str(SERVICE / "worker.py"), "--root", str(ROOT)],
                                                cwd=ROOT, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
            threading.Thread(target=self.read_worker, daemon=True).start()
            self.status.set("Worker running")
        except Exception as error: messagebox.showerror("Worker", str(error))

    def read_worker(self):
        for line in self.worker_proc.stdout: self.events.put("worker: " + line.rstrip())

    def seed(self):
        db = DATA_ROOT / "rbx2008m.db"
        binary = DATA_ROOT / "bin" / "RobloxApp_client.exe"
        if not db.exists() or not binary.exists():
            self.write("Seed needs local Ghidra DB + client binary")
            return
        digest = hashlib.sha256()
        with binary.open("rb") as stream:
            for chunk in iter(lambda: stream.read(1024 * 1024), b""): digest.update(chunk)
        import sqlite3
        with sqlite3.connect(db) as conn:
            rows = conn.execute("SELECT program,addr FROM scope WHERE in_scope=1 ORDER BY indeg DESC LIMIT 200").fetchall()
        payload = {"jobs": [{"binary_hash": digest.hexdigest(), "program": p, "address": a} for p, a in rows]}
        request = urllib.request.Request("http://127.0.0.1:8765/v1/jobs/seed", json.dumps(payload).encode(),
                                         {"Content-Type": "application/json", "X-Worker-Token": TOKEN,
                                          "X-RoConstruct-Project": PROJECT})
        try:
            with urllib.request.urlopen(request, timeout=5) as response: self.write(response.read().decode())
        except Exception as error: self.write("seed unavailable: %s" % error)

    def read(self):
        for line in self.proc.stdout: self.events.put(line.rstrip())

    def stop(self):
        if self.proc and self.proc.poll() is None: self.proc.terminate()
        if self.worker_proc and self.worker_proc.poll() is None: self.worker_proc.terminate()
        self.status.set("Coordinator stopped")

    def refresh(self):
        try:
            request = urllib.request.Request("http://127.0.0.1:8765/v1/status", headers={
                "X-Worker-Token": TOKEN, "X-RoConstruct-Project": PROJECT})
            with urllib.request.urlopen(request, timeout=2) as response:
                data = json.load(response)
                workers = data.get("workers", [])
                jobs = data.get("jobs", {})
                self.status.set("ONLINE  // workers %s  // queue %s  // done %s" %
                                (data.get("workers_online", 0), jobs.get("queued", 0), jobs.get("done", 0)))
                self.write(json.dumps(data, indent=2))
        except Exception as error:
            self.write("status unavailable: %s" % error)

    def poll(self):
        try:
            while True: self.write(self.events.get_nowait())
        except queue.Empty: pass
        self.after(150, self.poll)


if __name__ == "__main__":
    App().mainloop()
