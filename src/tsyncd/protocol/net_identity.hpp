/*
 * @Author: chenhao.gao chenhao.gao@ecarxgroup.com
 * @Date: 2025-12-24 10:01:11
 * @LastEditors: chenhao.gao chenhao.gao@ecarxgroup.com
 * @LastEditTime: 2026-01-26 14:28:04
 */
#pragma once

#include "tsync_types.hpp"

namespace tsyncd
{
    // Build IEEE 1588 ClockIdentity from interface address.
    int generate_clock_identity(ClockIdentity &ci, const char *iface_name);
}
