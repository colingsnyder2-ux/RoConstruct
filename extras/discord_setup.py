"""One-time Discord server setup for RoConstruct.

Creates roles, categories, channels, pinned rules/guide, and a webhook for
GitHub pushes. Safe to re-run: anything that already exists (by name) is kept.

Run:  py extras\\discord_setup.py
The bot token is typed in hidden and never saved or printed.
"""
import getpass
import json
import sys
import time
import urllib.error
import urllib.request
from pathlib import Path

API = "https://discord.com/api/v10"
ROOT = Path(__file__).resolve().parent.parent
SITE = "https://colingsnyder2-ux.github.io/RoConstruct/"
REPO = "https://github.com/colingsnyder2-ux/RoConstruct"
SEND = 1 << 11  # SEND_MESSAGES

ROLES = [  # name, colour
    ("Maintainer", 0x2F6BFF),
    ("Contributor", 0x38C8FF),
    ("Worker", 0x3FB950),
    ("Hand-matcher", 0xF2C14E),
]

RULES = f"""**RoConstruct rules**
1. **Never post Roblox client exes, DLLs, game files or download links.** Everyone brings their own copy. Sharing them puts this server and the GitHub repo at risk of takedown.
2. No inline asm or faked matches. The server re-checks every submission with the real compiler.
3. Use the same username here as on the leaderboard.
4. Be helpful. Matching is hard; post diffs, not insults.
Progress: {SITE}"""

GUIDE = f"""**Getting started**
1. Download RoConstruct: {REPO}/archive/refs/heads/main.zip and unzip it.
2. Double-click `install.cmd`. It installs Python, downloads the old compilers and enables one-click links.
3. Put your own copy of a client in `clients\\<name>\\` (see `clients/clients.json` for exe names), then run `roc client verify`.
4. On the website, click **Start helping** on a client. Pick a username once and leave the window open overnight.
Heads up: workers use the GPU and CPU heavily. Close the window to stop.
Hand-matching instead? `roc next 2008-06`, `roc claim ...`, `roc check ...`, `roc submit ...`. Ask in #matching."""

LAYOUT = [  # category, [(channel, topic, read_only)]
    ("INFO", [
        ("rules", "Read first.", True),
        ("announcements", "Project news.", True),
        ("getting-started", "How to join in.", True),
    ]),
    ("PROJECT", [
        ("progress", "Site updates and commits, posted automatically.", True),
        ("leaderboard", "Bragging rights.", False),
        ("general", "Anything RoConstruct.", False),
    ]),
    ("WORK", [
        ("help-setup", "install.cmd, compilers, client exes.", False),
        ("matching", "Hand-matching: share asm diffs and tricks.", False),
        ("ai-workers", "GPUs, models, overnight runs.", False),
        ("tooling", "RoConstruct bugs and ideas.", False),
    ]),
]


class Discord:
    def __init__(self, token):
        self.token = token

    def call(self, method, path, body=None):
        while True:
            req = urllib.request.Request(API + path, method=method,
                                         data=json.dumps(body).encode() if body is not None else None,
                                         headers={"Authorization": "Bot " + self.token,
                                                  "Content-Type": "application/json",
                                                  "User-Agent": "DiscordBot (%s, 1.0)" % REPO})
            try:
                with urllib.request.urlopen(req, timeout=30) as r:
                    data = r.read()
                    return json.loads(data) if data else None
            except urllib.error.HTTPError as error:
                if error.code == 429:  # rate limited: wait as told, retry
                    time.sleep(json.loads(error.read()).get("retry_after", 1) + 0.2)
                    continue
                detail = error.read().decode(errors="replace")[:300]
                if error.code == 401:
                    sys.exit("Discord rejected the token (401). Reset it in the Developer Portal and try again.")
                if error.code == 403:
                    sys.exit("Missing permission (403) for %s %s. Re-invite the bot with Administrator." % (method, path))
                raise SystemExit("Discord error %d on %s %s: %s" % (error.code, method, path, detail))


def client_channels():
    try:
        reg = json.loads((ROOT / "clients" / "clients.json").read_text())
    except OSError:
        return []
    return [((e.get("built") or name)[:4], "Client %s (built %s)." % (name, e.get("built", "?")), False)
            for name, e in sorted(reg.items())]


def main():
    token = getpass.getpass("Bot token (hidden, not saved): ").strip()
    d = Discord(token)
    guilds = d.call("GET", "/users/@me/guilds")
    if not guilds:
        sys.exit("The bot is in no server yet. Open the invite link from the guide first.")
    guild = guilds[0]
    if len(guilds) > 1:
        for i, g in enumerate(guilds, 1):
            print("%d. %s" % (i, g["name"]))
        guild = guilds[int(input("Which server? ")) - 1]
    gid = guild["id"]
    print("Setting up '%s'..." % guild["name"])

    roles = {r["name"]: r for r in d.call("GET", "/guilds/%s/roles" % gid)}
    for name, colour in ROLES:
        if name not in roles:
            roles[name] = d.call("POST", "/guilds/%s/roles" % gid,
                                 {"name": name, "color": colour, "hoist": True, "mentionable": True})
            print("  role", name)
    maintainer = roles["Maintainer"]["id"]

    channels = d.call("GET", "/guilds/%s/channels" % gid)
    by_name = {(c["name"], c.get("parent_id")): c for c in channels}
    cats = {c["name"]: c for c in channels if c["type"] == 4}
    made = {}
    layout = LAYOUT + [("CLIENTS", client_channels())]
    for cat_name, chans in layout:
        cat = cats.get(cat_name) or d.call("POST", "/guilds/%s/channels" % gid, {"name": cat_name, "type": 4})
        for name, topic, read_only in chans:
            existing = by_name.get((name, cat["id"]))
            if existing:
                made[name] = existing
                continue
            overwrites = [{"id": gid, "type": 0, "deny": str(SEND)},          # @everyone: read only
                          {"id": maintainer, "type": 0, "allow": str(SEND)}] if read_only else []
            made[name] = d.call("POST", "/guilds/%s/channels" % gid,
                                {"name": name, "type": 0, "parent_id": cat["id"], "topic": topic,
                                 "permission_overwrites": overwrites})
            print("  #%s" % name)
            if name == "rules":
                msg = d.call("POST", "/channels/%s/messages" % made[name]["id"], {"content": RULES})
                d.call("PUT", "/channels/%s/pins/%s" % (made[name]["id"], msg["id"]))
            if name == "getting-started":
                msg = d.call("POST", "/channels/%s/messages" % made[name]["id"], {"content": GUIDE})
                d.call("PUT", "/channels/%s/pins/%s" % (made[name]["id"], msg["id"]))

    progress = made["progress"]["id"]
    hooks = d.call("GET", "/channels/%s/webhooks" % progress) or []
    hook = next((h for h in hooks if h["name"] == "GitHub"), None) or \
        d.call("POST", "/channels/%s/webhooks" % progress, {"name": "GitHub"})
    print("\nDone.")
    print("Last step, on GitHub: repo Settings -> Webhooks -> Add webhook")
    print("  Payload URL:  https://discord.com/api/webhooks/%s/%s/github" % (hook["id"], hook["token"]))
    print("  Content type: application/json    Events: Just the push event")
    print("Keep that URL private: anyone with it can post in #progress.")


if __name__ == "__main__":
    main()
