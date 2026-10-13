@echo off
setlocal
cd /d "%~dp0"
title RoConstruct
rem The one Windows launcher. No arguments: menu. First run: installs itself.
set PY=py -3.12
%PY% -c "import sys" >nul 2>nul || set PY=py
rem `roc update` only syncs Git source. Do not trigger the full installer first.
if /I "%~1"=="update" goto run
%PY% -c "import pefile, capstone" >nul 2>nul || (
  echo RoConstruct is not set up yet. Running first-time setup...
  call install.cmd
  %PY% -c "import pefile, capstone" >nul 2>nul || exit /b 1
)
:run
%PY% roc.py %*
if "%~1"=="" pause
