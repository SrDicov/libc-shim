#pragma once

#include <stdint.h>
#include <sys/cdefs.h>
#include <sys/types.h>
#include <libc_shim.h>
#include <sys/statfs.h>

namespace shim {
    // Bionic statfs layout. On x86_64 LP64 this is identical in size/order to the
    // host (musl/glibc) struct statfs, so we copy fields explicitly to be safe.
    struct statfs {
        unsigned long f_type;
        unsigned long f_bsize;
        unsigned long f_blocks;
        unsigned long f_bfree;
        unsigned long f_bavail;
        unsigned long f_files;
        unsigned long f_ffree;
        unsigned long f_fsid;
        unsigned long f_namelen;
        unsigned long f_frsize;
        unsigned long f_flags;
        unsigned long f_spare[4];
    };

    int statfs(const char *path, struct statfs *buf);
    int statfs64(const char *path, struct statfs *buf);

    void add_statfs_shimmed_symbols(std::vector<shimmed_symbol> &list);
}
