# mkfile

mkfile is a simple C++ program to create empty files using Command-line Interface (CLI).

Based on the mkdir command to create folders, mkfile creates empty files in specified folder(s).

## Instalation


## Usage

mkfile can be used to create:

-   a file in the folder you are:

```bash
$ mkfile file.ext
```

-   a file in a subfolder:

```bash
$ mkfile subfolder/file.ext
```

-   a file in a superfolder:

```bash
$ mkfile ../file.ext
```

-   a file in a non-related path:

```bash
$ mkfile C:/path/file.ext
```

-   multiple files the same way as the previous examples:

```bash
$ mkfile C:/path/file0.ext ./file1.ext ../file2.ext
```

If the file already exists, it **won't** be deleted or modified.

If there is no `path` argument, nothing happens.

## License

[MIT](https://douglas-sebastian.mit-license.org/)
