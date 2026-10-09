# RoConstruct packages

Three zips, one code base. A helper needs the first one; the other two are opt-in.

| Package | Who | What it installs | What it runs |
| --- | --- | --- | --- |
| **RoConstruct Worker** | helpers | Python 3.12 check, `pefile` + `capstone`, the exact MSVC compiler bundles, `roconstruct://` registration | the cloud worker (`roc setup`, `roc launch`) |
| **RoConstruct Local AI** | helpers who want a local model | Ollama and, only if asked, Docker Desktop + the Rev.ng image | local-model workers, Rev.ng hints |
| **RoConstruct Server** | maintainers | the rest of `roc/` (`server.py`, `discord.py`, `progress.py`, `dataset.py`) | the group server and website publishing |

Build all three:

```
py -3.12 packaging/build.py
py -3.12 packaging/build.py worker      # or local-ai / server
```

Output lands in `dist/`. Each build stages the package in `dist/stage-<name>/`,
imports every module it contains, and only then writes the zip. If `roc.py`
references a module the package leaves out and it is not a maintainer module, the
build fails instead of shipping a broken download.

## Why the split

The default path used to install too much: an old MSVC toolchain *plus* Ollama,
Docker, local models and a link-registry entry, whether the helper wanted them or
not. Most helpers never run a local model, so all of that was dead weight on
machines that will never need a GPU.

Now:

- `install.cmd` installs packages and compilers, nothing else, and prints the size
  and time before it downloads.
- The website asks username, client and cloud consent, writes a signed config and
  starts the worker.
- `roc local-ai` is the only thing that installs Ollama, and `roc local-ai
  --docker` is the only thing that offers Docker. Both ask first.

## Keeping the maintainer modules out

`roc.py` imports every `roc.*` module *inside* the command that needs it, so a
missing module breaks one command instead of the whole program. Commands that
only make sense for a maintainer go through `need_module()`, which prints:

```
Publishing the website ships in RoConstruct Server (maintainer-only).
Ask a maintainer if you need it.
```

If you add a module that helpers need, add it to `WORKER_MODULES` in
`packaging/build.py`. The build will tell you if you forget.