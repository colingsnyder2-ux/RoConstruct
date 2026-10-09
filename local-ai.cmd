@echo off
setlocal
cd /d "%~dp0"
title RoConstruct local AI (optional)

rem This is the only thing that installs Ollama, and only because you ran it.
rem Cloud workers do not need any of it: no GPU, no Ollama, no Docker.

py -3.12 roc.py local-ai %*
if errorlevel 1 (
  echo.
  echo Not installed. You can still work:  py -3.12 roc.py launch
)
echo.
echo To add Rev.ng hints later (about 5 GB, needs Docker Desktop):
echo    py -3.12 roc.py local-ai --docker
pause