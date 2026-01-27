/*
 * @Author: chenhao.gao chenhao.gao@ecarxgroup.com
 * @Date: 2026-01-20 15:29:32
 * @LastEditors: chenhao.gao chenhao.gao@ecarxgroup.com
 * @LastEditTime: 2026-01-26 14:31:43
 */
#pragma once
#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

int qnx_raw_open(const char *ifname);
int qnx_raw_recv(int fd, void *buf, int buf_len, struct timespec *hwts, int nonblock);
int qnx_raw_send(int fd, const void *buf, int len, struct timespec *hwts);

int qnx_phc_open(const char *phc_dev);
int qnx_phc_adjtime_step(int phc_fd, long long offset_ns);
int qnx_phc_adjfreq_ppb(int phc_fd, long long freq_ppb);

#ifdef __cplusplus
}
#endif
