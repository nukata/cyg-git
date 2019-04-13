# Cyg-Git

This provides a `Git` for Windows virtually.
You only need Cygwin and its packages.

I had once tried the Go plugin for VSCode on Windows 10 and found that it
required Git for Windows implicitly.
However, it was redundant since I had already installed Cygwin and its `git`
package.
So I wrote this proxy and wrapper.

## Experimental compatibiliy with VSCode 

At first I had implemented the proxy for `git` as a batch file `git.bat`.
It had worked successfully with `go` and its plugin for VSCode.
However, VSCode itself did not seem to recognize any batch file as `git`.
Now I tried to make VSCode also recognize the proxy by implementing it with C. 
It is just an experiment currently but it seems to work fairly well.


## How to install

- You need the following Cygwin packages: `git`, `bash`, `zsh` and
  `mingw64-x86_64-gcc-core`.

- If you have installed Cygwin somewhere other than `C:/cygwin64`,
  modify the path name `C:/cygwin64/bin/bash` in `git.c` of Cyg-Git
  accordingly.

- compile the `git.c` with `x86_64-w64-ming32-gcc -o git`.
  Make sure the resulting `git.exe` is independent from `cygwin1.dll`.

```
$ x86_64-w64-ming32-gcc -o git git.c
$ ls -l git.exe
-rwxr-xr-x 1 suzuki None 400412 Dec 30 18:44 git.exe
$ ldd ./git.exe
        ntdll.dll => /cygdrive/c/WINDOWS/SYSTEM32/ntdll.dll (0x7ffcacc40000)
        KERNEL32.DLL => /cygdrive/c/WINDOWS/System32/KERNEL32.DLL (0x7ffcac2f0000)
        KERNELBASE.dll => /cygdrive/c/WINDOWS/System32/KERNELBASE.dll (0x7ffca8e10000)
        msvcrt.dll => /cygdrive/c/WINDOWS/System32/msvcrt.dll (0x7ffcabc00000)
$ 
```

- Put the resulting `git.exe` and `git-wrapper` of Cyg-Git anywhere on the
  Windows' path.
  I put them in `C:\Users\<my name>\go\bin`.
  Make sure they have been "`chmod u+x`"-ed.

Now you can use `git` on Windows.

```
C:\>git --version
git version 2.17.0

C:\>
```


## Appendix: Proxy for GCC

*Go*'s [`cgo`](https://github.com/golang/go/wiki/cgo) on Windows needs mingw-w64 gcc as `gcc`.
Put the following `gcc.bat` in `C:\Users\<your name>\go\bin`.

```DOS
@echo off
PATH C:\cygwin64\bin;%PATH%
C:\cygwin64\bin\x86_64-w64-mingw32-gcc %*
```

Then `go build` will use `C:\cygwin64\bin\x86_64-w64-mingw32-gcc` as `gcc`.
I have successfully built `fyne_demo` in [fyne-io/fyne](https://github.com/fyne-io/fyne) with it.

```
C:\Users\suzuki\go\src\fyne.io\fyne\cmd\fyne_demo>go build -ldflags -H=windowsgui

C:\Users\suzuki\go\src\fyne.io\fyne\cmd\fyne_demo>fyne_demo.exe
```
