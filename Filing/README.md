# Shreyas Tulsi 706157430


In this lab, I successfully implemented the following TODO

## Building

To build program, run make

## Running

Create Executable
./ext2-create 

Mounting:
mkdir mnt 
sudo mount -o loop cs111-base.img mnt

Examples:
dumpe2fs cs111-base.img
(dump file system info)

ls-ain

total 7
2 drwxr-xr-x 3     0 1024 Nov  9 00:58 .
942169 drwxrwxrwx 4 1000 1000 4096 Nov  9 00:58 ..
13 lrw-r--r-- 1 1000 1000   11 Nov  9 00:58 hello -> hello-world
12 -rw-r--r-- 1 1000 1000   12 Nov  9 00:58 hello-world
11 drwxr-xr-x 2     0 1024 Nov  9 00:58 lost+found


fsck.ext2 cs111-base.img
cs111@cs111_Downloads/Lab4 $ fsck.ext2 cs111-base.img
e2fsck 1.46.4 (18-Aug-2021)
cs111-base has gone 0 days without being checked, check forced.
Pass 1: Checking inodes, blocks, and sizes
Pass 2: Checking directory structure
Pass 3: Checking directory connectivity
Pass 4: Checking reference counts
Pass 5: Checking group summary information
cs111-base: 13/128 files (0.0% non-contiguous), 24/1024 blocks
cs111@cs111_Downloads/Lab4 $


## Cleaning up

sudo umount mnt
rmdir mnt
make clean
