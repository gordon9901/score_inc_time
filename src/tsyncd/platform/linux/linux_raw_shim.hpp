/*
 * @Author: chenhao.gao chenhao.gao@ecarxgroup.com
 * @Date: 2025-12-24 10:01:11
 * @LastEditors: chenhao.gao chenhao.gao@ecarxgroup.com
 * @LastEditTime: 2026-01-27 11:35:45
 */
#pragma once
#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

int linux_raw_open(const char *ifname);
int linux_raw_recv(int fd, void *buf, int buf_len, struct timespec *hwts, int flag);
int linux_raw_send(int fd, void *buf, int len, struct timespec *hwts);

#ifdef __cplusplus
}
#endif
