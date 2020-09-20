#include <sys/stat.h>

enum
{
    OWNER_OFFSET = 6,
    GROUP_OFFSET = 3
};

struct Task
{
    unsigned uid;
    int gid_count;
    unsigned *gids;
};

static int access_compare(int myMode, int reqMode) {
    if ((myMode ^ reqMode) != ((myMode ^ reqMode) & myMode)) {
        return 0;
    }
    return 1;
}

static int find_group (int s_gid, unsigned *gids, int gid_count) {
    for (int i = 0; i < gid_count; ++i) {
        if (gids[i] == s_gid) {
            return 1;
        }
    }
    return 0;
}

int myaccess (const struct stat *stb, const struct Task *task, int access) {
    if (!task->uid) {
        return 1;
    }
    if (task->uid == stb->st_uid) {
        return access_compare(stb->st_mode >> OWNER_OFFSET, access);
    }
    if (find_group(stb->st_gid, task->gids, task->gid_count)) {
        return access_compare(stb->st_mode >> GROUP_OFFSET, access);
    }
    return access_compare(stb->st_mode, access);
}
