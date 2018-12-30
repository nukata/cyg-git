# Cyg-Git

This provides a `Git` for Windows virtually.
You only need Cygwin and its packages.

I tried the Go plugin for VSCode on Windows 10 and found that it required
Git for Windows implicitly.
However, it was redundant since I had already installed Cygwin and its `git`
package.
So I wrote this proxy and wrapper.

## How to install

- You need the following Cygwin packages: `git`, `bash` and `zsh`.

- If you have installed Cygwin somewhere other than `C:\cygwin64`,
  modify the path name `C:\cygwin64\bin\bash` in `git.bat` of Cyg-Git
  accordingly.

- Put `git.bat` and `git-wrapper` of Cyg-Git anywhere on the
  Windows' path.
  I put them `C:\Users\<my name>\go\bin`.
  Make sure they have been "`chmod u+x`"-ed.

Now you can use `git` on Windows.

```
C:\>git --version
git version 2.17.0

C:\>
```
