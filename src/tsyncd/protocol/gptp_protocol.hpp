/*
 * @Author: chenhao.gao chenhao.gao@ecarxgroup.com
 * @Date: 2025-12-24 10:01:11
 * @LastEditors: chenhao.gao chenhao.gao@ecarxgroup.com
 * @LastEditTime: 2026-01-26 14:27:44
 */
#pragma once
#include "tsync_types.hpp"
#include <cstddef>
#include <cstdint>

namespace tsyncd
{
    bool parse_gptp_message(const unsigned char *buffer, std::size_t buffer_len, PTPMessage &msg);
}
