/*
 * @Author: chenhao.gao chenhao.gao@ecarxgroup.com
 * @Date: 2025-12-24 10:01:11
 * @LastEditors: chenhao.gao chenhao.gao@ecarxgroup.com
 * @LastEditTime: 2026-01-26 14:26:59
 */
#pragma once

#include "time_sync_engine.hpp"
#include <string>

namespace tsyncd
{
    bool LoadEngineOptionsFromFile(const std::string &path, EngineOptions &opt);
} // namespace tsyncd
