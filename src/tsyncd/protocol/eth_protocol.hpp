/*
 * @Author: chenhao.gao chenhao.gao@ecarxgroup.com
 * @Date: 2025-12-24 10:01:11
 * @LastEditors: chenhao.gao chenhao.gao@ecarxgroup.com
 * @LastEditTime: 2026-01-26 14:27:21
 */
#pragma once
#include <cstdint>
#include <netinet/in.h>
#include "tsync_types.hpp"

#ifdef _QNX710_
struct ethhdr {
    unsigned char h_dest[MAC_ADDR_LEN];
    unsigned char h_source[MAC_ADDR_LEN];
    uint16_t h_proto;
};
#else
#include <linux/if_ether.h>
#endif

namespace tsyncd
{
    int add_ethernet_header(unsigned char *buffer, unsigned int &buffer_len);
    void parse_ethernet_header(const unsigned char *buffer, ethhdr &eth_header, int &offset);
}
