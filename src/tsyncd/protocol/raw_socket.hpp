/********************************************************************************
* Copyright (c) 2025 Contributors to the Eclipse Foundation
*
* See the NOTICE file(s) distributed with this work for additional
* information regarding copyright ownership.
*
* This program and the accompanying materials are made available under the
* terms of the Apache License Version 2.0 which is available at
* https://www.apache.org/licenses/LICENSE-2.0
*
* SPDX-License-Identifier: Apache-2.0
********************************************************************************/
#pragma once
#include <time.h>

namespace tsyncd
{
    int setup_raw_socket(int &sockFd, const char *interface_name);
    int raw_sendMsg(int sockFd, void *send_buffer, int bufLen, ::timespec *hwts);
    int raw_recvMsg(int sockFd, void *recv_buffer, ::timespec *hwts, int flag); // flag:0 blocking,1 errqueue
}
