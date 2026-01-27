/*
 * @Author: chenhao.gao chenhao.gao@ecarxgroup.com
 * @Date: 2025-12-24 10:01:11
 * @LastEditors: chenhao.gao chenhao.gao@ecarxgroup.com
 * @LastEditTime: 2025-12-24 10:08:15
 */
#pragma once
#include <time.h>

namespace tsyncd
{
    int setup_raw_socket(int &sockFd, const char *interface_name);
    int raw_sendMsg(int sockFd, void *send_buffer, int bufLen, ::timespec *hwts);
    int raw_recvMsg(int sockFd, void *recv_buffer, ::timespec *hwts, int flag); // flag:0 blocking,1 errqueue
}
