#include "no-fortify.h"
#include "statfs.h"
#include "iorewrite.h"
#include <cstring>

using namespace shim;

int shim::statfs(const char *path, struct statfs *buf) {
    struct ::statfs tmp = {};
    int ret = ::statfs(iorewrite0(path).data(), &tmp);
    if (ret != 0) ret = ::statfs("/", &tmp);
    buf->f_type = tmp.f_type;
    buf->f_bsize = tmp.f_bsize;
    buf->f_blocks = tmp.f_blocks;
    buf->f_bfree = tmp.f_bfree;
    buf->f_bavail = tmp.f_bavail;
    buf->f_files = tmp.f_files;
    buf->f_ffree = tmp.f_ffree;
    memcpy(&buf->f_fsid, &tmp.f_fsid, sizeof(buf->f_fsid));
    buf->f_namelen = tmp.f_namelen;
    buf->f_frsize = tmp.f_frsize;
    buf->f_flags = tmp.f_flags;

    return ret;
}

void shim::add_statfs_shimmed_symbols(std::vector<shimmed_symbol> &list) {
    list.insert(list.end(), {
        {"statfs", statfs},
        {"statfs64", statfs}
    });
}
