# Cyg-Git

This provides a `git` for Windows virtually.
You need Cygwin only.

I just tried the Go plugin of VSCode and found that it requies
Git for Windows implicitly.
However, it is redundant since I have already installed Cygwin.
So I wrote this.

# How to install

- Provide `bash`, `cygpath`, `git` and `zsh` of Cygwin.

- Put `git.bat` and `git-wrapper` of Cyg-Git anywhere on the Windows' path.
  I put them `C:\Users\<my name>\go\bin`.

- If you have installed Cygwin somewhere other than `C:\cygwin64`,
  modify the path name `C:\cygwin64\bin\bash` in `git.bat` accordingly.

- Make sure `git.bat` and `git-wrapper` have "`chmod u+x`"-ed.


Now you can use `git` in Windows natively.

```
C:\>git --version
git version 2.17.0

C:\>
```
