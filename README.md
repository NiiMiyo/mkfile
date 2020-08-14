# mkfile

mkfile is a simple C++ program to create an empty file using Command-line Interface (CLI).

Based on the mkdir command to create folders, mkfile creates a single empty file in the specified folder.

## Instalation

Download mkfile at the [releases page](https://www.github.com/NiiMiyo/mkfile/releases/latest), extract it and add it to PATH.

## Usage

mkfile can be used to create a file:

-   in the folder you are:

```bash
$ mkfile file.ext
```

-   in a subfolder:

```bash
$ mkfile subfolder/file.ext
```

-   in a superfolder:

```bash
$ mkfile ../file.ext
```

-   in a non-related path:

```bash
$ mkfile C:/path/file.ext
```

If the file already exists, it **won't** be deleted or modified.

If there is no `path` argument, nothing happens.

## License

[MIT](https://douglas-sebastian.mit-license.org/)
