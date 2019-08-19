# sparse
a simple tool to pipe standard input into a sparse file

Example:

```
sudo dd if=/dev/sda1 | sparse sda1.img
```

The file sda1.img will be created as sparse file (filesystem support required)
